NAME = libasm.a

SRCDIR = srcs
OBJDIR = objs

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_B = ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s

OBJS = $(SRCS:%.s=$(OBJDIR)/%.o)
OBJS_B = $(SRCS_B:%.s=$(OBJDIR)/%.o)

NASM = nasm
NASM_FLAGS = -f elf64 -Wall

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wl,-z,noexecstack

TESTER = tester
TESTER_BONUS = tester_bonus

all: $(NAME) $(TESTER)

bonus_lib: $(OBJS) $(OBJS_B)
	ar rcs $(NAME) $(OBJS) $(OBJS_B)

bonus: bonus_lib $(TESTER_BONUS)

$(TESTER): main.c $(NAME)
	$(CC) $(CFLAGS) -o $(TESTER) main.c $(NAME)

$(TESTER_BONUS): main_bonus.c
	$(CC) $(CFLAGS) -o $(TESTER_BONUS) main_bonus.c $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.s | $(OBJDIR)
	$(NASM) $(NASM_FLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR) tester tester_bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus