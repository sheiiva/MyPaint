##
## 		S O U R C E S  M A K E F I L E
##
## Corentin COUTRET-ROZET
## https://github.com/sheiiva/MyPaint
##
##

CC			=	gcc
LD			=	$(CC)
PRINT		=	@echo -e
RM          =   @rm -f

INCLUDES	=	$(shell find . -name '*.h' | grep -oP ".*/" | uniq | awk '{print "-I"$$0}')

SOURCES		=	$(shell find . -name '*.c')

OBJ 		= 	$(SOURCES:.c=.o)

override CFLAGS 	+=	-g3 -W -Wall -Wextra $(INCLUDES)
override LDLIBS 	+=	-lm -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

NAME 		= 	$(ROOT_PATH)MyPaint

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tPRECOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(PRINT) "\n------->\tCONGRATS !\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re