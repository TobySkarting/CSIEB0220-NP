#ifndef PLAYER_H
#define PLAYER_H

class Player {
 public:
  static Player *GetInstance();

  Player();

  void SetPosition(int x, int y);
  bool MoveUp();
  bool MoveDown();
  bool MoveLeft();
  bool MoveRight();

  int x() const;
  int y() const;

 private:
  static Player *instance_;

  char symbol_;
  int x_;
  int y_;
};

#endif
