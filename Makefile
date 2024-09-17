BUILDDIR=$(CURDIR)/build
BIN=$(BUILDDIR)/uconv

SRCS=src/main.c \
	 src/strutil.c \
	 src/data_unit.c \
	 src/unix_timestamp.c
CC=gcc

.PHONY: build
build:
	mkdir -p '$(BUILDDIR)'
	$(CC) -g $(SRCS) -o $(BIN)
