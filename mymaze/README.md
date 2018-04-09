# Homework 1 - Maze I

## User Guide

The source code includes

```
main.cc
maze.cc
player.cc
room.cc
```

### Prerequisites

GCC 5.4.0~ with C++ 11 support is needed to build this program.

### How to build

You can choose to use MakeFiles or just simply compile with g++.

#### Build with make

```
cmake .
make
```

#### Build with g++

```
g++ -o mymaze -g main.cc maze.cc player.cc room.cc --std=c++11
```

### Run the program

Use `mymaze -f file` to load the maze file and start the game.

```
./mymaze -f mazefile.txt
```

After the maze file is loaded into the program, one can use the common W(up), S(down), A(left), D(right) or the specified 1(up), 2(left), 3(right) or 4(down) to move the player.

## About the Program

The `Maze` holds the structure of the maze.
It stores each `Room` in a `std::vector`.
Each room has four walls.
The wall can be one of the type in 

```cpp
enum WallType : short {
  kNothing,
  kWall,
  kEmpty,
  kExit,
  kEntrance,
};
```

The `Player` knows the position it stands on.

For each game loop, the program receives the direction the user gave.
It checks whether the player's move will reach the exit or not, and then handle the move if it isn't.
When you reach the exit, the program ends.
