#include "time.h"
#include <events.h>

ValveTurnedOn::ValveTurnedOn(time_t turned_on_at_)
    : turned_on_at(turned_on_at_) {}

ValveTurnedOff::ValveTurnedOff(time_t turned_off_at_)
    : turned_off_at(turned_off_at_) {}

ScheduleChanged::ScheduleChanged(time_t start_time_, time_t end_time_)
    : start_time(start_time_), end_time(end_time_) {}
