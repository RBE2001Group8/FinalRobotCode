#include "UserButton.h"

UserButton::UserButton(int pin) : BUTTON_PIN(pin) {

}

void UserButton::initialize() {
	pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool UserButton::isPressed() {
	return !digitalRead(BUTTON_PIN);
}

bool UserButton::isDoublePressed() {
	return false;
}
