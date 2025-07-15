CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRC = main.cpp \
	BitcoinExchange.cpp
OBJS_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJS_DIR)/%.o)

NAME = btc

all: $(NAME)

# PROGRESS BAR
BAR_LENGTH = 50
TOTAL_FILES = $(words $(SRC))
COMPILED_FILE = 0

define progress_bar
	@COMPILED_FILE=$$((COMPILED_FILE + 1)); \
	PERCENT=$$((COMPILED_FILE * 100 / $(TOTAL_FILES))); \
	FILLED=$$((PERCENT * $(BAR_LENGTH) / 100)); \
	EMPTY=$$(($(BAR_LENGTH) - $$FILLED)); \
	BAR=$$(printf "%0.s⬜"); \

endef

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