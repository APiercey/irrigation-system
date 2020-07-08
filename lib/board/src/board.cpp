#include <Arduino.h>
#include <board.h>
#include <irrigation_system.h>

Board::Board(int valve_pin) {
  valve_pin = valve_pin;
  pinMode(valve_pin, OUTPUT);
}

void update_board(IrrigationSystem irrigation_system) {
  if (irrigation_system.valve->on) {
    digitalWrite(valve_pin, HIGH);
  } else {
    digitalWrite(valve_pin, LOW);
  }
}
