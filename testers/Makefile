NAME = exec

SRCS = ft_atoi_base.s 
OBJS = $(SRCS:.s=.o)
BINS = $(SRCS:%.s=%)

NASM = nasm
NASM_FLAGS = -f elf64
CC = gcc
LDFLAGS = -no-pie -nostartfiles

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.s
	$(NASM) $(NASM_FLAGS) -o $@ $<

%: %.o
	$(CC) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(BINS) $(NAME)

re: fclean all