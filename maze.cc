#include "maze.h"
#include <fstream>
#include <sstream>
#include "player.h"

Maze *Maze::instance_ = nullptr;

Maze *Maze::GetInstance() {
  if (Maze::instance_ == nullptr)
    Maze::instance_ = new Maze;
  return Maze::instance_;
}

Maze::Maze() {
}

template <typename T>
std::vector<T> ParseList(const std::string &str, const std::string &delimeter) {
  std::vector<T> list;
  size_t start = 0;
  size_t end = str.find(delimeter);
  while (end != std::string::npos) {
    std::string sub = str.substr(start, end - start);
    list.push_back(std::stoi(sub));
    start = end + delimeter.length();
    end = str.find(delimeter, start);
  }
  list.push_back(std::stoi(str.substr(start)));
  return list;
}

void Maze::LoadMaze(const std::string &maze_file) {
  std::ifstream fin(maze_file);
  if (!fin)
    throw std::runtime_error("unable to open file: " + maze_file);

  std::string line;
  if (!std::getline(fin, line)) {
    throw std::runtime_error("format error: unable to read the input file");
  }
  auto list = ParseList<int>(line, ",");
  if (list.size() != 2) {
    std::stringstream error;
    error << "format error: the maze size is incorrect" << std::endl << "your input: " << line;
    throw std::runtime_error(error.str());
  }
  this->width_ = list[0];
  this->height_ = list[1];

  for (int x = 0; x < this->height_; ++x)
    for (int y = 0; y < this->width_; ++y) {
      if (!std::getline(fin, line)) {
        throw std::runtime_error("format error: unable to read the input file");
      }
      auto list = ParseList<short>(line, ",");
      if (list.size() != 5) {
        std::stringstream error;
        error << "format error: the room size is incorrect" << std::endl << "your input: " << line;
        throw std::runtime_error(error.str());
      }
      Room room(list[0], list[1], list[2], list[3], list[4]);
      if (room.HasEntrance())
        Player::GetInstance()->SetPosition(x, y);
      this->rooms.push_back(room);
    }
}

int Maze::width() {
  return this->width_;
}

int Maze::height() {
  return this->height_;
}

const Room& Maze::GetRoom(int x, int y) {
  return this->rooms[x * height_ + y];
}
