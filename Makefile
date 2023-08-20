# Compiler options
CC := gcc
CFLAGS := -fsanitize=address -g -lm
LDLIBS := -lstdc++ -g

# Directories
SRC_DIR := src

# Source files
MAIN_SOURCE := main.cpp
SRC_SOURCE := $(wildcard $(SRC_DIR)/*.cpp)

# Target
MAIN_EXE := tasks

$(MAIN_EXE): $(MAIN_SOURCE) $(SRC_SOURCE)
	$(CC) $^ $(CFLAGS) $(LDLIBS) -o $@

# Phony target
.PHONY : clean 

clean:
	rm -rf $(MAIN_EXE)
