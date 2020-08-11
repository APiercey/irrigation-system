/* #include "../../lib/time.cpp" */
/* #include "time.h" */
/* #include <irrigation_system.h> */
/* #include "time.h" */
/* #include <board_manager.h> */
#include <events.h>
/* #include <tiny-json.h> */
#include <event_audit_log.h>
#include <unity.h>
/* #include <valve.h> */

/* IrrigationSystem irrigiation_system_for_tomorrow() { */
/*   return IrrigationSystem(get_tomorrow(), Valve(false)); */
/* } */

/* IrrigationSystem irrigiation_system_for_yesterday() { */
/*   return IrrigationSystem(get_yesterday(), Valve(false)); */
/* } */

/* void test_irrigation_system_is_on(void) { */
/*   IrrigationSystem irrigation_system = irrigiation_system_for_tomorrow(); */

/*   irrigation_system.monitor_schedule(); */

/*   TEST_ASSERT_EQUAL(irrigation_system.valve->on, true); */
/* } */

/* void test_irrigation_system_is_off(void) { */
/*   IrrigationSystem irrigation_system = irrigiation_system_for_yesterday(); */

/*   irrigation_system.monitor_schedule(); */

/*   TEST_ASSERT_EQUAL(irrigation_system.valve->on, false); */
/* } */

/* void test_json(void) { */
/*   enum { MAX_FIELDS = 4 }; */
/*   json_t pool[MAX_FIELDS]; */

/*   char str[] = "{ \"name\": \"peter\", \"age\": 32 }"; */

/*   json_t const *parent = json_create(str, pool, MAX_FIELDS); */
/*   json_t const *namefield = json_getProperty(parent, "name"); */
/*   char const *namevalue = json_getValue(namefield); */

/*   TEST_ASSERT_EQUAL(*"peter", *namevalue); */
/* } */

/* void test_fake_board_manager(void) { */
/*   BoardManager board_manager = BoardManager(0); */
/*   ScheduleChanged event = ScheduleChanged(0, 0); */
/*   ScheduleChanged *ptr = *event; */
/*   ScheduleChanged &rfe = event; */

/*   board_manager.consume_event(ptr); */
/* } */

void test_audit_log_starts_empty(void) {
  EventAuditLog eal = EventAuditLog();

  int num_events = 0;

  for (auto &event : eal.event_log) {
    if (event != NULL) {
      num_events++;
    }
  }

  TEST_ASSERT_EQUAL(num_events, 0);
}

int main(int argc, char **argv) {
  UNITY_BEGIN(); // IMPORTANT LINE!
  /* RUN_TEST(test_irrigation_system_is_on); */
  /* RUN_TEST(test_json); */
  /* RUN_TEST(test_fake_board_manager); */
  /* RUN_TEST(test_irrigation_system_is_off); */
  UNITY_END(); // stop unit testing
  return 0;
}
