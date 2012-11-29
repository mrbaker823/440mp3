all: classify

classify: main.o Image.o ImageSet.o
	g++ main.o Image.o ImageSet.o -o classify

main.o: main.cpp
	g++ -c main.cpp

Image.o: Image.h Image.cpp
	g++ -c Image.h Image.cpp

ImageSet.o: ImageSet.h ImageSet.cpp
	g++ -c ImageSet.h ImageSet.cpp

clean:
	rm -rf *o classify

