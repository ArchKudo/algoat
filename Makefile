.POSIX:
.SUFFIX:

CC	= cc
CFLAGS	= -g -Wall -Wextra -Werror -pedantic -O2
LDLIBS	= -lcriterion

SRC_DIR	= src
BIN_DIR = bin
OBJ_DIR = obj

SEARCH_DIR	= search


all: $(BIN_DIR)/bin_search
$(BIN_DIR)/bin_search:
	$(CC) $(CFLAGS) $(SRC_DIR)/$(SEARCH_DIR)/bin_search.c -o $(BIN_DIR)/bin_search
clean:
	rm -f $(BIN_DIR)/*
