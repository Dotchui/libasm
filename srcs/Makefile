NAME = exec

SRCS = main.c ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
S_BONUS = ft_atoi_base.s ft_list_push_front.s ft_list_size.s ft_list_sort.s ft_list_remove_if.s
OBJS = $(SRCS:.s=.o)
O_BONUS = $(S_BONUS:.s=o)
BINS = $(SRCS:%.s=%)
B_BONUS = $(S_BONUS:%.s=%)

NASM = nasm
NASM_FLAGS = -f elf64
CC = gcc

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	gcc -no-pie -o $(NAME) $(BINS)

$(BONUS): $(OBJS) $(O_BONUS)
	gcc -no-pie -o $(NAME) $(BINS) $(B_BONUS)

%.o: %.s
	$(NASM) $(NASM_FLAGS) -o $@ $<

%: %.o
	gcc -no-pie -o $(NAME) $(BINS)

clean:
	rm -f $(OBJS) $(O_BONUS)

fclean: clean
	rm -f $(BINS) $(B_BONUS) $(NAME)

re: fclean all

.phony: all bonus clean fclean re