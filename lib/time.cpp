#include "time.h"

#ifndef TIME_CPP
#define TIME_CPP

time_t get_now() {
  time_t now;
  time(&now);

  return now;
}

time_t get_tomorrow() { return get_now() + 24 * 60 * 60; }
time_t get_yesterday() { return get_now() - 24 * 60 * 60; }

#endif
