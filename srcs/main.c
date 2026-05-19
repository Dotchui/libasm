#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t  ft_strlen(char *str);
char    *ft_strcpy(char *dest, char *src);
int     ft_strcmp(char *s1, char *s2);
ssize_t ft_write(int fd, char *buf, int size);
ssize_t ft_read(int fd, char *buf, int size);
char    *ft_strdup(char *src);
int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp) (), void (*free_fct)(void *));

int		in_func = 0;

void	test_ft_strlen(char *str)
{
	in_func = 1;
	printf("ft_strlen =	%zu\n", ft_strlen(str));
	printf("strlen =	%zu\n", strlen(str));
	exit(0);
}

void	test_ft_strcpy(char *str)
{
	in_func = 1;
	char	buf[100];
	printf("ft_strcpy =	%s\n", ft_strcpy(buf, str));
	printf("strcpy =	%s\n", strcpy(buf, str));
	exit (0);
}

// SUS STRCMP BIZARRE, A RETESTER SOUS LINUX
void	test_ft_strcmp(char *s1, char *s2)
{
	in_func = 1;
	printf("ft_strcmp =	%d\n", ft_strcmp(s1, s2));
	printf("strcmp =	%d\n", strcmp(s1, s2));
	exit (0);
}

void	test_ft_write(char *file, char *msg, char *size)
{
	in_func = 1;
	int	fd;
	if (!file || !file[0])
		fd = 1;
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 1)
		exit (1);
	int		len = ft_atoi_base(size, "0123456789");
	printf("ft_write =	%zd\n", ft_write(fd, msg, len));
	printf("write =	%zd\n", write(fd, msg, len));
	close(fd);
	exit(0);
}

void	test_ft_read(char *file, char *size)
{
	in_func = 1;
	if (!file)
		exit (1);
	int	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (1);
	int		len = ft_atoi_base(size, "0123456789");
	char	buf[len + 1];
	ssize_t	bytes_read = ft_read(fd, buf, len);
	printf("ft_read =  %zd\n", bytes_read);
	buf[bytes_read] = '\0';
	printf("fd_read buffer =	%s\n\n\n", buf);
	close(fd);

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (1);
	bytes_read = read(fd, buf, len);
	printf("read =	%zd\n", bytes_read);
	buf[bytes_read] = '\0';
	printf("read buffer =	%s\n", buf);
	close(fd);
	exit(0);
}

void	test_ft_strdup(char *str)
{
	in_func = 1;
	char	*s1;
	char	*s2;

	s1 = ft_strdup(str);
	s2 = strdup(str);
	printf("ft_strdup =	%s\n", s1);
	printf("strdup =	%s\n", s2);
	free(s1);
	free(s2);
	exit(0);
}

void	test_ft_atoi_base(char *str, char *base)
{
	in_func = 1;
	printf("%d\n", ft_atoi_base(str, base));
	exit(0);
}

void	fill_random_list(t_list **begin_list, int sort)
{
	*begin_list = NULL;

	int	len = (rand() % 10) + 1;
	len = 2;
	printf("List length = %d\n", len);
	int	type = rand () % 2;
	if (sort == 1)
		type = 1;
	if (type == 0)
		printf("List type = int\n");
	else
		printf("List type = char\n\n");
	while (len > 0)
	{
		if (type == 0)
		{
			int *n = malloc(sizeof(int));
			if (!n)
				return ;
			*n = rand() % 1000;
			ft_list_push_front(begin_list, n);
		}
		else
		{
			char	*c = malloc(sizeof(char));
			if (!c)
				return ;
			*c = 'A' + (rand() % 26);
			ft_list_push_front(begin_list, c);
		}
		len--;
	}
}

void	test_ft_list_push_front()
{
	in_func = 1;
	t_list	*begin_list;
	fill_random_list(&begin_list, 1);
	for(t_list *cur = begin_list; cur; cur = cur->next)
		printf("%c ", *(char *)cur->data);
	printf("\n");
	char	*c = malloc(sizeof(char));
	if (!c)
		return ;
	*c = '?';
	ft_list_push_front(&begin_list, c);
	for(t_list *cur = begin_list; cur; cur = cur->next)
		printf("%c ", *(char *)cur->data);
	printf("\n");
	while (begin_list)
	{
		t_list	*next = begin_list->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}

void	test_ft_list_size()
{
	in_func = 1;
	t_list	*begin_list;
	fill_random_list(&begin_list, 0);
	printf("%d\n", ft_list_size(begin_list));
	while (begin_list)
	{
		t_list	*next = begin_list->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}

int		ft_charcmp(void *c1, void *c2)
{	
	if (!c1 || !c2)
		return (0);
	return (*(unsigned char *)c1 - *(unsigned char *)c2);
}

void	test_ft_list_sort()
{
	in_func = 1;
	t_list	*begin_list;
	fill_random_list(&begin_list, 1);
	for(t_list *cur = begin_list; cur; cur = cur->next)
		printf("%c ", *(char *)cur->data);
	printf("\n\n");

	ft_list_sort(&begin_list, ft_charcmp);

	for(t_list *cur = begin_list; cur; cur = cur->next)
		printf("%c ", *(char *)cur->data);
	printf("\n");
	while (begin_list)
	{
		t_list	*next = begin_list->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}

void	free_data(void *node)
{
	free (node);
}

void	test_ft_list_remove_if(char c)
{
	in_func = 1;
	t_list	*begin_list;
	fill_random_list(&begin_list, 1);
	for(t_list *cur = begin_list; cur; cur = cur->next)
		printf("%c ", *(char *)cur->data);
	printf("\n\n");
	ft_list_remove_if(&begin_list, &c, ft_charcmp, free_data);
	for(t_list *cur = begin_list; cur; cur = cur->next)
		printf("%c ", *(char *)cur->data);
	while (begin_list)
	{
		t_list	*next = begin_list->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}

int		ft_strstr(char *s1, const char *s2, int func)
{
	int	i;
	int	j;

	i = 0;

	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i] && s2[j] && s1[i] == s2[j])
			{
				i++;
				j++;
			}
			if (!s2[j])
				return (func);
		}
		i++;
	}
	return (0);
}

int		check_function(char *str)
{
	if (!str)
		return (0);
	int	i = ft_strlen(str);

	if (i < 7 || i > 18)
		return (0);
	static const char *fn_names[] =
	{
		"ft_strlen",
		"ft_strcpy",
		"ft_strcmp",
		"ft_write",
		"ft_read",
		"ft_strdup",
		"ft_atoi_base",
		"ft_list_push_front",
		"ft_list_size",
		"ft_list_sort",
		"ft_list_remove_if",
	};
	int	func;
	i = 0;
	while (i < 11)
	{
		func = ft_strstr(str, fn_names[i], i + 1);
		if (func != 0)
			return (func);
		i++;
	}
	return (func);
}

int 	main(int argc, char **argv)
{
    if (argc != 2 && argc != 3 && argc != 4 && argc != 5)
	{
		printf("Usage: ./tester function [arg1] [arg2] [arg3]\n");
		return (1);
	}

	srand(time(NULL));
	int	function = check_function(argv[1]);
	switch (function)
	{
		case 1:
			if (argc != 3)
				break ;
			test_ft_strlen(argv[2]);
			break ;
		case 2:
			if (argc != 3)
				break ;
			test_ft_strcpy(argv[2]);
			break ;
		case 3:
			if (argc != 4)
				break ;
			test_ft_strcmp(argv[2], argv[3]);
			break ;
		case 4:
			if (argc != 5)
				break ;
			test_ft_write(argv[2], argv[3], argv[4]);
			break ;
		case 5:
			if (argc != 4)
				break ;
			test_ft_read(argv[2], argv[3]);
			break ;
		case 6:
			if (argc != 3)
				break ;
			test_ft_strdup(argv[2]);
			break ;
		case 7:
			if (argc != 4)
				break ;
			test_ft_atoi_base(argv[2], argv[3]);
			break ;
		case 8:
			if (argc != 2)
				break ;
			test_ft_list_push_front();
			break ;
		case 9:
			if (argc != 2)
				break ;
			test_ft_list_size();
			break ;
		case 10:
			if (argc != 2)
				break ;
			test_ft_list_sort();
			break ;
		case 11:
			if (argc != 3)
				break ;
			test_ft_list_remove_if(argv[2][0]);
			break ;
		default:
			printf("Wrong function name\n");
	}
	if (in_func == 0)
	{
		printf("Wrong number of arguments for function %s\n", argv[1]);
		return (1);
	}
    return (0);
}
