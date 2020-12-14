# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snara <snara@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 13:59:38 by snara             #+#    #+#              #
#    Updated: 2020/12/14 14:32:45 by snara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c
OBJS = ${SRCS:.c=.o}
HDRS = ft_printf.h

ifdef WITHBONUS
SRCS +=  
endif

LPATH = libft/
LIBFT = libft.a
LIB = $(LPATH)$(LIBFT)

CC = gcc
INC = -I. -I$(LPATH)
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} $(INC) -c $< 

all:	$(NAME)

$(NAME): $(OBJS) $(LIB) $(HDRS)
		ar rc $(NAME) $(LIB) $(OBJS)

libft: $(LIB)
$(LIB):
		make -C $(LPATH)

bonus:
		make WITHBONUS=1 all

clean:
		@make -C $(LPATH)/ clean
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
