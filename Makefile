# Use command "make mode=ERROR" for default build
all:
	cd build && g++ -c -Wall -Werror \
	../main.cpp \
	$$(pkg-config --cflags --libs libmongocxx) -D$(mode) \
	-Wl,-rpath,/usr/local/lib && \
	g++ \
	main.o \
	-o ../output/emmoria \
	$$(pkg-config --cflags --libs libmongocxx) \
	-Wl,-rpath,/usr/local/lib \
	-lsfml-graphics -lsfml-window -lsfml-system

clean:
	find . -name '*.gch' -delete && \
	rm build/*.o output/*
