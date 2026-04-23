NAME = libasm.a

SRCS_DIR = ./srcs
SRCS = 

OBJS_DIR = ./srcs/objs/
OBJS = $(SRCS:%.s=$(OBJS_DIR)%.o)

NASM = nasm
NASM_FLAGS = -f elf64

all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.s | $(OBJS_DIR)
	$(NASM) $(NASM_FLAGS) -o $@ $<

clean:
	rm -rf srcs/objs/

fclean: clean
	rm -rf $(NAME)
	
re: fclean all
