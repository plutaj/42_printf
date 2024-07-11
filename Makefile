NAME = libftprintf.a
SOURCES = \
		printf.c \
		functions.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f *.so

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
