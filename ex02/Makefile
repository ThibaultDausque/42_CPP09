CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf
SRC = main.cpp \
	  PmergeMe.cpp
OBJS_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJS_DIR)/%.o)

NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@clear

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
	@clear

.PHONY: all clean fclean re
