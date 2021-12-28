CC ?= gcc
CFLAGS :=					\
	-ansi					\
	-pedantic				\
	-Wpedantic				\
	-Wall					\
	-Wextra					\
	-Werror					\
	-ggdb					\
	-fsanitize=undefined	\
	-fsanitize=address

LDFLAGS += 					\
    -fsanitize=undefined 	\
    -fsanitize=address		

TARGET = mymips
BUILD_DIRECTORY = build
DIRECTORY_GUARD = @mkdir -p $(@D)
SRC = $(wildcard src/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIRECTORY)/%.c.o, $(SRC))

$(BUILD_DIRECTORY)/%.c.o: %.c
	@$(DIRECTORY_GUARD)
	@echo "[CC] $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@$(DIRECTORY_GUARD)
	@echo "[LD] $@"
	@$(CC) $(LDFLAGS) -o $@ $^

all: $(TARGET)
test: $(TESTS)

clean: 
	-rm -r $(BUILD_DIRECTORY)

distclean: clean
	-rm $(TARGET)

.PHONY: all clean distclean
.DEFAULT: all
