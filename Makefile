# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Directories
INC_DIR = inc
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin

# Source files and target binaries
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/main/%.o,$(SRC_FILES))
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/test/%.o,$(TEST_FILES))
TARGET = $(BIN_DIR)/main/main_program
TEST_TARGET = $(BIN_DIR)/test/test_program

# Include directories
INCLUDES = -I$(INC_DIR)

# Build main program
build_main: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)/main
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Build test program with CATCH_CONFIG_MAIN
build_test: $(TEST_TARGET)

$(TEST_TARGET): $(filter-out $(BIN_DIR)/main/main.o, $(OBJ_FILES)) $(TEST_OBJ_FILES)
	@mkdir -p $(BIN_DIR)/test
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Compile source files
$(BIN_DIR)/main/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)/main
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

$(BIN_DIR)/test/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)/test
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Run the main program
run: $(TARGET)
	./$(TARGET)

# Run the test program
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

# Default target
all: main

# Phony targets
.PHONY: all clean
