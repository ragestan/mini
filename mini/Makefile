NAME = minitalk.a
RM = rm -f
SRC 	= client.c\
			server.c\
			utility.c\

FILIO = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):		$(FILIO)
		ar -rc $(NAME) $(FILIO)

clean:
		$(RM) $(FILIO)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
