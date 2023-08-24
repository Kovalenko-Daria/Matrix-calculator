matrix_calculator: basic_operations.o extended_operations.o calculator.o
	gcc -Wall -Werror -Wextra basic_operations.o extended_operations.o calculator.o -o matrix_calculator

basic_operations.o: basic_operations.c
	gcc -Wall -Werror -Wextra -c basic_operations.c -o basic_operations.o

extended_operations.o: extended_operations.c
	gcc -Wall -Werror -Wextra -c extended_operations.c -o extended_operations.o

calculator.o: calculator.c
	gcc -Wall -Werror -Wextra -c calculator.c -o calculator.o

.PHONY:rebuild clean all
 
rebuild:clean all

clean:
	rm -rf *.o matrix_calculator

all: matrix_calculator
