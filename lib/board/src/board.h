#ifndef BOARD_H
#define BOARD_H

class Board {
public:
  Board(int valve_pin);
  int valve_pin;
  void update_board(IrrigationSystem irrigation_system);
};

#endif
