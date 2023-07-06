CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
EXECUTABLE := inventory_management

.PHONY: all clean

all: banner $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@echo "Building $(EXECUTABLE)..."
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "Build successful!"

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compilation successful!"

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJ) $(EXECUTABLE)
	@echo "Cleanup successful!"

.PHONY: banner

banner:
	@echo "-------------------------------------------------------"
	@echo "|                  Welcome to Makefile                 |"
	@echo "|              Inventory Management Project            |"
	@echo "-------------------------------------------------------"
