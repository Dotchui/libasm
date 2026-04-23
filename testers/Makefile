NAME = exec

SRCS = ft_atoi_base.s
OBJS = $(SRCS:.s=.o)
BINS = $(SRCS:%.s=%)

NASM = nasm
NASM_FLAGS = -f elf64
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	gcc -no-pie -o exec main.c ft_atoi_base.o

%.o: %.s
	$(NASM) $(NASM_FLAGS) -o $@ $<

%: %.o
	gcc -no-pie -o exec main.c ft_atoi_base.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BINS) $(NAME)

re: fclean all