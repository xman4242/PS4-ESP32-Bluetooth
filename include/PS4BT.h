#ifndef PS4BT_H
#define PS4BT_h
#include "src/PS4Controller.h"

class PS4Remote
{
private:
    PS4Controller PS4HID;
    int ReturnButtonVal(int ButtontoGet);
    int ReturnStickValRaw(int ValuetoGet);

public:
    //Begins the remtote bluetooth services
    bool Begin(char *mac);
    //Does nothing
    bool End();
    //Returns true if connected
    bool IsConnected();
    //Sets the LED on the PS4 controller
    void SetLed(int Red, int Green, int Blue);
    //Sets the rumble
    void SetRumble(int SmallMotor, int LargeMotor);
    //Sets the flashing time of the LED
    void SetFlashRate(int onTime, int offTime);
    //Sends all the above info to the controller
    void SendToController();
    //Returns true while the button is pressing
    int GetButtonPress(int button);
    //Only returns true the first time it is clicked
    int GetButtonClick(int button);
    //Returns true while the button is being held
    int GetButtonPress(int button);
    //Gets L2 or R2
    int GetAnalogButton(int button);
    //Gets the unmapped analog stick value
    int GetStickRaw(int Stick);
    //Gets the stick value and maps it from 0-255f with a deadzone. 10 is a good one to start with
    int GetStick255(int Stick, int Deadzone);

        int PrevStates[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        //Button Enumeration
        int ButtonTriangle = 0;
        int ButtonCircle = 1;
        int ButtonCross = 2;
        int ButtonSquare = 3;
        int Share = 4;
        int Options = 5;
        //Arrow Enumeration
        int UpArrow = 6;
        int RightArrow = 7;
        int DownArrow = 8;
        int LeftArrow = 9;
        //Trigger Enumeration
        int R1 = 10;
        int L1 = 11;
        int PS = 12;
        int Touchpad = 13;
        int R3 = 14; //Not really triggers, but the buttons under the joysticks
        int L3 = 15;
        //Stick Enumeration
        int LeftStickY = 24;
        int RightStickY = 25;
        int LeftStickX = 20;
        int RightStickX = 21;
        int R2 = 23;
        int L2 = 22;
        //Other
        
        
        



        
    
};

#endif