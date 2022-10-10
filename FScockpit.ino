#include "Joystick.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
        16, 0,
        true, true, false,
        false, false, false,
        false, false,
        false, false, false);

int AxisX = 0;
int AxisY = 0;

void setup()
{
    Joystick.begin();
    Serial.begin(9600);    
}   

void loop()
{
    AxisX = analogRead(A0); //assigning axis X for the yoke;
    AxisX = map(AxisX, 0, 1023, 0, 255);

    Joystick.setXAxis(AxisX);

    AxisY = analogRead(A1); //assigning axis Y for the yoke;
    AxisY = map(AxisY, 0, 1023, 0, 255);

    Joystick.setYAxis(AxisY);

    delay(5); //delay 5 ms to ensure read is correct and to give time;
}

void buttons()
{
    byte yokeButtons[] = {1, 2, 3, 5, 6, 7, 8};
}

void throttle()
{
    byte throttleButtons[] = {9, 14, 15, 16};
    
}
