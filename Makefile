# C compiler I want to use
CC=gcc
# flags I want to use
CFLAGS=-Wall -Wextra -Werror
# directory with .c file where the .h file is included
HASHTABLE=./src/hashTable.c
# directory with .c test files
TESTS_DIR=./test
# directory where I want the post-compilation binary files to go to
OUTPUT_DIR=$(TESTS_DIR)/bin
# optimization I want to use
OP=-O3
# List of all test files in the test directory
TEST_FILES= $(wildcard $(TESTS_DIR)/*.c)
# List of how the output files should be named and where they should go
OUTPUT_FILES = $(patsubst $(TESTS_DIR)/%.c,$(OUTPUT_DIR)/%,$(TEST_FILES))

# Run to make all the output files for all tests
all: $(OUTPUT_DIR) $(OUTPUT_FILES)

# Make sure that a /test/bin directory is made if there is not one already
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Compile each test file with the wanted format
$(OUTPUT_DIR)/%: $(TESTS_DIR)/%.c
	$(CC) $(HASHTABLE) $(CFLAGS) -o $@ $<

# Get rid of all the output files
clean:
	rm -f $(OUTPUT_FILES)

# Let them know it's all clean
.PHONY: all clean

# Add a 'refresh' target to clean and then rebuild everything
refresh: clean all

