.POSIX:
.SUFFIXES:

CC	= cc

CFLAGS	= -std=c99 \
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
					-fprofile-arcs -ftest-coverage \
					-fno-omit-frame-pointer -ffloat-store -fno-common -fstrict-aliasing \

LDFLAGS	= -lcriterion -lgcov --coverage

all:	test
test:	test.o binary_search.o
	$(CC) $(LDFLAGS) $? -o $@
binary_search.o:	binary_search.c
	$(CC) $(CFLAGS) $? -o $@
test.o:	test.c
	$(CC) -c $? -o $@
gcov: test
	./$?
	gcov binary_search.c
clean:
	rm -f *.{o,gcov,gcda,gcno} binary_search test main
