CC=gcc
CC_OPT = -g3 -fsanitize=address -Wall -Wextra -Werror
OUTPUT=my_ls

all: ${OUTPUT}

${OUTPUT}: main.o load_flags.o print_flags.o a_flag.o t_flag.o no_flag.o both_flag.o
	${CC} ${CC_OPT} main.o load_flags.o print_flags.o a_flag.o t_flag.o no_flag.o both_flag.o -o ${OUTPUT}

a_flag.o: a_flag.c
	${CC} ${CC_OPT} -c a_flag.c

t_flag.o: t_flag.c
	${CC} ${CC_OPT} -c t_flag.c

both_flag.o: both_flag.c
	${CC} ${CC_OPT} -c both_flag.c

no_flag.o: no_flag.c
	${CC} ${CC_OPT} -c no_flag.c

print_flags.o: print_flags.c
	${CC} ${CC_OPT} -c print_flags.c

main.o: main.c
	${CC} ${CC_OPT} -c main.c

clear:
	rm *.o ${OUTPUT}