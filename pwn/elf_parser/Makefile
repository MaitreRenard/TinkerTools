CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
		  -Wjump-misses-init -Wlogical-op

LIBRARIES=-lcapstone

parser.out: parser.o
	${CC} $< -O3 -std=c18 ${CFLAGS} -o $@ ${LIBRARIES}

%.o: %.c
	${CC} -c $< -o $@
