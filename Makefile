CC = gcc

all: clean exploit

.PHONY: exploit
exploit:
	$(CC) exploit.c util.c -o exploit -no-pie -static

clean:
	rm -f exploit
