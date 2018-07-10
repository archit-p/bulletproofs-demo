CFLAGS = -Wall
CC = g++ 
all:
all: checkdir prover.o verifier.o inner_product_arg.o group.o main.o num_theory.o vector_util.o
	$(CC) $(CFLAGS) -o build/demo build/num_theory.o build/vector_util.o build/main.o build/prover.o build/inner_product_arg.o build/group.o
checkdir:
	if [ ! -d "./build" ]; \
		then mkdir build && \
		echo "Created build dir"; \
		fi
prover.o:
	$(CC) $(CFLAGS) -c -o build/prover.o src/prover.cpp
inner_product_arg.o:
	$(CC) $(CFLAGS) -c -o build/inner_product_arg.o src/inner_product_arg.cpp
group.o:
	$(CC) $(CFLAGS) -c -o build/group.o src/group.cpp
main.o:
	$(CC) $(CFLAGS) -c -o build/main.o src/main.cpp
verifier.o:
	$(CC) $(CFLAGS) -c -o build/verifier.o src/verifier.cpp
num_theory.o:
	$(CC) $(CFLAGS) -c -o build/num_theory.o src/num_theory.cpp
vector_util.o:
	$(CC) $(CFLAGS) -c -o build/vector_util.o src/vector_util.cpp
clean:
	rm -rf build