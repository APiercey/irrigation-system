#include "../../lib/time.cpp"
#include "time.h"
#include <irrigation_system.h>
#include <unity.h>
#include <valve.h>

const int VALVE_PIN = 13;

IrrigationSystem irrigiation_system_for_tomorrow() {
  return IrrigationSystem(get_tomorrow(), Valve(false));
}

IrrigationSystem irrigiation_system_for_yesterday() {
  return IrrigationSystem(get_yesterday(), Valve(false));
}

void test_irrigation_system_is_on(void) {
  IrrigationSystem irrigation_system = irrigiation_system_for_tomorrow();

  irrigation_system.monitor_schedule();

  TEST_ASSERT_EQUAL(irrigation_system.valve->on, true);
}

void test_irrigation_system_is_off(void) {
  IrrigationSystem irrigation_system = irrigiation_system_for_yesterday();

  irrigation_system.monitor_schedule();

  TEST_ASSERT_EQUAL(irrigation_system.valve->on, false);
}

int main(int argc, char **argv) {
  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_irrigation_system_is_on);
  RUN_TEST(test_irrigation_system_is_off);
  UNITY_END(); // stop unit testing
  return 0;
}
