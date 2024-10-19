CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -g
OS := $(shell uname)

# Include the appropriate compiler version of C++98
ifeq ($(OS), Linux)
	CXXFLAGS += -std=c++98
else
	CXXFLAGS += -std=gnu++98
endif

SRCS := Account.cpp

OBJS_DIR := objects
OBJS := $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

NAME := main

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o $(NAME)
	@echo "Created" $(NAME)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Created" $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME).exe tests tests.exe
	rm -rf current*.log old_NOTIME.log

re: fclean all

test: $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) tests.cpp -o tests
	@echo "Created tests"

compare: test
	@./tests > current.log
	@echo "Appended tests to current.log file"
	@awk '{ print $$2 }' ./current.log > current_NOTIME.log
	@echo "Appended current.log file contents without timestamp to current_NOTIME.log"
	@awk '{ print $$2 }' ./19920104_091532.log > old_NOTIME.log
	@echo "Appended 19920104_091532.log file contents without timestamp to old_NOTIME.log"
	@echo "Comparing current_NOTIME.log and old_NOTIME.log"
	@diff current_NOTIME.log old_NOTIME.log && echo "No difference found!" || echo "Uh oh! An oopsie happened."
