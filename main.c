#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

size_t  ft_strlen(char *str);
char    *ft_strcpy(char *dest, char *src);
int     ft_strcmp(char *s1, char *s2);
ssize_t ft_write(int fd, char *buf, int size);
ssize_t ft_read(int fd, char *buf, int size);
char    *ft_strdup(char *src);

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
	int		len = atoi(size);
	printf("\nft_write =	%zd\n\n", ft_write(fd, msg, len));
	printf("\nwrite =	%zd\n", write(fd, msg, len));
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
	int		len = atoi(size);
	char	buf[len + 1];
	ssize_t	bytes_read = ft_read(fd, buf, len);
	printf("ft_read =  %zd\n", bytes_read);
	buf[bytes_read] = '\0';
	printf("fd_read buffer =	%s\n\n", buf);
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
	};
	int	func;
	i = 0;
	while (i < 6)
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
