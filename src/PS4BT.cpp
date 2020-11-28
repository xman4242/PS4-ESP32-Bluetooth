#include "include/PS4BT.h"

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

int GetButtonClick(int button)
{   
    int PrevVal = PrevStates[button];
    int CurrentVal = ReturnButtonVal(button);

    if (CurrentVal == 0 && PrevVal == 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

int GetButtonPress(int button)
{
    return ReturnButtonVal(button);
}

int GetAnalogButton(int button)
{
    return ReturnButtonVal(button);
}

int GetStickRaw(int Stick)
{
    return ReturnStickValRaw(Stick);
}

int GetStick255(int Stick, int Deadzone)
{
    int retval = 0;

    if(GetStickRaw(Stick) > Deadzone || GetStickRaw(Stick) < (-1*Deadzone))
    {
        retval = (PS4.data.analog.stick.ly)*2;
    }

    else retval = 0;

    if(retval > 255) retval = 255;
    if(retval < -255) retval = -255;

}

int ReturnButtonVal(int ButtontoGet)
{       
    if(ButtontoGet == ButtonTriangle) return PS4HID.data.button.triangle;
    if(ButtontoGet == ButtonCircle) return PS4HIDdata.button.circle;
    if(ButtontoGet == ButtonCross) return PS4HID.data.button.cross;
    if(ButtontoGet == ButtonSquare) return PS4HID.data.button.square;
    if(ButtontoGet == UpArrow) return PS4HID.data.button.up;
    if(ButtontoGet == RightArrow) return PS4HID.data.button.right;
    if(ButtontoGet == DownArrow) return PS4HID.data.button.down;
    if(ButtontoGet == LeftArrow) return PS4HID.data.button.left;
    if(ButtontoGet == R1) return PS4HID.data.button.r1;
    if(ButtontoGet == L1) return PS4HID.data.button.l1;
    if(ButtontoGet == R2) return PS4HID.data.analog.button.r2;
    if(ButtontoGet == L2) return PS4HID.data.analog.button.l2;
    if(ButtontoGet == R3) return PS4HID.data.button.r3;
    if(ButtontoGet == L3) return PS4HID.data.button.l3;
    if(ButtontoGet == Share) return PS4HID.data.button.share;
    if(ButtontoGet == Options) return PS4HID.data.button.options;
    if(ButtontoGet ==PS) return PS4HID.data.button.ps;
    if(ButtontoGet == Touchpad) return PS4HID.data.button.touchpad;
        
}

int ReturnStickValRaw(int ValuetoGet)
{
    if (ValuetoGet == LeftStickY) return PS4HID.data.analog.stick.ly;
    if (ValuetoGet == RightStickY) return PS4HID.data.analog.stick.ry;
    if (ValuetoGet == LeftStickX) return PS4HID.data.analog.stick.lx;
    if (ValuetoGet == RightStickY) return PS4HID.data.analog.stick.rx;  

}

