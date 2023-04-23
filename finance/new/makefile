CC = g++
FLAG = -g -Wall -pedantic -std=c++2b -fmodules-ts -c #-fmodule-header


ttt: EuropeanOption.o testOption.o
	$(CC) -o ttt EuropeanOption.o testOption.o

test: EuropeanOption.o testOption.o NonlinearSolver.o
	$(CC) -o test EuropeanOption.o testOption.o NonlinearSolver.o

NonlinearSolver.o: NonlinearSolver.cpp
	$(CC) $(FLAG) NonlinearSolver.cpp

SteffensensSolver.o: SteffensensSolver.cpp
	$(CC) $(FLAG) SteffensensSolver.cpp
EuropeanOption.o: EuropeanOption.cpp
	$(CC) $(FLAG) EuropeanOption.cpp

testOption.o: testOption.cpp
	$(CC) $(FLAG) testOption.cpp

tt: hello.o main.o
	$(CC) -o tt hello.o main.o

hello.o: hello.cpp
	g++ -fmodules-ts -std=c++2b -c hello.cpp

main.o: main.cpp
	g++ -fmodules-ts -std=c++2b -c main.cpp

clean:
	rm *.o test ./a.out tt ttt