/*
Authors:
- Oriol
- Pablo Arancibia Barahona
*/

#include "mbed.h"
 
DigitalIn enable(p17);
DigitalOut led(LED1);

int main()
{
    const int PULSE_MIN_TIME = 500;

    Timer pressTimer;
    bool stateEnable = false;

    while (true) {
        if (enable && !stateEnable){ // if enable is pressed and before was not pressed
            pressTimer.start();
            stateEnable = true;

        } else if (enable && stateEnable && pressTimer.read_ms() > PULSE_MIN_TIME){ // if is pressed for 0.5 sec
            pressTimer.stop();
            pressTimer.reset();
            led = !led;

        } else if (enable && !stateEnable){ // if enable is not pressed and before was pressed
            pressTimer.stop();
            pressTimer.reset();
            stateEnable = false;
        }
    }
}
