all: 
	g++ -o build/main src/main.cpp

clean:
	@echo "Cleaning files"
	rm build/*
