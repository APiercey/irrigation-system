#include "valve.h"

Valve::Valve(bool is_on) { on = is_on; }

void Valve::turn_on() { on = true; }
void Valve::turn_off() { on = false; }
bool Valve::is_on() { return on == true; }
bool Valve::is_off() { return on == false; }
