# capstone library name (without prefix 'lib' and suffix '.so')
LIBNAME = capstone

disass: disass.o
	${CC} $< -O3 -Wall -l$(LIBNAME) -o $@.out

%.o: %.c
	${CC} -c $< -o $@
