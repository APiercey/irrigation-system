#include "time.h"
#include <board_manager.h>
#include <events.h>
#include <irrigation_system.h>
#include <system_manager.h>

SystemManagerService::SystemManagerService(IrrigationSystem irrigation_system_,
                                           BoardManager board_manager_)
    : irrigation_system(irrigation_system_), board_manager(board_manager_) {}

void SystemManagerService::stop() {}
void SystemManagerService::loop() {}

void SystemManagerService::start(time_t finish_at) {
  time_t now;
  time(&now);
  Event events[10];

  irrigation_system.set_schedule(now, finish_at);
  irrigation_system.monitor_schedule(events);

  for (Event event : events) {
    board_manager.consume_event(event);
  }
}
