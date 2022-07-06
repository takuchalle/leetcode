all: run
	
build: main.cpp
	g++ -std=c++17 -O2 main.cpp

clean:
	rm ./a.out

run: build
	./a.out

.PHONY: all build run clean
