#######################################
#              COMPILER               #
#######################################

CC	=	clang++

######################################
#             EXECUTABLE             #
######################################
NAME	=	ft_container

#######################################
#             DIRECTORIES             #
#######################################

OBJSDIR	=	objs

SRCSDIR	=	srcs/

######################################
#            SOURCE FILES            #
######################################

SRCS	=	main.cpp		\
			vector.cpp		\

INC		= includes
######################################
#            OBJECT FILES            #
######################################

OBJS	=	${addprefix ${OBJSDIR}/, ${SRCS:.cpp=.o}}

DEP	=	${OBJS:.o=.d}

#######################################
#                FLAGS                #
#######################################

FLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98 -I $(INC) -g3

#######################################
#                RULES                #
#######################################

.PHONY: clean fclean all re

all: ${NAME}

$(NAME): ${OBJS}
			${CC} ${FLAGS} ${OBJS} -o $@

-include $(DEP)
${OBJSDIR}/%.o:${SRCSDIR}%.cpp | $(OBJSDIR)
			${CC} ${FLAGS} -c $< -o $@

$(OBJSDIR):
	@mkdir -p $@

clean:
		rm -rf ${OBJSDIR}

fclean: clean
		rm -rf ${NAME}

re:	fclean all
