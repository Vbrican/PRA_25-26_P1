bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -std=c++11 -Wall -Wextra -g -o bin/testListArray testListArray.cpp

clean:
	rm -rf *.o *.gch bin

