# Use command "make mode=ERROR" for default build
all:
	cd build && g++ -c -Wall -Werror \
	../src/entity/interactable/InteractableEntityFactory.cpp \
	../inc/entity/interactable/InteractableEntityFactory.hpp \
	../inc/entity/interactable/IInteractableEntity.hpp \
	../src/entity/interactable/simple/RockGround.cpp \
	../inc/entity/interactable/simple/RockGround.hpp \
	../src/entity/interactable/simple/RoyalMat.cpp \
	../inc/entity/interactable/simple/RoyalMat.hpp \
	../src/entity/interactable/simple/BottomWall.cpp \
	../inc/entity/interactable/simple/BottomWall.hpp \
	../src/entity/interactable/simple/RightWall.cpp \
	../inc/entity/interactable/simple/RightWall.hpp \
	../src/entity/interactable/simple/LeftWall.cpp \
	../inc/entity/interactable/simple/LeftWall.hpp \
	../src/entity/interactable/simple/UpperWall.cpp \
	../inc/entity/interactable/simple/UpperWall.hpp \
	../src/entity/interactable/simple/Corner.cpp \
	../inc/entity/interactable/simple/Corner.hpp \
	../src/entity/interactable/simple/Grass.cpp \
	../inc/entity/interactable/simple/Grass.hpp \
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
	InteractableEntityFactory.o \
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
