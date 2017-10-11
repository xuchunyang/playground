all: hello-world func

# XXX: Split compiling and testing

hello-world: hello-world.c
	${CC} hello-world.c -o hello-world
	echo y | ./hello-world
	rm hello-world

func: func.c
	${CC} func.c -o func
	./func
	rm func
