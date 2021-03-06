# Use command "make mode=ERROR" for default build
all:
	cd build && g++ -c -Wall -Werror -fno-rtti \
	../src/util/datastructure/QuadNode.cpp \
	../inc/util/datastructure/QuadNode.hpp \
	../src/util/datastructure/QuadTree.cpp \
	../inc/util/datastructure/QuadTree.hpp \
	../src/entity/SharedParameters.cpp \
	../inc/entity/SharedParameters.hpp \
	../src/util/InputUtil.cpp \
	../inc/util/InputUtil.hpp \
	../src/map/TextureContainer.cpp \
	../inc/map/TextureContainer.hpp \
	../src/entity/Entity.cpp \
	../inc/entity/Entity.hpp \
	../inc/util/enum/QuadPosition.hpp \
	../src/util/DatabaseUtil.cpp \
	../inc/util/DatabaseUtil.hpp \
	../src/entity/Returnable.cpp \
	../inc/entity/Returnable.hpp \
	../src/entity/simple/Sign.cpp \
	../inc/entity/simple/Sign.hpp \
	../src/entity/simple/Stair.cpp \
	../inc/entity/simple/Stair.hpp \
	../src/entity/simple/Hole.cpp \
	../inc/entity/simple/Hole.hpp \
	../inc/util/define/UndefineLoadEntity.hpp \
	../inc/util/define/DefineLoadEntity.hpp \
	../inc/util/observer/IGriddedSubject.hpp \
	../inc/util/observer/IGriddedObserver.hpp \
	../src/entity/button/FileButton.cpp \
	../inc/entity/button/FileButton.hpp \
	../src/entity/player/Player.cpp \
	../inc/entity/player/Player.hpp \
	../inc/entity/EntityCombination.hpp \
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
	-I/media/connor/DATA/Documents/git/FirstSfmlMongoProject/Emmoria/inc \
	$$(pkg-config --cflags --libs libmongocxx) -D$(mode) \
	-Wl,-rpath,/usr/local/lib && \
	g++ \
	main.o \
	QuadNode.o \
	QuadTree.o \
	SharedParameters.o \
	InputUtil.o \
	TextureContainer.o \
	Entity.o \
	DatabaseUtil.o \
	Returnable.o \
	Sign.o \
	Stair.o \
	Hole.o \
	FileButton.o \
	Player.o \
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
	-I/media/connor/DATA/Documents/git/FirstSfmlMongoProject/Emmoria/inc -fno-rtti \
	$$(pkg-config --cflags --libs libmongocxx) \
	-Wl,-rpath,/usr/local/lib \
	-lsfml-graphics -lsfml-window -lsfml-system

clean:
	find . -name '*.gch' -delete && \
	rm build/*.o output/*
