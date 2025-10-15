# name
NAME := bureau

# files
## sources
SRC :=
vpath %.cpp src/
SRC += main.cpp
SRC += Bureaucrat.cpp
SRC += AForm.cpp
SRC += ShrubberyCreationForm.cpp
SRC += RobotomyRequestForm.cpp
SRC += PresidentialPardonForm.cpp
SRC += Intern.cpp

## objects
OBJ := $(SRC:.cpp=.o)
OBJ := $(addprefix obj/,$(OBJ))

## dependencies
DEP := $(OBJ:.o=.d)

# commands
CC := c++
LD := c++
RM := rm -rf
MKDIR = mkdir -p $(@D)

# flags
## cflags
CFLAGS :=
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -O3
CFLAGS += -std=c++98

## cppflags
CPPFLAGS :=
CPPFLAGS += -Iinc/
CPPFLAGS += -MMD
CPPFLAGS += -MP

## ldflags
LDFLAGS :=

ifdef DEBUG
	CFLAGS += -O0
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

ifeq ($(DEBUG), 2)
	CFLAGS += -pg
	LDFLAGS += -pg
endif

# rules

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(OBJ) -o $@ $(LDFLAGS)

obj/%.o: %.cpp
	$(MKDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEP)

clean:
	$(RM) obj/

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

valgrind: re
	valgrind ./$(NAME)

.PHONY: all clean fclean re
