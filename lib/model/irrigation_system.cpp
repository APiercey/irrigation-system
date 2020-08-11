#include "time.h"
#include <commands.h>
#include <events.h>
#include <irrigation_system.h>
#include <schedule.h>
#include <valve.h>

IrrigationSystem::IrrigationSystem(Valve valve_)
    : valve(valve_), schedule(Schedule(0, 0)) {}

void IrrigationSystem::monitor_schedule(Event *events) {
  time_t now;
  time(&now);
  int event_count = 0;

  if (valve.is_off() && schedule.on_schedule()) {
    events[event_count++] = ValveTurnedOn(now);
  }

  if (valve.is_off() && schedule.expired()) {
    events[event_count++] = ValveTurnedOff(now);
  }
}

ScheduleChanged IrrigationSystem::execute(SetSchedule command) {
  return ScheduleChanged(command.start_time, command.end_time);
}

void IrrigationSystem::apply(ScheduleChanged event) {
  schedule = Schedule(event.start_time, event.end_time);
}

void IrrigationSystem::apply(ValveTurnedOn event) { valve.turn_on(); }
void IrrigationSystem::apply(ValveTurnedOff event) { valve.turn_off(); }
