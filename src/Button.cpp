#include "Button.hpp"
#include <Arduino.h>
using namespace GamePad;

// Tells the button which pin and action are assigned to it.
// If an invalid action is passed, it will default to LEFT.
Button::Button(ButtonAction action, uint pin) : action(action), pin(pin)
{
    pinMode(pin, INPUT);
    
    if (action > ButtonAction::JUMP)
    {
        action = (ButtonAction)0;
    }
}

// Returns whether or not there is voltage at this buttons assigned pin.
bool Button::Pressed() const
{
    return digitalRead(pin);
}

// Allow Button to be printed to Serial
// Writes the first letter of its action
size_t Button::printTo(Print& p) const
{
    char buf;
    switch (action)
    {
    case ButtonAction::LEFT:
        buf = 'L';
        break;
    
    case ButtonAction::RIGHT:
        buf = 'R';
        break;

    case ButtonAction::JUMP:
        buf = 'J';
        break;

    default:
        buf = '0'; // Invalid
        break;
    }

    return p.print(buf);
}
