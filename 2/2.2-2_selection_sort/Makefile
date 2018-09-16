CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -O3 -std=c++17
all: main

main: main.cc
	$(CXX) $(CXXFLAGS) $< -o $@

test: main 1.in 1.out
	./main < 1.in | diff -w -s 1.out -

clean:
	rm -f main

.PHONY: test clean

