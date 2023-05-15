# links stdc++ library by default
# CC := g++
# or
CC := cc

all: test

#util.o: util.cc
#        $(CC) -c -o util.o  util.cc

test.o: test.cpp
#	$(CC) -c test.gcc

# notice -lstd++ is after the .o files
test: test.o
	$(CC) -o test test.o -lstdc++

clean:
	-rm test.o test