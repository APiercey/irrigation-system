#ifndef IRRIGATION_SYSTEM_H
#define IRRIGATION_SYSTEM_H
#include <schedule.h>
#include <valve.h>

class IrrigationSystem {
public:
  Schedule schedule;
  Valve valve;
  IrrigationSystem(Valve valve);

  void set_schedule(time_t start_time, time_t end_time);
  void monitor_schedule(Event *events);
  void stop();
};

#endif
