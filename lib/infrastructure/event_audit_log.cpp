#include <event_audit_log.h>
#include <events.h>
#define AUDIT_LOG_SIZE 10

EventAuditLog::EventAuditLog() {
  size = AUDIT_LOG_SIZE;
  Event future_events[AUDIT_LOG_SIZE] = {};
  event_log = future_events;
}

void EventAuditLog::log(Event &event) {}
Event *EventAuditLog::access(int access) { return &event_log[access]; }
