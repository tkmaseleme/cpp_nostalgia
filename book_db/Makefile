# Compiler settings
CC := g++
CFLAGS := -std=c++11 -Wall

# Source files and object files
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

# Output executable
EXEC := virtual_bookshelf

# Default target: Build the executable and display welcome banner
all: welcome $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the compiled object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Rule to display the welcome banner
.PHONY: welcome
welcome:
	@echo "**************************************************"
	@echo "*   Welcome to the Virtual Bookshelf Program!    *"
	@echo "**************************************************"
