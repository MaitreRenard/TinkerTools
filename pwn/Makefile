de_bruijn.out: de_bruijn.o
	${CC} $< -O3 -Wall -Wextra -std=c11 -pedantic -o $@

%.o: %.c
	${CC} -c $< -o $@
