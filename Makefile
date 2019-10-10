.PHONY: all

all: main.c vec.h
	mkdir -p build
	clang -I/usr/local/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2 -std=c11 -g main.c -o build/demo

run: all
	./build/demo

clean:
	rm -rf ./build
