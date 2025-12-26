bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -std=c++11 -Wall -Wextra -g -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	 mkdir -p bin
	 g++ -o bin/testNode testNode.cpp Node.h
bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -std=c++11 -Wall -Wextra -g -o bin/testListLinked testListLinked.cpp

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

clean:
	rm -rf *.o *.gch bin

