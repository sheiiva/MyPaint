##
## 		S O U R C E S  M A K E F I L E
##
## Corentin COUTRET-ROZET
## https://github.com/sheiiva/MyPaint
##
##

CC			=	clang
LD			=	$(CC)
PRINT		=	@echo
RM          =   @rm -f

INCLUDES	=	$(shell find . -name '*.h' | grep -oP ".*/" | uniq | awk '{print "-I"$$0}')

SOURCES		=	$(shell find . -name '*.c')

OBJ 		= 	$(SOURCES:.c=.o)

%.o: %.c
	$(PRINT) "\n> COMPILE $<\n"
	$(CC) $(CFLAGS) -c $< -o $@

override CFLAGS 	+=	-g3 -W -Wall -Wextra -Werror $(INCLUDES)
override LDLIBS 	+=	-lm -lcsfml-audio -lcsfml-graphics -lcsfml-system -lcsfml-window

NAME 		= 	$(ROOT_PATH)MyPaint

$(NAME): $(OBJ)
	$(PRINT) "\n------->\tCOMPILED SRC DEPENDENCIES.\n\nLET'S LINK IT ALL:\n"
	$(LD) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	$(PRINT) "\n------->\tEXEC [ $@ ]\n"

all: $(NAME)

clean:
	$(PRINT) "\n------->\tREMOVE TMP FILES\n"
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)

fclean: clean
	$(PRINT) "------->\tREMOVE BINARY\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re