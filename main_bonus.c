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

int     ft_atoi_base(char *str, char *base);
void    ft_list_push_front(t_list **begin_list, void *data);
int     ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp) (), void (*free_fct)(void *));

int		in_func = 0;

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
	printf("\n");
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
	int	i = strlen(str);

	if (i < 7 || i > 18)
		return (0);
	static const char *fn_names[] =
	{
		"ft_atoi_base",
		"ft_list_push_front",
		"ft_list_size",
		"ft_list_sort",
		"ft_list_remove_if",
	};
	int	func;
	i = 0;
	while (i < 5)
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
    if (argc != 2 && argc != 3 && argc != 4)
	{
		printf("Usage: ./tester function [arg1] [arg2]\n");
		return (1);
	}

	srand(time(NULL));
	int	function = check_function(argv[1]);
	switch (function)
	{
		case 1:
			if (argc != 4)
				break ;
			test_ft_atoi_base(argv[2], argv[3]);
			break ;
		case 2:
			if (argc != 2)
				break ;
			test_ft_list_push_front();
			break ;
		case 3:
			if (argc != 2)
				break ;
			test_ft_list_size();
			break ;
		case 4:
			if (argc != 2)
				break ;
			test_ft_list_sort();
			break ;
		case 5:
			if (argc != 3)
				break ;
			test_ft_list_remove_if(argv[2][0]);
			break ;
		default:
			printf("Wrong function name\n");
			return (1);
	}
	if (in_func == 0)
	{
		printf("Wrong number of arguments for function %s\n", argv[1]);
		return (1);
	}
    return (0);
}
