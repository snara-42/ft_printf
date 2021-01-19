# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 13:59:38 by snara             #+#    #+#              #
#    Updated: 2021/01/20 07:44:22 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

ifdef WITHBONUS
HDRS = ft_printf.h
SRCS = ft_printf.c ft_printf_parse.c ft_printf_output.c libft_c.c libft_n.c
else
HDRS = ft_printf.h
SRCS = ft_printf.c ft_printf_parse.c ft_printf_output.c libft_c.c libft_n.c
endif

LPATH = libft/
LIB = $(LPATH)libft.a

OBJS = ${SRCS:%.c=%.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

%.o: %.c $(HDRS)
		${CC} ${CFLAGS} -c $<

all:	$(NAME)

$(NAME): $(OBJS) $(HDRS) $(LPATH)
		make -C $(LPATH)
		cp $(LIB) $(NAME)
		ar rcs $(NAME) $(OBJS)

libft: $(LIB)
$(LIB):
		make -C $(LPATH)

bonus:
		make WITHBONUS=1 all

clean:
		rm -f ${OBJS} ${B_OBJS}
		make -C $(LPATH) clean

fclean:	clean	
		rm -f a.out $(NAME) $(LIB)

re: fclean all

test:
	make && ${CC} -fsanitize=address ${NAME} test_.c && ./a.out

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
