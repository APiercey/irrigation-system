#include "../../lib/time.cpp"
#include <Arduino.h>
#include <board.h>
#include <irrigation_system.h>
#include <unity.h>

const int VALVE_PIN = 13;

IrrigationSystem irrigiation_system_for_tomorrow() {
  return IrrigationSystem(get_tomorrow(), Valve(false));
}

IrrigationSystem irrigiation_system_for_yesterday() {
  return IrrigationSystem(get_yesterday(), Valve(false));
}

void test_board_start_with_pin_low(void) {
  Board board = Board(13);

  TEST_ASSERT_EQUAL(LOW, digitalRead(13));
}

void test_board_pin_turns_on(void) {
  Board board = Board(13);

  IrrigationSystem irrigation_system = irrigiation_system_for_tomorrow();

  irrigation_system.monitor_schedule();

  board.update_board(irrigation_system);

  TEST_ASSERT_EQUAL(HIGH, digitalRead(13));
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  Serial.begin(115200);
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
}

void loop() {
  RUN_TEST(test_board_start_with_pin_low);
  RUN_TEST(test_board_pin_turns_on);
  UNITY_END(); // stop unit testing
}
