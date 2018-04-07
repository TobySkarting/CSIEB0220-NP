#ifndef ROOM_H
#define ROOM_H

class Room {
 public:
  enum WallType : short {
    kNothing,
    kWall,
    kEmpty,
    kExit,
    kEntrance,
  };

  Room(short top, short left, short right, short bottom, short reserved);

  bool HasEntrance();

  short top_wall() const;
  short left_wall() const;
  short right_wall() const;
  short bottom_wall() const;
  short reserved();

 private:
  short top_wall_;
  short left_wall_;
  short right_wall_;
  short bottom_wall_;
  short reserved_;

};

#endif
