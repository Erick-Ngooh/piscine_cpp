CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98

EXEC = RPN

SRCDIR = src
BINDIR = bin
OBJDIR = obj
INCDIR = include

SRCS = main.cpp 
OBJS := $(SRCS:%.cpp=%.o)
DEPS := $(OBJS:.o=.d)

all: $(BINDIR)/$(EXEC)

check: all 
		valgrind --leak-check=full ./$(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJDIR)/$(OBJS)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c -MMD -MP $< -o $@ 

-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(BINDIR)

re: fclean all

.PHONY: clean fclean re all
