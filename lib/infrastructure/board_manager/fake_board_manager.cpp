#ifdef NATIVE
#include <board_manager.h>

String event_names[10];
int num_events = 0;

BoardManager::BoardManager(int _valve) {}

void BoardManager::consume_event(ValveTurnedOn &event) {
  events_names[num_events++] = "ValveTurnedOn";
}

void BoardManager::consume_event(ValveTurnedOff &event) {
  events_names[num_events++] = "ValveTurnedOff";
}

String[] BoardManager::get_event_names() { return events_names; }
#endif
