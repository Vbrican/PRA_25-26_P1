bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -std=c++11 -Wall -Wextra -g -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	 mkdir -p bin
	 g++ -o bin/testNode testNode.cpp Node.h

clean:
	rm -rf *.o *.gch bin

