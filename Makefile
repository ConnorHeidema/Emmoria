# Use command "make mode=ERROR" for default build
all:
	cd build && g++ -c -Wall -Werror \
	../src/map/TileMap.cpp \
	../inc/map/TileMap.hpp \
	../src/debug/DebugMetricVisualizer.cpp \
	../inc/debug/DebugMetricVisualizer.hpp \
	../src/database/DatabaseReader.cpp \
	../inc/database/DatabaseReader.hpp \
	../src/loop/GameLoop.cpp \
	../inc/loop/GameLoop.hpp \
	../src/util/logger/Logger.cpp \
	../inc/util/logger/Logger.hpp \
	../inc/util/logger/ILogger.hpp \
	../main.cpp \
	$$(pkg-config --cflags --libs libmongocxx) -D$(mode) \
	-Wl,-rpath,/usr/local/lib && \
	g++ \
	main.o \
	TileMap.o \
	DebugMetricVisualizer.o \
	DatabaseReader.o \
	GameLoop.o \
	Logger.o \
	-o ../output/emmoria \
	$$(pkg-config --cflags --libs libmongocxx) \
	-Wl,-rpath,/usr/local/lib \
	-lsfml-graphics -lsfml-window -lsfml-system

clean:
	find . -name '*.gch' -delete && \
	rm build/*.o output/*
