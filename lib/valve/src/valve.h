#ifndef VALVE_H
#define VALVE_H

class Valve {
public:
  Valve(bool is_on);
  void turn_on();
  void turn_off();
  bool on;
};

#endif
