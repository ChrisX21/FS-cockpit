#include "Joystick.h"

#define BUTTON_COUNT 11

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
        11, 0,
        true, true, false,
        true, true, false,
        false, true,
        false, false, false);

int AxisX = 0;
int AxisY = 0;
int AxisRotationX = 0;
int AxisRotationY = 0;
int AxisThrottle = 0;

byte buttonPins[BUTTON_COUNT] = 
{
    2, 3, 5, 6, 7, 8, 9, 10, 16, 14, 15
};

void setup()
{
    Joystick.begin();
    Serial.begin(9600);  
    
    for (byte i = 0; i < BUTTON_COUNT; i++)
        pinMode(buttonPins[i], INPUT_PULLUP);  
}   

void loop()
{
    readButtonStates();

    AxisX = analogRead(A0); //assigning axis X for the yoke;
    AxisX = map(AxisX, 0, 1023, 0, 255);

    Joystick.setXAxis(AxisX);

    AxisY = analogRead(A1); //assigning axis Y for the yoke;
    AxisY = map(AxisY, 0, 1023, 0, 255);

    Joystick.setYAxis(AxisY);

    AxisRotationX = analogRead(A2); //assigning axis X rotation for the propeller pitch;
    AxisRotationX = map(AxisRotationX, 0, 1023, 0, 255);//ToDo: Actual pin layout for prop pitch;

    Joystick.setRxAxis(AxisRotationX);

    AxisRotationY = analogRead(A3); //assigning axis Y rotation for the AirToFuel Ratio/mixture;
    AxisRotationY = map(AxisRotationY, 0, 1023, 0, 255);//ToDo: Actual pin layout for mixture;
    
    Joystick.setRyAxis(AxisRotationY);
    
    AxisThrottle = analogRead(A4); //assigning axis Y rotation for the throttle;
    AxisThrottle = map(AxisThrottle, 0, 1023, 0, 255);//ToDo: Actual pin layout for throttle;

    Joystick.setThrottle(AxisThrottle);
    
    delay(10); //delay 10ms to ensure read is correct and to give time for controller read;
}

void readButtonStates()
{
    for (int i = 0; i < BUTTON_COUNT; i++)
    {
        int state = digitalRead(buttonPins[i]);
        Joystick.setButton(i, !state);
    }
}
