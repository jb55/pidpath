
BIN ?= pidpath
PREFIX ?= /usr/local
CFLAGS = -Wall -Wextra

all: $(BIN)

$(BIN): pidpath.c
	$(CC) -o $@ $^

install: $(BIN)
	install $< $(PREFIX)/bin

clean:
	rm -f $(BIN)

