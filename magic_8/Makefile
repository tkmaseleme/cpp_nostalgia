# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source file and output file name
SRC = main.cpp
OUT = magic_8

# Rule to build the executable
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# Rule to clean the generated files
clean:
	rm -f $(OUT)
