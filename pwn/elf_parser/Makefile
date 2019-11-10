# capstone library name (without prefix 'lib' and suffix '.so')
LIBNAME = capstone

parser.out: parser.o
	${CC} $< -O3 -Wall -Wextra -std=c11 -pedantic -l$(LIBNAME) -o $@

%.o: %.c
	${CC} -c $< -o $@
