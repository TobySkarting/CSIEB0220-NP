#include "player.h"
#include "maze.h"

Player *Player::instance_ = nullptr;

Player *Player::GetInstance() {
  if (Player::instance_ == nullptr)
    Player::instance_ = new Player;
  return Player::instance_;
}

Player::Player() : symbol_('*') {

}

int Player::x() const {
  return this->x_;
}

int Player::y() const {
  return this->y_;
}

void Player::SetPosition(int x, int y) {
  this->x_ = x;
  this->y_ = y;
}

bool Player::MoveUp() {
  const Room &room = Maze::GetInstance()->GetRoom(this->x_, this->y_);
  if (room.top_wall() == Room::kEmpty) {
    --this->x_;
    return true;
  }
  return false;
}

bool Player::MoveDown() {
  const Room &room = Maze::GetInstance()->GetRoom(this->x_, this->y_);
  if (room.bottom_wall() == Room::kEmpty) {
    ++this->x_;
    return true;
  }
  return false;
}

bool Player::MoveLeft() {
  const Room &room = Maze::GetInstance()->GetRoom(this->x_, this->y_);
  if (room.left_wall() == Room::WallType::kEmpty) {
    --this->y_;
    return true;
  }
  return false;
}

bool Player::MoveRight() {
  const Room &room = Maze::GetInstance()->GetRoom(this->x_, this->y_);
  if (room.right_wall() == Room::kEmpty) {
    ++this->y_;
    return true;
  }
  return false;
}
