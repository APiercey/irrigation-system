#ifndef BOARD_H
#define BOARD_H
#include <events.h>

class BoardManager {
public:
  int valve_pin;

  BoardManager(int valve_pin);

  void consume_event(ValveTurnedOn &event);
  void consume_event(ValveTurnedOff &event);
};

#endif
