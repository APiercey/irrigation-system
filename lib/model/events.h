#include "time.h"
class Event {};

class ValveTurnedOn : public Event {
public:
  time_t turned_on_at;

  ValveTurnedOn(time_t turned_on_at);
};

class ValveTurnedOff : public Event {
public:
  time_t turned_off_at;

  ValveTurnedOff(time_t turned_off_at);
};

class ScheduleChanged : public Event {
public:
  time_t start_time;
  time_t end_time;

  ScheduleChanged(time_t start_time, time_t end_time);
};
