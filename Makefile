CXX = clang++
CXXFLAGS = -Wall -std=c++17

SRC_DIR = src
BUILD_DIR = build

SOURCES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE = $(BUILD_DIR)/cowsay

INCLUDE_DIRS = -I$(SRC_DIR) -I$(SRC_DIR)/classes/billboard -I$(SRC_DIR)/classes/cli -I$(SRC_DIR)/classes/creature -I$(SRC_DIR)/functions -I$(SRC_DIR)/libs/fstring -I$(SRC_DIR)/utils

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
