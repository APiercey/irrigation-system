#ifdef EMBEDDED
#include <Arduino.h>
#endif
#include <board_manager.h>

BoardManager::BoardManager(int valve_pin_) {
  valve_pin = valve_pin_;
#ifdef EMBEDDED
  digitalWrite(valve_pin, LOW);
#endif
}

void BoardManager::consume_event(ValveTurnedOn &event) {
#ifdef EMBEDDED
  digitalWrite(valve_pin, HIGH);
#endif
}

void BoardManager::consume_event(ValveTurnedOff &event) {
#ifdef EMBEDDED
  digitalWrite(valve_pin, LOW);
#endif
}
