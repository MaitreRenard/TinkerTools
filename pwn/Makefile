de_bruijn.out: de_bruijn.o
	${CC} $< -O3 -Wall -Wextra -std=c18 -pedantic -o $@ -lm

%.o: %.c
	${CC} -c $< -o $@
