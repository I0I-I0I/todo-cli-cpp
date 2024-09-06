all: main

main: main.cpp
	@echo "Compiling main file"
	g++ -o build/main main.cpp

clean:
	@echo "Cleaning files"
	rm build/*
