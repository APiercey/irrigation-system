#ifndef VALVE_H
#define VALVE_H

class Valve {
public:
  bool on;

  Valve(bool is_on);

  void turn_on();
  void turn_off();
  bool is_on();
  bool is_off();
};

#endif
