#include "mbed.h"

DigitalOut led1(LED1);
AnalogIn sensor(A0);

int main() {
    // Setup
    int distance = 0;
    
    // Loop
    while (true) {
        float volts = sensor.read() * 0.0048828125;
        int newDistance = 13 * pow(volts, -1);
        // Motion tolerance = 3%
        if (newDistance < (distance * 0.97) || newDistance > (distance * 1.03)) {
            led1 = 1;
            distance = newDistance;
        }
        else {
            led1 = 0;
        }
        wait(0.1);
    }
}

