NAME = libftprintf.a 

CC = cc

FLAGS = -Wall -Wextra -Werror

AR = ar

RM = rm -f

FILES = ft_printf.c\

OBJS = ${FILES:.c=.o}

LIBFTDIR = ./libft

LIBFTNAME = libft.a

${NAME}:	makelibft ${OBJS}
	ar rc ${NAME} ${OBJS}

.c.o: 	
	${CC} $< -o ${<:.c=.o} -c

makelibft:
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

all: 		$(NAME)

clean:
	$(RM) $(OBJS) $(OBJS2)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean