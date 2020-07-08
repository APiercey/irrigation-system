#ifndef IRRIGATION_SYSTEM_H
#define IRRIGATION_SYSTEM_H

#include "time.h"
#include <valve.h>

class IrrigationSystem {
public:
  IrrigationSystem(time_t turn_off_at, Valve valve);
  Valve *valve;

  void monitor_schedule();

private:
  time_t turn_off_at;

  bool on_schedule();
};

#endif
