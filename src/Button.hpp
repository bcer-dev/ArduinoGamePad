#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <Printable.h>
#include "ButtonAction.hpp"

using uint = unsigned int;

namespace GamePad
{
    // The Button class is a container buttons and button functionality.
    // Each Button will have a ButtonAction which just keeps track of whether
    // the Button's purpose is JUMP, LEFT, or RIGHT which will be useful for 
    // making games using this GamePad. Buttons also require a pin from which they
    // will check if the physical push button is pressed.
    // On instantiation, the Button will set the given pin to INPUT.
    class Button : public Printable
    {
    private:
        ButtonAction action;
        uint pin;

    public:
        Button(ButtonAction name, uint pin);
        bool Pressed() const;
        size_t printTo(Print& p) const;
    };
}

#endif // BUTTON_HPP