NAME = libftprintf.a 

CC = cc

FLAGS = -Wall -Wextra -Werror -g

AR = ar

RM = rm -f

FILES = ft_printf.c ft_printf_utilities.c

LIBFT_FILES = libft/ft_strdup.c \
				libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_strchr.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_split.c \
				libft/ft_strrchr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_calloc.c \
				libft/ft_itoa.c \
				libft/ft_strjoin.c \
				libft/ft_strmapi.c \
				libft/ft_substr.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_striteri.c \
				libft/ft_strtrim.c \

OBJS = ${FILES:.c=.o}

LIBFT_OBJS = ${LIBFT_FILES:.c=.o}

LIBFTDIR = ./libft/

LIBFTNAME = libft.a

RED=\033[0;31m

GREEN=\033[0;32m

YELLOW=\033[0;33m

WHITE=\033[0m

${NAME}: ${OBJS}
	@printf "$(YELLOW)TRYING TO COMPILE LIBFTPRINTF$(WHITE)"
	@make -s makelibft
	@${AR} rc ${NAME} ${OBJS} $(LIBFT_OBJS)
	@printf "\r$(GREEN)LIBFTPRINTF READY TO USE$(WHITE)"

.c.o: 	
	@${CC} $< -o ${<:.c=.o} -c ${FLAGS} -fPIE

makelibft:
	@make -s -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@printf "$(YELLOW)CLEANING ALL FILES$(WHITE)"
	@make -s -C $(LIBFTDIR) fclean
	@$(RM) $(NAME)
	@printf "\r$(RED)ALL FILES ARE CLEANED$(WHITE)"

re: clean all

.PHONY: all clean

samael:
	@echo "                               (\_/)                                        "
	@echo "                               (0.0)                                        "
	@echo "                               />*<\                                        "
	@echo "         ******\   ******\  **\      **\  ******\  ********\ **\            "
	@echo "        **  __**\ **  __**\ ***\    *** |**  __**\ **  _____|** |           "
	@echo "        ** /  \__|** /  ** |****\  **** |** /  ** |** |      ** |           "
	@echo "        \******\  ******** |**\**\** ** |******** |*****\    ** |           "
	@echo "         \____**\ **  __** |** \***  ** |**  __** |**  __|   ** |           "
	@echo "        **\   ** |** |  ** |** |\*  /** |** |  ** |** |      ** |           "
	@echo "        \******  |** |  ** |** | \_/ ** |** |  ** |********\ ********\      "
	@echo "         \______/ \__|  \__|\__|     \__|\__|  \__|\________|\________|     "
