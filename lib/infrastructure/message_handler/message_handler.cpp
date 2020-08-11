#include "tiny-json.h"
#include <message_handler.h>

MessageHandler::MessageHandler(SystemManagerService sms)
    : system_manager_service(sms) {}

void MessageHandler::handle_message(char str[]) {
  enum { MAX_FIELDS = 4 };
  json_t pool[MAX_FIELDS];
  json_t const *parent = json_create(str, pool, MAX_FIELDS);
  json_t const *cmdfield = json_getProperty(parent, "cmd");

  char const *cmdvalue = json_getValue(cmdfield);

  switch (*cmdvalue) {
  case * "STRT":
    json_t const *strtfield = json_getProperty(parent, "cmd");

    char const *strtvalue = json_getValue(strtfield);
    system_manager_service.start();
  }
}
