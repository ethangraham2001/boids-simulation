# libsfml: g++ lib/main.o -o simulation -L<sfml-install-path>/lib -lsfml-graphics -lsfml-window -lsfml-system
#
CXX = g++
CXXFLAGS = -std=c++11 -Isrc/lib -pthread
LDFLAGS = -lgtest -lgtest_main

SRC_DIR = src/lib
TEST_DIR = test
BUILD_DIR = build
MAIN_DIR = src/main

TEST = tests
PROGRAM = boids

# List your source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Generate object file names for source and test files
SRC_OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILES))

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files to object files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile and link all object files to create the test executable
$(TEST): $(SRC_OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(PROGRAM): $(SRC_OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

.PHONY: test clean

test: $(TEST)
	./$(TEST)

clean:
	rm -rf $(BUILD_DIR) $(TEST)
