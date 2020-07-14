#ifndef SCHEDULE_H
#define SCHEDULE_H
class Schedule {
public:
  time_t start_time;
  time_t end_time;

  Schedule(time_t start_time, time_t end_time);

  bool on_schedule();
  bool expired();
};
#endif
