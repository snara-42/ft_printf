# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 13:59:38 by snara             #+#    #+#              #
#    Updated: 2021/01/04 22:38:38 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HDRS = ft_printf.h

ifdef WITHBONUS
SRCS = 
else
SRCS = ft_printf.c
endif

OBJS = ${SRCS:%.c=%.o}

LPATH = libft/
LIBFT = libft.a
LIB = $(LPATH)$(LIBFT)

CC = gcc
INC = -I$(LPATH)
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} $(INC) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS) $(LIB) $(HDRS)
		cp $(LIB) ./$(NAME)
		ar rcs $(NAME) $(OBJS)

libft: $(LIB)
$(LIB): $(LPATH)*.c $(LPATH)*.h
		make -C $(LPATH)

bonus:
		make WITHBONUS=1 all

clean:
		make clean -C $(LPATH)
		rm -f ${OBJS} ${B_OBJS}

fclean:	clean	
		rm -f ${LIB}
		rm -f a.out ${NAME}

re: fclean all

noodle:
	@clear
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo "	           (    )     (      )"
	@echo "	              (    )    ("
	@echo ""
	@echo "               ___...---=(=)=(===================="
	@echo '         ..-""          )=)=(=)==================='
	@echo "        |-._          ( ( (  ( ( (         _.-|"
	@echo '        |   `""----.................----""`   |'
	@echo "        |                                     |"
	@echo "        |                                     |"
	@echo "         \                                   /"
	@echo "          \                                 /"
	@echo "           \                               /"
	@echo "            \                             /"
	@echo "             \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                             __..--"" /'
	@echo "     '._     """----.....______.....----"""          _.'"
	@echo '         ""--..,,_____            _____,,..--""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo ""
	@echo ""
	@echo ""
	@echo "	           (    )     (      )"
	@echo "	              (    )    ("
	@echo ""
	@echo "                        =(=)=(===================="
	@echo "                        ==)=(=)==================="
	@echo "               ___...----())))(---....___"
	@echo '         ..-""          ) (((( )         ""-..'
	@echo "        |-._          ( ( (  ( ( (         _.-|"
	@echo '        |   `""----.................----""`   |'
	@echo "        |                                     |"
	@echo "        |                                     |"
	@echo "         \                                   /"
	@echo "          \                                 /"
	@echo "           \                               /"
	@echo "            \                             /"
	@echo "             \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                             __..--"" /'
	@echo "     '._     """----.....______.....----"""          _.'"
	@echo '         ""--..,,_____            _____,,..--""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "	           (    )     (      )"
	@echo "	              (    )    ("
	@echo "                        =(=)=(===================="
	@echo "                        ==)=(=)==================="
	@echo "                         ())))("
	@echo "                         )(((()"
	@echo "                         ())))("
	@echo "                         )(((()"
	@echo "               ___...----())))(---....___"
	@echo '         ..-""          ) (((( )         ""-..'
	@echo "        |-._          ( ( (  ( ( (         _.-|"
	@echo '        |   `""----.................----""`   |'
	@echo "        |                                     |"
	@echo "        |                                     |"
	@echo "         \                                   /"
	@echo "          \                                 /"
	@echo "           \                               /"
	@echo "            \                             /"
	@echo "             \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                             __..--"" /'
	@echo "     '._     """----.....______.....----"""          _.'"
	@echo '         ""--..,,_____            _____,,..--""'''
	@echo '                      """------"""'
	@sleep 0.5


.PHONY: all clean fclean tclean re bonus test noodle
