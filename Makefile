NAME = push_swap

SOURCES =	push_swap.c tools.c reverse.c short_three.c free_and_find.c push_to_a.c calculate.c push_to_b.c\

OBJECTS = $(SOURCES:%.c=%.o)

LIBFT	=	libft/libft.a
CC	=	cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./libft

LIBFT_FLAGS = -L ./libft -lft

all: $(LIBFT) $(NAME)	

$(LIBFT):
	make -C libft

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS)

clean:
	make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
