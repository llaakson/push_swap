NAME = push_swap

SOURCES =	push_swap2.c tools.c push.c rotate.c reverse.c swap.c short_three.c push_to_b.c push_to_a.c\

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
