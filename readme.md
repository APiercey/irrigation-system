# Irrigation System

The irrigiation system is designed to work on the ESP32 (build on the DevBoard) and uses the Android framework.

## Current State
This is very much a work-in-progress. The idea is to leverage MQTT to push commands to the irrigation system.

### Architecture
The system is designed with the command-event pattern with the three key areas:
- lib/application: The application control layer. It uses the services from the `infrastructre` and `model` layer to control the system.
- lib/infrastructure: The infastructure layer. Services provided here can but used by the `application` layer and `setup()` function of the ESP32 board.
- lib/model: Pure domain logic. Classes and services are system agnostic and are designed to run _anywhere_. Commands come in and events come out with events being applied to change internal state.


The system workflow is described:
1. Command as raw data comes in from a MQTT topic
2. Data is passed into the application layer and is parsed into a command.
3. The command is executed by the IrrigationSystem (model layer).
4. On `loop()` the application layer requests for the model to monitor its internal state. Possibly returning events.
5. Events returned are applied to the model and passed onto the infrastructure layer to be processed.
6. The infrastrcture layer updates the board pins.
