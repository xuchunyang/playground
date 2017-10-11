CFLAGS = -std=c99 -Wall

all: hello-world func

# XXX: Split compiling and testing

hello-world: hello-world.c
	$(CC) $(CFLAGS) hello-world.c -o hello-world
	echo y | ./hello-world
	rm hello-world

func: func.c
	$(CC) $(CFLAGS) func.c -o func
	./func
	rm func
