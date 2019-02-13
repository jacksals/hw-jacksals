CXXFLAGS = --std=c++11 -Wall -g

ULListStr: ulliststr.o

ULListStr.o: ulliststr.h ulliststr.cpp
	g++ -g -Wall -c ulliststr.cpp -o ulliststr.o

clean:
	rm rf- ulliststr ulliststr.o

.PHONY: clean