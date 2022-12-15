#include <Joystick.h>

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
        
    for (byte i = 0; i < BUTTON_COUNT; i++)
        pinMode(buttonPins[i], INPUT_PULLUP);  

    Joystick.setXAxisRange(0, 1023);
    Joystick.setYAxisRange(0, 1023);
    Joystick.setRxAxisRange(0,1023);
    Joystick.setRyAxisRange(0, 1023);
}   

void loop()
{
    readButtonStates();
    //main controls (yoke):
    AxisX = analogRead(A0); //assigning axis X for the yoke;
    Joystick.setXAxis(AxisX);

    AxisY = analogRead(A1); //assigning axis Y for the yoke;
    Joystick.setYAxis(AxisY);

    //throttle quadrant:
    AxisThrottle = analogRead(A2); //assigning axis for throttle;
    Joystick.setThrottle(AxisThrottle);

    AxisRotationX = analogRead(A3); //assigning axis for AirToFuel Ratio/Mixture;
    Joystick.setRxAxis(AxisRotationX);

    //AxisRotationY = analogRead(A4); //assgning axis for prop angle;
    //Joystick.setRyAxis(AxisRotationY);
    
    delay(10); //delay 10ms to ensure read is correct and to give time for controller read to be complete;
}

void readButtonStates()
{
    for (int i = 0; i < BUTTON_COUNT; i++)
    {
        int state = digitalRead(buttonPins[i]);
        Joystick.setButton(i, !state);
    }
}
//Made by Kristiyan Aleksiev
