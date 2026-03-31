CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =

SOURCES = $(wildcard experiments/*/*.c)
EXECUTABLES = $(SOURCES:.c=)

all: $(EXECUTABLES)

%: %.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

.PHONY: clean run-all

clean:
	rm -f $(EXECUTABLES)

run-all:
	@echo "Build complete. Run any program from the experiments/ directory."
