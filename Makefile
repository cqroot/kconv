BUILD_DIR=$(CURDIR)/build
TARGET_EXEC=kconv

SRCS=src/main.c \
	 src/strutil.c \
	 src/data_unit.c \
	 src/unix_timestamp.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
CC=gcc
CFLAGS=-g

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p '$(dir $@)'
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: clean
clean:
	rm -rf '$(BUILD_DIR)'
