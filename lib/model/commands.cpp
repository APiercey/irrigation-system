#include "time.h"
#include <commands.h>

SetSchedule::SetSchedule(time_t start_time_, time_t end_time_)
    : start_time(start_time_), end_time(end_time_) {}
