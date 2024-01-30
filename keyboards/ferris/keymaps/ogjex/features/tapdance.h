#pragma once

#ifndef TAPDANCE_H
#define TAPDANCE_H
#include QMK_KEYBOARD_H

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

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    bool recording;
    td_state_t state;
} td_tap_t;

// Declare functions
void safe_reset(tap_dance_state_t *state, void *user_data);
void td_delete(tap_dance_state_t *state, void *user_data);
void td_bspace(tap_dance_state_t *state, void *user_data);
void td_ae_enter(tap_dance_state_t *state, void *user_data);
void td_send_success_strings(tap_dance_state_t *state, void *user_data);
void td_aa(tap_dance_state_t *state, void *user_data);
void td_oe(tap_dance_state_t *state, void *user_data);
void td_apptab_switch(tap_dance_state_t *state, void *user_data);
void td_home_prev(tap_dance_state_t *state, void *user_data);
void td_end_next(tap_dance_state_t *state, void *user_data);
void td_esc_tm(tap_dance_state_t *state, void *user_data);
void td_next_tab(tap_dance_state_t *state, void *user_data);
void td_prev_tab(tap_dance_state_t *state, void *user_data);
void td_osm_sft_ctl_alt(tap_dance_state_t *state, void *user_data);
void td_left_skip_each_tap(tap_dance_state_t *state, void *user_data);
void td_left_skip_finished(tap_dance_state_t *state, void *user_data);
void td_right_skip_each_tap(tap_dance_state_t *state, void *user_data);
void td_right_skip_finished(tap_dance_state_t *state, void *user_data);
void lrst_gui_finished(tap_dance_state_t *state, void *user_data);
void lrst_gui_reset(tap_dance_state_t *state, void *user_data);
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

#endif // TAPDANCE_H
