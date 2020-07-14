class Event {};

class ValveTurnedOn : Event {
  time_t turned_on_at;

  ValveTurnedOn(time_t turned_on_at);
};

class ValveTurnedOff : Event {
  time_t turned_off_at;

  ValveTurnedOff(time_t turned_off_at);
};
