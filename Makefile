# Use command "make mode=ERROR" for default build
all:
	cd build && g++ -c -Wall -Werror \
	../src/entity/EntityContainer.cpp \
	../inc/entity/EntityContainer.hpp \
	../inc/entity/IUpdatable.hpp \
	../inc/entity/IInteractable.hpp \
	../inc/entity/DrawableTransformable.hpp \
	../src/util/Location.cpp \
	../inc/util/Location.hpp \
	../src/entity/EntityFactory.cpp \
	../inc/entity/EntityFactory.hpp \
	../inc/entity/IGridded.hpp \
	../src/entity/simple/RockGround.cpp \
	../inc/entity/simple/RockGround.hpp \
	../src/entity/simple/RoyalMat.cpp \
	../inc/entity/simple/RoyalMat.hpp \
	../src/entity/simple/BottomWall.cpp \
	../inc/entity/simple/BottomWall.hpp \
	../src/entity/simple/RightWall.cpp \
	../inc/entity/simple/RightWall.hpp \
	../src/entity/simple/LeftWall.cpp \
	../inc/entity/simple/LeftWall.hpp \
	../src/entity/simple/UpperWall.cpp \
	../inc/entity/simple/UpperWall.hpp \
	../src/entity/simple/Corner.cpp \
	../inc/entity/simple/Corner.hpp \
	../src/entity/simple/Grass.cpp \
	../inc/entity/simple/Grass.hpp \
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
	EntityContainer.o \
	Location.o \
	EntityFactory.o \
	RockGround.o \
	RoyalMat.o \
	BottomWall.o \
	RightWall.o \
	LeftWall.o \
	UpperWall.o \
	Corner.o \
	Grass.o \
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
