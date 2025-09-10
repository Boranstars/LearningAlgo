# Auto-generated Makefile
# Default: compile each .cpp into build/<same path>.o preserving dirs.
# Use `make` to build object files. Use `make bins` to link test_*.cpp
# into executables (linked with all object files).

# Compiler
CXX ?= g++
CXXFLAGS ?= -g -Wall -std=c++17

# ------------------------------------------------------------------
# Sources and objects
# - SRCS: non-test cpp files (will be compiled to object files)
# - TEST_SRCS: test_*.cpp files (contain main)
# ------------------------------------------------------------------
# find non-test source files, exclude build and common hidden dirs
SRCS := $(shell find . -type f -name '*.cpp' -not -name 'test*.cpp' -not -path './build/*' -not -path './.git/*' -not -path './.vscode/*')

# map ./path/to/foo.cpp -> build/path/to/foo.o
# NOTE: keep ALL_SRCS/ALL_OBJS for building all objects, but exclude sources
# that contain a `main` when linking test binaries.
ALL_SRCS := $(SRCS)
ALL_OBJS := $(patsubst ./%.cpp,build/%.o,$(ALL_SRCS))

# Detect sources that define a main function and exclude them from the
# objects used when linking test_*.cpp executables (they would cause
# multiple-definition of main).
MAIN_SRCS := $(shell grep -l "int main" $(ALL_SRCS) 2>/dev/null || true)
LIB_SRCS := $(filter-out $(MAIN_SRCS),$(ALL_SRCS))

# Objects used for linking libraries/tests (exclude files containing main)
OBJS := $(patsubst ./%.cpp,build/%.o,$(LIB_SRCS))

# test sources and their object files
TEST_SRCS := $(shell find . -type f -name 'test*.cpp' -not -path './build/*' -not -path './.git/*' -not -path './.vscode/*')
TEST_OBJS := $(patsubst ./%.cpp,build/%.o,$(TEST_SRCS))
TEST_BINS := $(patsubst ./%.cpp,build/%,$(TEST_SRCS))

.PHONY: all objs bins clean list

# Default: only build object files
all: objs

# build all object files by default (including example files that contain main)
objs: $(ALL_OBJS)

# Compile .cpp -> .o in build/ preserving subdirs
build/%.o: ./%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $< -> $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build test binaries: each test depends on its own .o and the other objects
bins: $(TEST_BINS)

build/%: build/%.o $(OBJS)
	@mkdir -p $(dir $@)
	@echo "Linking $@"
	$(CXX) $(CXXFLAGS) $^ -o $@

list:
	@printf "%s\n" $(SRCS) $(TEST_SRCS) | sed 's/^\.\///'

clean:
	rm -rf build

# end of Makefile
