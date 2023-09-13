#include "mbed.h"
 
DigitalIn enable(p17);
DigitalOut led(LED1);

Timer t;
int state = 0;
// 0 -> PIN 17 disabled
// 1 -> PIN 17 enabled for less than 0.5s
// 2 -> PIN 17 enabled for more than 0.5s

int main()
{
    while (true) {
        if (enable) {
            if (state == 0) {
                t.reset();
                t.start();
                state = 1;
            }
            if (state == 1 && t.read() > 0.5) {
                led = !led;
                t.stop();
                state = 2;
            }
        } else {
            state = 0;
        }
    }
}
