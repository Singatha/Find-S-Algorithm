# ML Lab 2 makefile
# Xhanti Singatha
CC=g++


cocept: ConceptLearning.o 
	$(CC)  ConceptLearning.o -std=c++11 -o concept

ConceptLearning.o: ConceptLearning.cpp
	$(CC) ConceptLearning.cpp -std=c++11 -c

clean:
	@rm -f *.o
