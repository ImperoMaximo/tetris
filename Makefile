# Compiler / tools
CXX := g++
RM  := rm -f
MKDIR := mkdir -p

# Directories
SRC_DIRS := . tetrominos
BUILD_DIR := build

# Binary
BIN := tetris

# Flags
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
DEPFLAGS := -MMD -MP

DEBUG_FLAGS   := -O0 -g -DDEBUG
RELEASE_FLAGS := -O2 -DNDEBUG

# -------------------------------------------------------------------
# Automatic source discovery
# -------------------------------------------------------------------
SRCS := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cpp))

# Convert src paths into build/xxx.o
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# -------------------------------------------------------------------
# Default rule = release build
# -------------------------------------------------------------------
.PHONY: all
all: CXXFLAGS += $(RELEASE_FLAGS)
all: $(BIN)

# -------------------------------------------------------------------
# Build binary
# -------------------------------------------------------------------
$(BIN): $(OBJS)
	@echo "[LINK] $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

# -------------------------------------------------------------------
# Object build rule
# Build objects in build/... creating directories as needed
# -------------------------------------------------------------------
$(BUILD_DIR)/%.o: %.cpp
	@echo "[CXX] $<"
	@$(MKDIR) $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# -------------------------------------------------------------------
# Include dependency files
# -------------------------------------------------------------------
-include $(DEPS)

# -------------------------------------------------------------------
# Debug & Release
# -------------------------------------------------------------------
.PHONY: debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: clean $(BIN)

.PHONY: release
release: CXXFLAGS += $(RELEASE_FLAGS)
release: clean $(BIN)

# -------------------------------------------------------------------
# Run
# -------------------------------------------------------------------
.PHONY: run
run: $(BIN)
	./$(BIN)

.PHONY: valgrind
valgrind: $(BIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN)

# -------------------------------------------------------------------
# Cleaning
# -------------------------------------------------------------------
.PHONY: clean
clean:
	@echo "[CLEAN]"
	$(RM) $(BIN)
	$(RM) -r $(BUILD_DIR)

.PHONY: rebuild
rebuild: clean all