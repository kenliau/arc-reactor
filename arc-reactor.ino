// This #include statement was automatically added by the Particle IDE.
#include "InternetButton/InternetButton.h"

InternetButton b = InternetButton();

bool rainbow_mode = false;
bool halloween_mode = false;
int number_of_leds = 11;

void setup() {
    // Tell b to get everything ready to go
    // Use b.begin(1); if you have the original SparkButton, which does not have a buzzer or a plastic enclosure
    // to use, just add a '1' between the parentheses in the code above.
    b.begin();
    
    lightsUp();
}

void loop(){

    if (b.buttonOn(1)) {

        rainbow_mode = true;
        b.rainbow(1);
        delay(1000);
        b.rainbow(2);
        delay(1000);
        b.rainbow(3);
        delay(1000);
        b.rainbow(4);
        delay(1000);
        b.rainbow(5);
        delay(1000);

        return;
    }

    if (b.buttonOn(2)) {

        halloween_mode = true;
        halloweenMode();
        delay(3000);

        return;
    }


    // If we are not in rainbow mode anymore, turn the LEDs off
    if (rainbow_mode == true || halloween_mode == true) {
        rainbow_mode = false;
        halloween_mode = false;
        lightsUp();
    }
}

void halloweenMode() {
    for (int i = 1; i <= number_of_leds; i++) {
        b.smoothLedOn(i, 241, 88, 2);
    }
    
    delay(1000);

    // Turn off unecessary LEDs
    b.ledOff(1);
    b.ledOff(3);
    b.ledOff(9);
    b.ledOff(11);    

    // Blinking green eyes and purple mouth
    for (int i = 1; i <= 100; i++) {
        
        // Close green eyes
        b.ledOff(2);
        b.ledOff(10);
        
        // Close purple mouth
        b.ledOff(4);
        b.ledOff(5);
        b.ledOff(6);
        b.ledOff(7);
        b.ledOff(8);
        
        delay(100);
        
        // Open green eyes
        b.ledOn(2, 27, 165, 44);
        b.ledOn(10, 27, 165, 44);
        
        // Open purple mouth
        b.ledOn(4, 124, 16, 173);
        b.ledOn(5, 124, 16, 173);
        b.ledOn(6, 124, 16, 173);
        b.ledOn(7, 124, 16, 173);
        b.ledOn(8, 124, 16, 173);
    }

}

void lightsUp() {
    for (int i = 1; i <= number_of_leds; i++) {
        b.smoothLedOn(i, 128, 128, 128);
    }
}