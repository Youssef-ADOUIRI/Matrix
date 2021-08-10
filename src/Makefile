
prog: main.o matrix.o
	g++ main.o matrix.o -o prog

main.o: main.cpp
	g++ -c main.cpp

matrix.o: matrix.cpp
	g++ -c matrix.cpp

clean:
	rm main.o matrix.o prog