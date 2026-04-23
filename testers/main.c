#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

size_t  ft_strlen(char *str);
char    *ft_strcpy(char *src);
int     ft_strcmp(char *s1, char *s2);
int     ft_write(int fd, char *buf, int size);
int     ft_read(int fd, char *buf, int size);
char    *ft_strdup(char *src);
int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp) (), void (*free_fct)(void *)); 

void	test_ft_strlen(char *str)
{
	printf("ft_strlen =	%d\n", ft_strlen(str));
	printf("strlen =	%d\n", strlen(str));
	exit(0);
}

void	test_ft_strcpy(char *str)
{
	printf("ft_strcpy =	%s\n", ft_strcpy(str));
	printf("strcpy =	%s\n", strcpy(str));
	exit (0);
}

void	test_ft_strcmp(char *s1, char *s2)
{
	printf("ft_strcmp =	%d\n", ft_strcmp(s1, s2));
	printf("strcmp =	%d\n", strcmp(s1, s2));
	exit (0);
}

void	test_ft_write(char *file, char *msg, char *size)
{
	if (!file)
		int fd = 1;
	else
		int		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 1)
		exit (1);
	int		len = ft_atoi_base(size, "0123456789");
	printf("ft_write =	%d\n", ft_write(fd, msg, size));
	printf("write =	%d\n", write(fd, msg, size));
	close(fd);
	exit(0);
}

void	test_ft_read(char *file, char *size)
{
	if (!file)
		exit (1);
	int	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (1);
	char	buf[size + 1]
	int		len = ft_atoi_base(size, "0123456789");
	printf("ft_read =	%d\n", ft_read(fd, buf, len));
	buf[len] = '\0';
	printf("fd_read buffer =	%s\n", buf)
	printf("read =	%d\n", read(fd, buf, len));
	buf[len] = '\0';
	printf("read buffer =	%s\n", buf);
	close(fd);
	exit(0);
}

void	test_ft_strdup(char *str)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup(str);
	s2 = strdup(str);
	printf("ft_strdup =	%s\n", s1);
	printf("strdup =	%s\n", s2);
	exit(0);
}

void	test_ft_atoi_base(char *str, char *base)
{
	printf("%d\n", ft_atoi_base(str, base));
	exit(0);
}

int		ft_strstr(char *s1, char *s2, int func)
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

	if (i < 7 || i > 17)
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
	int	case;
	i = 0;
	while (i < 11)
	{
		case = ft_strstr(str, fn_names[i], i + 1);
		if (case != 0)
			return (case);
		i++;
	}
	return (case);
}

int 	main(int argc, char **argv)
{
    if (argc != 3)
        return (1);
	int	function = check_function(argv[1]);
	switch (function)
	{
		case 1:
			test_ft_strlen(argv[2]);
		case 2:
			test_ft_strcpy(argv[2]);
		case 3:
			test_ft_strcmp(argv[2], argv[3]);
		case 4:
			test_ft_write(argv[2], argv[3], argv[4]);
		case 5:
			test_ft_read(argv[2], argv[3]);
		case 6:
			test_ft_strdup(argv[2]);
		case 7:
			test_ft_atoi_base(argv[2], argv[3]);
		case 8:
			test_ft_list_push_front(argv[2]);
		case 9:
			test_ft_list_size(argv[2]);
		case 10:
			test_ft_list_sort();
		case 11:
			test_ft_list_remove_if(argv[2]);
		default:
			printf("Wrong function name\n");
	}
    return (0);
}
