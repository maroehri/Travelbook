CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS =
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include
TEST_DIR = test
BIN_DIR = bin


# The files for your application, excluding the main.cpp
APP_SOURCES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
APP_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(APP_SOURCES))
APP_EXECUTABLE = $(BIN_DIR)/my_app

# The source for your main function
MAIN_SOURCE = $(SRC_DIR)/main.cpp
MAIN_OBJECT = $(OBJ_DIR)/main.o

# The files for your tests
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SOURCES))
TEST_EXECUTABLE = $(BIN_DIR)/test_app

# Default build target
all: $(APP_EXECUTABLE)

# Target for building the main application
$(APP_EXECUTABLE): $(APP_OBJECTS) $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Target for building the test application
test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(APP_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Generic rule for creating objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Generic rule for creating test objects
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/* $(APP_EXECUTABLE) $(TEST_EXECUTABLE)

# Target for running the tests
runtests: test
	./$(TEST_EXECUTABLE)

.PHONY: all test clean runtests
