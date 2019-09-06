CC = g++
FLAG = -std=c++14

build:
	$(CC) $(FLAG) *.cpp -o out.exe

run:
	./out.exe

clean:
	rm ./out.exe
