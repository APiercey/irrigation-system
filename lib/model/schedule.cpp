#include "time.h"
#include <schedule.h>

Schedule::Schedule(time_t start_time_, time_t end_time_) {
  start_time = start_time_;
  end_time = end_time_;
}

bool Schedule::on_schedule() {
  time_t now;
  time(&now);

  return now > start_time && now < end_time;
}

bool Schedule::expired() {
  time_t now;
  time(&now);

  return now > end_time;
}
