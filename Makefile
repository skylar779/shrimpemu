BINARY := build/shrimpemu

LDFLAGS := 

C_SOURCE_FILES := $(wildcard src/*.c) $(wildcard src/**/*.c)
C_OBJECT_FILES := $(patsubst src/%.c, build/%.o, $(C_SOURCE_FILES))

CFLAGS := -std=gnu99 -g
INCLUDE := -I./include

.PHONY: all clean run

all: BINARY

clean:
	@rm -r build/

run: BINARY
	./$(BINARY)

BINARY: $(C_OBJECT_FILES)
	@gcc -o $(BINARY) $(C_OBJECT_FILES) $(LDFLAGS)

build/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
