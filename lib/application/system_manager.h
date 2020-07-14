#ifndef SYSTEM_MANAGER_SERVICE_H
#define SYSTEM_MANAGER_SERVICE_H

class SystemManagerService {
public:
  SystemManagerService(IrrigationSystem irrigiation_system,
                       BoardManager board_manager);
  void start(time_t finish_at);
  void loop();
  void stop();

private:
  IrrigationSystem irrigation_system;
  BoardManager board_manager;
}

#endif
