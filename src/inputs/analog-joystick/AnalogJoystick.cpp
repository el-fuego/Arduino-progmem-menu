#include <Arduino.h>
#include "./AnalogJoystick.h"


namespace Menu {
  #define JOYSTICK_LONG_PRESS_TIMEOUT 500
  #define JOYSTICK_PIN_HIGH_VALUE 800
  #define JOYSTICK_PIN_LOW_VALUE 200


  AnalogJoystickInput::AnalogJoystickInput(uint8_t _pinX, uint8_t _pinY) : pinX(_pinX), pinY(_pinY) {};
  AnalogJoystickInput::AnalogJoystickInput(uint8_t _pinX, uint8_t _pinY, boolean _isXInverted) : pinX(_pinX), pinY(_pinY), isXInverted(_isXInverted){};
  AnalogJoystickInput::AnalogJoystickInput(uint8_t _pinX, uint8_t _pinY, boolean _isXInverted, boolean _isYInverted) : pinX(_pinX), pinY(_pinY), isXInverted(_isXInverted), isYInverted(_isYInverted){};

  void AnalogJoystickInput::init() {
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
  };


  /**
  * Get behaviour action.
  * Return single action per JOYSTICK_LONG_PRESS_TIMEOUT (without this, slow single press can be recognized as multiple pressing)
  * Return action continuously, if pressed more then JOYSTICK_LONG_PRESS_TIMEOUT
  */
  INPUT_ACTION AnalogJoystickInput::getAction() {
    INPUT_ACTION currentAction = readRawAction();
    unsigned long currentTime = millis();
    if (updatedAt > currentTime) {
      updatedAt = 0;
    }

    // single press
    if (currentAction != previousAction) {
      updatedAt = currentTime;
      previousAction = currentAction;
      return currentAction;
    }

    // long press
    if (currentTime - updatedAt > JOYSTICK_LONG_PRESS_TIMEOUT) {
      return currentAction;
    }

    return INPUT_ACTION::NONE;
  };

  /**
  * Convert pin values to current behaviour action
  */
  INPUT_ACTION AnalogJoystickInput::readRawAction() {
    int valueX = analogRead(pinX);
    if (valueX > JOYSTICK_PIN_HIGH_VALUE) {
      return isXInverted ? INPUT_ACTION::LEFT : INPUT_ACTION::RIGHT;
    }

    if (valueX < JOYSTICK_PIN_LOW_VALUE) {
      return isXInverted ? INPUT_ACTION::RIGHT : INPUT_ACTION::LEFT;
    }

    int valueY = analogRead(pinY);
    if (valueY > JOYSTICK_PIN_HIGH_VALUE) {
      return isYInverted ? INPUT_ACTION::UP : INPUT_ACTION::DOWN;
    }

    if (valueY < JOYSTICK_PIN_LOW_VALUE) {
      return isYInverted ? INPUT_ACTION::DOWN : INPUT_ACTION::UP;
    }

    return INPUT_ACTION::NONE;
  };


  /**
  * Run behaviour with some action
  * Return {bool} has updates
  */
  bool AnalogJoystickInput::navigate(Menu* menu) {
    return navigateWithFourButtons(getAction(), menu);
  };

  bool AnalogJoystickInput::navigate(NumberField* numberField) {
    return navigateWithFourButtons(getAction(), numberField);
  };

  bool AnalogJoystickInput::navigate(TextField* textField) {
    return navigateWithFourButtons(getAction(), textField);
  };

};
