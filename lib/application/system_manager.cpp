#include "time.h"
#include <board_manager.h>
#include <commands.h>
#include <events.h>
#include <irrigation_system.h>
#include <system_manager.h>

SystemManagerService::SystemManagerService(IrrigationSystem irrigation_system_,
                                           BoardManager board_manager_)
    : irrigation_system(irrigation_system_), board_manager(board_manager_) {}

void SystemManagerService::stop() {
  Event events[2];

  irrigation_system.monitor_schedule(events);

  for (Event &event : events) {
    board_manager.consume_event(&event);
  }
}
void SystemManagerService::loop() {}

void SystemManagerService::start(time_t finish_at) {
  time_t now;
  time(&now);

  SetSchedule command = SetSchedule(now, finish_at);

  ScheduleChanged event = irrigation_system.execute(command);
  irrigation_system.apply(event);
}
