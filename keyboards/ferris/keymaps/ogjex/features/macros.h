// macros.h
#ifndef MACROS_H
#define MACROS_H

#include QMK_KEYBOARD_H

// Add any other necessary includes here

// Declare variables related to macros
enum {
    M_QUES = SAFE_RANGE
};

//uint16_t key_timer;

// Declare functions related to macros
bool process_record_user(uint16_t keycode, keyrecord_t *record);

#endif // MACROS_H
