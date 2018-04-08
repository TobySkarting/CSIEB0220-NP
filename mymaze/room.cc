#include "room.h"

Room::Room(short top, short left, short right, short bottom, short reserved) 
    : top_wall_(top), left_wall_(left), right_wall_(right), bottom_wall_(bottom), reserved_(reserved) {

}

short Room::top_wall() const {
  return this->top_wall_;
}

short Room::left_wall() const {
  return this->left_wall_;
}

short Room::right_wall() const {
  return this->right_wall_;
}

short Room::bottom_wall() const {
  return this->bottom_wall_;
}

short Room::reserved() {
  return this->reserved_;
}

bool Room::HasEntrance() {
  return (this->top_wall_ == Room::kEntrance || this->bottom_wall_ == Room::kEntrance
          || this->left_wall_== Room::kEntrance || this->right_wall_ == Room::kEntrance);
}
