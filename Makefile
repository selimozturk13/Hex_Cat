PROGRAM = hc
SRCS = main.c hex_functions.c utilities.c
HDRS = main.h
CC = gcc
DESTDIR ?= /usr/local
INSTALL_BIN_DIR := $(DESTDIR)/bin

all: $(PROGRAM)

$(PROGRAM): $(SRCS) $(HDRS)
	$(CC) $(SRCS) -o $(PROGRAM)
	@echo "Succesfuly compiled."

install: $(PROGRAM)
	@echo "installation's starting..."
	mkdir -p $(INSTALL_BIN_DIR)
	cp $(PROGRAM) $(INSTALL_BIN_DIR)
	@echo "'$(PROGRAM)' installed to $(INSTALL_BIN_DIR)"

clean:
	rm -f $(PROGRAM)
	@echo "Cleaned up."

.PHONY: all clean install
