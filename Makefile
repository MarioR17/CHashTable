CC=gcc
CFLAGS=-Wall -Wextra -Werror
HASHTABLE=./src/hashTable.c
TESTS_DIR=./test
OP=-O3
TEST_FILES= $(wildcard $(TESTS_DIR)*.c)
OUTPUT_FILES = $(patsubst $(TESTS_DIR)%.c,%,$(TEST_FILES))

all: $(OUTPUT_FILES)

%: $(SRC_DIR)%.c
	$(CC) $(HASHTABLE) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OUTPUT_FILES)

.PHONY: all clean


