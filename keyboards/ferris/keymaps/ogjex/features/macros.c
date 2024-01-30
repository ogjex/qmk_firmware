// macros.c
#include "macros.h"

// Defining macros on user input level
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    // define all macros to launch when keys are pressed (but not released)
    if(record->event.pressed){
        switch(keycode){
            case M_QUES:
            send_unicode_string("?");
            return false;
            break;
        default:
            break;
        }
    }
    return true;
}
