CC=clang++
FLAGS= -Wall -Wextra -Werror
NAME=phonebook
OBJDIR = obj
SRC := $(wildcard *.cpp)
OBJ := $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(SRC)))

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
