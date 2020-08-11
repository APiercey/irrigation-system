#ifndef APPLICATION_H
#define APPLICATION_H
#include <system_manager.h>

class MessageHandler {
  SystemManagerService system_manager_service;

  MessageHandler(SystemManagerService system_manager_service_);
  void handle_message(char str[]);
};

#endif
