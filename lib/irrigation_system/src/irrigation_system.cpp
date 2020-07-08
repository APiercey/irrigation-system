#include "time.h"
#include <irrigation_system.h>

IrrigationSystem::IrrigationSystem(time_t datetime, Valve _valve) {
  // Setup IrrigationSystem
  turn_off_at = datetime;
  valve = &_valve;
}

void IrrigationSystem::monitor_schedule() {
  if (on_schedule()) {
    valve->turn_on();
  } else {
    valve->turn_off();
  }
}

bool IrrigationSystem::on_schedule() {
  time_t now;
  double diff_in_seconds;

  time(&now);

  diff_in_seconds = difftime(now, turn_off_at);
  return diff_in_seconds < 0;
}
