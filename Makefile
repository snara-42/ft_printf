# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 13:59:38 by snara             #+#    #+#              #
#    Updated: 2021/01/09 23:17:59 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

ifdef WITHBONUS
HDRS = ft_printf.h
SRCS = 
else
HDRS = ft_printf.h
SRCS = ft_printf.c libft.c
endif

OBJS = ${SRCS:%.c=%.o}

LPATH = libft/
LIBFT = libft.a
LIB = $(LPATH)$(LIBFT)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

%.o: %.c
		${CC} ${CFLAGS} -c $<

all:	$(NAME)

$(NAME): $(OBJS) $(HDRS)
		ar rcs $(NAME) $(OBJS)

libft: $(LIB)
$(LIB):
		make -C $(LPATH)

bonus:
		make WITHBONUS=1 all

clean:
		rm -f ${OBJS} ${B_OBJS}

fclean:	clean	
		rm -f a.out ${NAME}

re: fclean all

test:
	make && ${CC} ${CFLAGS} ${NAME} test_.c && ./a.out

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
