#ifndef PS4_H
#define PS4_H
#include "PS4Controller.h"

class PS4Remote
{
private:
    PS4Controller PS4HID;
public:
    //Begins the remtote bluetooth services
    bool Begin();
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
    bool GetButtonPress(int button);
    //Only returns true the first time it is clicked
    bool GetButtonClick(int button);
    //Gets L2 or R2
    int GetAnalogButton(int button);
    //Gets the unmapped analog stick value
    int16_t GetStick(int Stick);
    //Gets the stick value and maps it from 0-255f
    int GetStick255(int Stick);

        
    
};

#endif