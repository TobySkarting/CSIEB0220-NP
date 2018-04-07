#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "maze.h"
#include "room.h"
#include "player.h"

using namespace std;

enum Direction {
  kUp,
  kLeft,
  kRight,
  kDown,
  kUnknown
};

/*
 ___ ___    
|    ___|   |
|   |___    |
|___ ___ ___|

 */
std::ostream& operator<<(std::ostream &os, Maze &maze) {
  const Player *player = Player::GetInstance();
  os << "width: " << maze.width() << " height: " << maze.height() << endl;
  for (int i = 0; i < maze.width(); ++i) {
    auto r = maze.GetRoom(0, i);
    if (r.top_wall() == Room::kWall)
      os << " ___";
    else if (r.top_wall() == Room::kEntrance)
      os << " _A_";
    else if (r.top_wall() == Room::kExit)
      os << " _B_";
    else
      os << "    ";
  }
  cout << endl;
  for (int x = 0; x < maze.height(); ++x) {
    for (int y = 0; y < maze.width(); ++y) {
      auto r = maze.GetRoom(x, y);
      // if left
      if (y == 0) {
        if (r.left_wall() == Room::kWall)
          os << "|";
        else if (r.left_wall() == Room::kEntrance)
          os << "A";
        else if (r.left_wall() == Room::kExit)
          os << "B";
        else
          os << " ";
      }
      if (r.bottom_wall() == Room::kWall)
        if (x == player->x() && y == player->y())
          os << "_*_";
        else
          os << "___";
      else
        if (x == player->x() && y == player->y())
          os << " * ";
        else
          os << "   ";
      if (r.right_wall() == Room::kWall)
        os << "|";
      else if (r.right_wall() == Room::kEntrance)
        os << "A";
      else if (r.right_wall() == Room::kExit)
        os << "B";
      else
        os << " ";
    }
    os << endl;
  }
  return os;
}

void PrintMaze() {
  cout << *Maze::GetInstance() << endl;
  cout << "Your move: ";
}

void PrintHelp() {
  cout << "Usage: mymaze -f file" << endl;
  cout << "How to play: " << endl;
  cout << "  You can use 1 or W to move up, 2 or A to move left, " << endl;
  cout << "  3 or D to move right, and 4 or S to move down." << endl;
}

void FlushScreen() {
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

short GetDirection(char key) {
  switch (key) {
    case '1': case 'w': case 'W': // go up
      return kUp;
    case '2': case 'a': case 'A': // go left
      return kLeft;
    case '3': case 'd': case 'D': // go right
      return kRight;
    case '4': case 's': case 'S': // go down
      return kDown;
  }
  return kUnknown;
}

bool CheckExit(short move, const Room &room) {
  switch (move) {
    case kUp:
      if (room.top_wall() == Room::kExit)
        return true;
      break;
    case kLeft:
      if (room.left_wall() == Room::kExit)
        return true;
      break;
    case kRight:
      if (room.right_wall() == Room::kExit)
        return true;
      break;
    case kDown:
      if (room.bottom_wall() == Room::kExit)
        return true;
      break;
  }
  return false;
}

bool HandleMove(short move) {
  switch (move) {
    case kUp:
      return Player::GetInstance()->MoveUp();
      break;
    case kLeft:
      return Player::GetInstance()->MoveLeft();
      break;
    case kRight:
      return Player::GetInstance()->MoveRight();
      break;
    case kDown:
      return Player::GetInstance()->MoveDown();
      break;
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> params;
  for (int i = 1; i < argc; ++i)
    params.push_back(argv[i]);
  
  try {
    if (params.size() == 0) {
      cout << "Use '-h' to display help" << endl;
      return 1;
    }
    if (std::find(params.begin(), params.end(), "-h") != params.end()) {
      PrintHelp();
      return 1;
    }
    auto iter = std::find(params.begin(), params.end(), "-f");
    if (iter == params.end() || ++iter == params.end()) {
      cout << "no input file";
      return -1;
    }
    string filename = *iter;
    Maze::GetInstance()->LoadMaze(filename);
  } catch (std::exception &e) {
    cerr << "fatal error: " << e.what() << endl;
    return -1;
  }

  FlushScreen();
  PrintMaze();
  char key;
  while (cin >> key) {
    FlushScreen();
    short direction = GetDirection(key);
    const Room &room = Maze::GetInstance()->GetRoom(Player::GetInstance()->x(), Player::GetInstance()->y());
    if (CheckExit(direction, room)) {
      cout << "You have finished the maze." << endl;
      break;
    }
    if (!HandleMove(direction))
      cout << "Invalid movement. Please try again.";
    PrintMaze();
  }
  cout << "Press enter to exit." << endl;
  cin.ignore();
  cin.get();
  return 0;
}
