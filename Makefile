CC=gcc
CFLAGS=-Wall -Wextra -Werror
HASHTABLE=./src/hashTable.c
TESTS_DIR=./test
OUTPUT_DIR=$(TESTS_DIR)/bin
OP=-O3
TEST_FILES= $(wildcard $(TESTS_DIR)/*.c)
OUTPUT_FILES = $(patsubst $(TESTS_DIR)/%.c,$(OUTPUT_DIR)/%,$(TEST_FILES))

all: $(OUTPUT_DIR) $(OUTPUT_FILES)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(OUTPUT_DIR)/%: $(TESTS_DIR)/%.c
	$(CC) $(HASHTABLE) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OUTPUT_FILES)

.PHONY: all clean


