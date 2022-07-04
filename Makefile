all: run
	

build: main.cpp
	g++ main.cpp

run: build
	./a.out

.PHONY: all build run
