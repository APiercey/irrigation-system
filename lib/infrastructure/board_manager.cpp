#include <Arduino.h>
#include <board_manager.h>
#include <events.h>
#include <irrigation_system.h>

BoardManager::BoardManager(int pin) {
  valve_pin = pin;
  pinMode(valve_pin, OUTPUT);
}

void BoardManager::consume_event(ValveTurnedOn *event) {
  digitalWrite(valve_pin, HIGH);
}

void BoardManager::consume_event(ValveTurnedOff *event) {
  digitalWrite(valve_pin, HIGH);
}
