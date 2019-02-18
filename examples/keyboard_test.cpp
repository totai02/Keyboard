#include <wiringPi.h>
#include <PCD8544.h>
#include "keyboard.h"

using namespace std;

void showKeyboard();

int main()
{
    // init
    wiringPiSetup();
    LCDInit();
    
    Keyboard keyboard;
    keyboard.initPin();
    
    // test
    string text = keyboard.popup("Keyboard");
    LCDsetTinyFont(false);
    LCDdrawstring_P(0, 0, text.c_str());
    LCDdisplay();

    return 0;
}
