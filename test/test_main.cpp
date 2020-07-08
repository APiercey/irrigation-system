#include "time.h"
#include <Arduino.h>
#include <board.h>
#include <irrigation_system.h>
#include <unity.h>
#include <valve.h>

const int VALVE_PIN = 13;

time_t get_now() {
  time_t now;
  time(&now);

  return now;
}

time_t get_tomorrow() { return get_now() + 24 * 60 * 60; }
time_t get_yesterday() { return get_now() - 24 * 60 * 60; }

void test_irrigation_system_is_on(void) {
  IrrigationSystem irrigation_system =
      IrrigationSystem(get_tomorrow(), Valve(false));

  irrigation_system.monitor_schedule();

  TEST_ASSERT_EQUAL(irrigation_system.valve->on, true);
}

void test_irrigation_system_is_off(void) {
  IrrigationSystem irrigation_system =
      IrrigationSystem(get_yesterday(), Valve(false));

  irrigation_system.monitor_schedule();

  TEST_ASSERT_EQUAL(irrigation_system.valve->on, false);
}

void test_board_pin_turns_on(void) {
  IrrigationSystem irrigation_system =
      IrrigationSystem(get_tomorrow(), Valve(false));

  Board board = Board(13);

  TEST_ASSERT_EQUAL(irrigation_system.valve->on, false);
}

void setup() {
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
}

void loop() {
  RUN_TEST(test_irrigation_system_is_on);
  RUN_TEST(test_irrigation_system_is_off);
  UNITY_END(); // stop unit testing
}
