NAME = libftprintf.a 

CC = cc

FLAGS = -Wall -Wextra -Werror -g

AR = ar

RM = rm -f

FILES = ft_printf.c ft_printf_utilities.c ft_conversions.c

OBJS = ${FILES:.c=.o}

LIBFTDIR = ./libft/

LIBFTNAME = libft.a

RED=\033[0;31m

GREEN=\033[0;32m

YELLOW=\033[0;33m

WHITE=\033[0m

${NAME}: ${OBJS}
	@printf "$(YELLOW)TRYING TO COMPILE LIBFTPRINTF$(WHITE)"
	@make -s makelibft
	@${AR} rc ${NAME} ${OBJS} $(LIBFTDIR)$(LIBFTNAME)
	@printf "\r$(GREEN)LIBFTPRINTF READY TO USE$(WHITE)"

.c.o: 	
	@${CC} $< -o ${<:.c=.o} -c ${FLAGS} -fPIE -g

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
