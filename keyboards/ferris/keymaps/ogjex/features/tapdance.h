#pragma once

// tapdance.h
#ifndef TAPDANCE_H
#define TAPDANCE_H

#include "action.h"
#include "action_code.h"
#include "keycodes.h"

// Add any other necessary includes here

// Declare functions or variables related to tap dance keys

typedef struct {
    bool is_press_action;
    bool recording;
    td_state_t state;
} td_tap_t;

typedef struct {
  bool is_press_action;
  int state;
} tap;

// create a global instance of the tapdance state type
static td_tap_t tap_state = {.state = TD_NONE};

// define functions
td_state_t cur_dance(tap_dance_state_t *state);
void alt_finished (tap_dance_state_t *state, void *user_data);
void alt_reset (tap_dance_state_t *state, void *user_data);


#endif // TAPDANCE_H
