# capstone library name (without prefix 'lib' and suffix '.so')
LIBNAME = capstone

parser: parser.o
	${CC} $< -O3 -Wall -Wextra -std=c99 -pedantic -l$(LIBNAME) -o $@

%.o: %.c
	${CC} -c $< -o $@
