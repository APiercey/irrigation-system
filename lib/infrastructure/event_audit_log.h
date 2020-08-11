#ifndef EVENT_AUDIT_LOG_H
#define EVENT_AUDIT_LOG_H
#include <events.h>

class EventAuditLog {
public:
  Event *event_log;
  int size;

  EventAuditLog();

  void log(Event &event);
  Event *access(int index);
};

#endif
