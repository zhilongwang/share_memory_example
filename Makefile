all:
	g++ -o reader reader.cpp loopqueue.cpp
	g++ -o writer writer.cpp loopqueue.cpp