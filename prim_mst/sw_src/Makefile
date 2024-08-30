# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -O3 -Wconversion -Wshadow

# Directories
SRC_DIR = src
INCLUDE_DIR = $(SRC_DIR)/include
BIN_DIR = bin
OBJ_DIR = obj

# Binary name
BIN_NAME = mst

# Source files
SRC_FILES = $(SRC_DIR)/mst.cpp $(SRC_DIR)/static_mst_mtx.cpp

# Object files
OBJ_FILES = $(OBJ_DIR)/mst.o $(OBJ_DIR)/static_mst_mtx.o

# Executable
EXEC = $(BIN_DIR)/$(BIN_NAME)

# Include directories
INCLUDES = -I $(INCLUDE_DIR)

# Header files
HEADERS = $(INCLUDE_DIR)/size_def.h

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $@

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create bin and obj directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Clean up build files
clean:
	rm -f $(OBJ_FILES) $(EXEC)

.PHONY: all clean