#ifndef IRRIGATION_SYSTEM_H
#define IRRIGATION_SYSTEM_H
#include <commands.h>
#include <schedule.h>
#include <valve.h>

class IrrigationSystem {
public:
  Schedule schedule;
  Valve valve;
  IrrigationSystem(Valve valve);

  ScheduleChanged execute(SetSchedule command);
  void apply(ScheduleChanged event);
  void apply(ValveTurnedOn event);
  void apply(ValveTurnedOff event);
  void monitor_schedule(Event *events);
};

#endif
