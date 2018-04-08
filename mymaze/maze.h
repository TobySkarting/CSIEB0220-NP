#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include "room.h"

class Maze {
 public:
  static Maze *GetInstance();

  Maze();

  void LoadMaze(const std::string &maze_file);
  const Room &GetRoom(int x, int y);

  int width();
  int height();

 private:
  static Maze *instance_;

  int width_;
  int height_;
  std::vector<Room> rooms;
};

#endif
