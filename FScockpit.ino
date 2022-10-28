#include "Joystick.h"

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

const byte btn1 = 2;
const byte btn2 = 3;
const byte btn3 = 5;
const byte btn4 = 6;
const byte sw1 = 7;
const byte DblSw1 = 8;
const byte DblSw2 = 9;

const byte Tbtn1 = 10;
const byte Tbtn2 = 16;
const byte Tbtn3 = 14;
const byte Tbtn4 = 15;


void setup()
{
    Joystick.begin();
    Serial.begin(9600);  
    
    //yoke buttons pinout
    pinMode(btn1, INPUT_PULLUP);
    pinMode(btn2, INPUT_PULLUP);
    pinMode(btn3, INPUT_PULLUP);
    pinMode(btn4, INPUT_PULLUP);
    pinMode(sw1, INPUT_PULLUP);
    pinMode(DblSw1, INPUT_PULLUP);
    pinMode(DblSw2, INPUT_PULLUP);
    
    //throttle buttons pinout
    pinMode(Tbtn1, INPUT_PULLUP);
    pinMode(Tbtn2, INPUT_PULLUP);
    pinMode(Tbtn3, INPUT_PULLUP);
    pinMode(Tbtn4, INPUT_PULLUP);
}   

void loop()
{
    AxisX = analogRead(A0); //assigning axis X for the yoke;
    AxisX = map(AxisX, 0, 1023, 0, 255);

    Joystick.setXAxis(AxisX);

    AxisY = analogRead(A1); //assigning axis Y for the yoke;
    AxisY = map(AxisY, 0, 1023, 0, 255);

    Joystick.setYAxis(AxisY);

    AxisRotationX = analogRead(A2); //assigning axis X rotation for the propeller pitch;
    AxisRotationX = map(AxisRotationX, 0, 1023, 0, 255);//ToDo: Actual pin layout for prop pitch;

    AxisRotationY = analogRead(A3); //assigning axis Y rotation for the AirToFuel Ratio/mixture;
    AxisRotationY = map(AxisRotationY, 0, 1023, 0, 255);//ToDo: Actual pin layout for mixture;

    AxisThrottle = analogRead(A4); //assigning axis Y rotation for the throttle;
    AxisThrottle = map(AxisThrottle, 0, 1023, 0, 255);//ToDo: Actual pin layout for throttle;

    delay(10); //delay 10ms to ensure read is correct and to give time for controller read;
    
}

void buttonCheck()
{
    byte btn1State;
    byte btn2State;
    byte btn3State;
    byte btn4State;
    byte sw1State;
    byte DblSw1State;
    byte DblSw2State;

    byte Tbtn1State;
    byte Tbtn2State;
    byte Tbtn3State;
    byte Tbtn4State;

    for (int i = 0; i < 11; i++)
    {
        
    }
    
}

