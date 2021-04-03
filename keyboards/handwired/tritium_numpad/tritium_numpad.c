#include "tritium_numpad.h"
#include "led.h"

void keyboard_pre_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	keyboard_pre_init_user();
	led_init_ports();
};

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
};

void led_init_ports(void) {
    // * Set our LED pins as output
    // Layer 0 LED
    setPinOutput(B4);
    // Layer 1 LED
    setPinOutput(B5);
    // Layer 2 LED
    setPinOutput(B6);
    // Layer 3 LED
    setPinOutput(B3);
}

void led_set_kb(uint8_t usb_led) {
    if (IS_LAYER_ON(0)) {
        writePinHigh(B4);
    } else {
        writePinLow(B4);
    }
    if (IS_LAYER_ON(1)) {
        writePinHigh(B5);
    } else {
        writePinLow(B5);
    }
    if (IS_LAYER_ON(2)) {
        writePinHigh(B6);
    } else {
        writePinLow(B6);
    }
    if (IS_LAYER_ON(3)) {
        writePinHigh(B3);
    } else {
        writePinLow(B3);
    }
}
