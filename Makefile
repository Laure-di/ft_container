#######################################
#              COMPILER               #
#######################################

CC	=	clang++

######################################
#             EXECUTABLE             #
######################################
NAME	=	ft_container

FT_NAME		=	ft

STD_NAME		=	std

#######################################
#             DIRECTORIES             #
#######################################

FTDIR	=	objs_ft

STDDIR	=	objs_std

SRCSDIR	=	srcs/

######################################
#            SOURCE FILES            #
######################################

SRCS	=	main.cpp		\

INC		= includes
######################################
#            OBJECT FILES            #
######################################

FTOBJS	=	${addprefix ${FTDIR}/, ${SRCS:.cpp=.o}}

STDOBJS	=	${addprefix ${STDDIR}/, ${SRCS:.cpp=.o}}

FTDEP	=	${FTOBJS:.o=.d}

STDDEP	=	${STDOBJS:.o=.d}

#######################################
#                FLAGS                #
#######################################

FLAGS = -Wall -Werror -Wextra -MMD -MP -std=c++98 -I $(INC) -g3

#######################################
#                RULES                #
#######################################

.PHONY: clean fclean all re

all : ft std

ft: ${FT}

std: ${STD}

$(FT_NAME): ${FTOBJS}
			${CC} ${FLAGS} -DFT ${FTOBJS} -o $@

$(STD_NAME): ${STDOBJS}
			${CC} ${FLAGS} -DSTD ${STDOBJS} -o $@

-include $(FTDEP)
${FTDIR}/%.o:${SRCSDIR}%.cpp | $(FTDIR)
			${CC} ${FLAGS} -DFT -c $< -o $@
-include $(STDDEP)
${STDDIR}/%.o:${SRCSDIR}%.cpp | $(STDDIR)
			${CC} ${FLAGS} -DSTD -c $< -o $@
$(FTDIR):
	@mkdir -p $@

$(STDDIR):
	@mkdir -p $@

clean:
		rm -rf ${STDDIR} ${FTDIR}

fclean: clean
		rm -rf ${FT_NAME} ${STD_NAME}

re:	fclean all
