CC = clang
CFLAGS = -O2 -Wall -I ..

all: testGet  testPost

testGet: testGet.c
	$(CC) $(CFLAGS) -o testGet testGet.c

testPost: testPost.c
	$(CC) $(CFLAGS) -o testPost testPost.c

clean:
	rm -f testGet testPost *~
