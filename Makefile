.POSIX:
.SUFFIXES:

CC	= cc

test_CFLAGS	= -std=c99 \
							-fprofile-arcs -ftest-coverage \
							-O3 -g -c

prog_CFLAGS	= -std=c99 \
							-pedantic -Wall \
							-Wno-missing-braces -Wextra -Wno-missing-field-initializers -Wformat=2 \
							-Wswitch-default -Wswitch-enum -Wcast-align -Wpointer-arith \
							-Wbad-function-cast -Wstrict-overflow=5 -Wstrict-prototypes -Winline \
							-Wundef -Wnested-externs -Wcast-qual -Wshadow -Wunreachable-code \
							-Wlogical-op -Wfloat-equal -Wstrict-aliasing=2 -Wredundant-decls \
							-Wold-style-definition -Werror \
							-g \
							-O2 \
							-c \
							-fno-omit-frame-pointer -ffloat-store -fno-common -fstrict-aliasing \

LDFLAGS	= -lcriterion -lgcov --coverage
all:	main
main:	main.o binary_search.o
	$(CC) $? -o $@
main.o:	main.c
	$(CC) $(prog_CFLAGS) $? -o $@
test:	test.o binary_search.o
	$(CC) $(LDFLAGS) $? -o $@
binary_search.o:	binary_search.c
	$(CC) $(prog_CFLAGS) $? -o $@
test.o:	test.c
	$(CC) $(test_CFLAGS) $? -o $@
clean:
	rm -f *.{o,gcov,gcda,gcno} binary_search test main
