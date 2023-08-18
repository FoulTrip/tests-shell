CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

DIR_SRC = src
UTILS_DIR = utils

SRCS = $(wildcard $(DIR_SRC)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

EXECUTABLE = hsh

$(EXECUTABLE): $(OBJS)
    $(cc) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXECUTABLE)