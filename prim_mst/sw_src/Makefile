# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -pedantic -O3

# Directories
SRC_DIR = src
OBJ_DIR = obj
APP_DIR = app

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Executable names
EXECUTABLES = $(SOURCES:$(SRC_DIR)/%.cpp=$(APP_DIR)/%.exe)

# Header files
HEADERS = $(wildcard $(SRC_DIR)/include/*.h)

# Default target
all: $(EXECUTABLES)

# Rule to build executables
$(APP_DIR)/%.exe: $(OBJ_DIR)/%.o
	@mkdir -p $(APP_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(APP_DIR)

.PHONY: all clean
