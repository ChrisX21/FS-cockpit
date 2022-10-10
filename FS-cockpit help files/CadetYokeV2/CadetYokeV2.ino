#include <Keypad.h>
#include <Joystick.h> //MAKE SURE YOU HAVE THE CORRECT JOYSTICK LIBRARY

//Joystick Setup
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK,
  16, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X, Y, but no Z Axis
  false, false, false,     // Rx, Ry, or No Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering;
  
int xAxis_ = 0;
int yAxis_ = 0;                 

const byte ROWS = 5; //four rows
const byte COLS = 7; //four columns

//define the symbols on the buttons of the keypads
char buttons[ROWS][COLS] = {
  {0, 1, 2, 3, 4, 16, 16}, //16s are placeholders
  {5, 6, 7, 8, 9, 16, 16},
  {16, 16, 16, 16, 16, 10, 11},
  {16, 16, 16, 16, 16, 12, 13},
  {16, 16, 16, 16, 16, 14, 15},

};
byte rowPins[ROWS] = {2, 3, 4, 5, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 8, 9, 10, 14, 15, 16}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad yokeButtons = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600); //Start serial monitoring
  Joystick.begin(); //Starts joystick
}
  
void loop(){
  checkButtons();
  
  xAxis_ = analogRead(A0);
  xAxis_ = map(xAxis_,0,1023,0,255);
  Joystick.setXAxis(xAxis_);
  
  yAxis_ = analogRead(A1);
  yAxis_ = map(yAxis_,0,1023,0,255);
  Joystick.setYAxis(yAxis_);

  delay(10);
}

void checkButtons(void) {
  if (yokeButtons.getKeys())
  {
    for (int i=0; i<LIST_MAX; i++)   
        {
           if (yokeButtons.key[i].stateChanged )   
            {
            switch (yokeButtons.key[i].kstate) {  
                    case PRESSED:
                    case HOLD:
                              Joystick.setButton(yokeButtons.key[i].kchar, 1);
                              break;
                    case RELEASED:
                    case IDLE:
                              Joystick.setButton(yokeButtons.key[i].kchar, 0);
                              break;
            }
            }
        }
  }
}
