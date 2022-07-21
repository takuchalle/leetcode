all: run
	
build: main.cpp
	g++ -std=c++17 -O0 -g main.cpp

clean:
	rm ./a.out

run: build
	./a.out

.PHONY: all build run clean
