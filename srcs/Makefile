NAME = exec

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, main.o $(SRCS:.s=.o))

NASM = nasm
NASM_FLAGS = -f elf64 -Wall
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	gcc -no-pie -Wl,-z,noexecstack -o $(NAME) $(OBJS)

$(OBJDIR)/main.o: main.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) main.c -o $@

$(OBJDIR)/%.o: %.s | $(OBJDIR)
	$(NASM) $(NASM_FLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re