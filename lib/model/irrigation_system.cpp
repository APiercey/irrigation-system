#include "time.h"
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
    valve.turn_on();
    events[event_count++] = SystemTurnedOn(now);
  }

  if (valve.is_off() && schedule.expired()) {
    valve.turn_off();
    events[event_count++] = SystemTurnedOff(now);
  }
}

void IrrigationSystem::set_schedule(time_t start_time, time_t end_time) {
  schedule = Schedule(start_time, end_time);
}

void IrrigationSystem::stop() { set_schedule(0, 0); }
