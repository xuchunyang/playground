hello-world: hello-world.c
	${CC} hello-world.c -o hello-world
	echo y | ./hello-world
	rm hello-world
