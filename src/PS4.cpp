#include "PS4.h"

bool PS4Remote::Begin()
{
    PS4HID.begin();
}

bool PS4Remote::Begin(char *mac)
{
    PS4HID.begin(mac);
}

bool PS4Remote::End()
{
    PS4HID.end();
}

bool PS4Remote::IsConnected()
{
    return PS4HID.isConnected();
}
void PS4Remote::SetLed(int Red. int Green, int Blue)
{
    PS4HID.setLed(Red, Green, Blue);
}

void PS4Remote::SetRumble(int SmallMotor, int LargeMotor)
{
    PS4HID.setRumble(SmallMotor,LargeMotor);
}

void PS4Remote::SetFlashRate(int onTime, int offTime)
{
    PS4HID.setFlashRate(onTime,offTime);
}

void PS4Remote::SendToController()
{
    PS4HID.sendToController();
}

