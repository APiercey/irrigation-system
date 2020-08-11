#ifndef COMMANDS_H
#define COMMANDS_H
class Command {};

class SetSchedule : public Command {
public:
  time_t start_time;
  time_t end_time;

  SetSchedule(time_t start_time, time_t end_time);
};
#endif
