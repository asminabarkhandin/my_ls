CC=gcc
CC_OPT = -g3 -fsanitize=address#-Wall -Wextra -Werror
OUTPUT=my_ls

all: ${OUTPUT}

${OUTPUT}: main.o load_flags.o print_flags.o
	${CC} ${CC_OPT} main.o load_flags.o print_flags.o -o ${OUTPUT}

load_flags.o: load_flags.c
	${CC} ${CC_OPT} -c load_flags.c

print_flags.o: print_flags.c
	${CC} ${CC_OPT} -c print_flags.c

main.o: main.c
	${CC} ${CC_OPT} -c main.c

clean:
	rm *.o ${OUTPUT}