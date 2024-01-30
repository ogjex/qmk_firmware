#pragma once
#include QMK_KEYBOARD_H

// tapdance.h
#ifndef TAPDANCE_H
#define TAPDANCE_H

#include "action.h"
#include "action_code.h"
#include "keycodes.h"

// Add any other necessary includes here

// Declare functions or variables related to tap dance keys
 //Our custom tap dance keys; add any other tap dance keys to this enum
enum {
    TD_RESET,
    TD_DELETE,
    TD_BSPACE,
    TD_AE_ENTER,
    TD_TEST_STRING,
    TD_AA_DK,
    TD_OE_DK,
    TD_APP_TAB,
    TD_HOME_P,
    TD_END_N,
    TD_ESC_TM,
    TD_NEXT_T,
    TD_PREV_T,
    ALT_OSL1,
    TD_OSM_SCAW,
    TD_LEFT_SKIP,
    TD_RIGHT_SKIP,
    TD_LRST_GUI
};


// Declare functions


#endif // TAPDANCE_H
