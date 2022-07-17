#include <Arduino.h>
#include "Button.hpp"

#define PIN_JUMP    2
#define PIN_RIGHT   3
#define PIN_LEFT    4

const GamePad::Button LEFT
{
    GamePad::ButtonAction::LEFT,
    PIN_LEFT
};

const GamePad::Button RIGHT
{
    GamePad::ButtonAction::RIGHT,
    PIN_RIGHT
};

const GamePad::Button JUMP
{
    GamePad::ButtonAction::JUMP,
    PIN_JUMP
};

// If button is pressed then write it to serial
void PrintIfPressed(const GamePad::Button& button);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    PrintIfPressed(LEFT);
    PrintIfPressed(RIGHT);
    PrintIfPressed(JUMP);
}

void PrintIfPressed(const GamePad::Button& button)
{
    if (!button.Pressed())
        return;
    Serial.print(button);
}