#include "tapdance.h"
#include "keymap.h"

// create a global instance of the tapdance state type
static td_tap_t tap_state = {.state = TD_NONE};


// -------------------------------------------------------------------------------------
// TAP DANCE INITIALISATION
// -------------------------------------------------------------------------------------
// initiate handlers to define the types of taps

// general function to define what type of tap to handle
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

// example of a full tap dance function structure
void td_send_success_strings(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING("key tapped once");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("key tapped twice");
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING("key held once");
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING("key held twice");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("key tapped thrice");
            break;
        case TD_TRIPLE_HOLD:
            SEND_STRING("key held thrice");
            break;
        default:
            break;
    }
}

// defining DK å
void td_aa(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_A);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_LBRC);
            break;
        default:
            break;
    }
}

// defining temporary ø
void td_oe(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_O);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_QUOT);
            break;
        default:
            break;
    }
}

// defining right arrow tapdance
void td_right_skip(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_RIGHT);
            break;
        default:
            break;
    }
}

// defining delete key macro
void td_delete(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DEL);

            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_DEL) SS_UP(X_LCTL));

            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_END) SS_TAP(X_DEL) SS_UP(X_LSFT) SS_UP(X_END));

            break;
        default:
            break;
    }
}

// defining backspace key macro
void td_bspace(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_BSPC);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_BSPC);
            tap_code(KC_BSPC);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_BSPC);
            tap_code(KC_BSPC);
            tap_code(KC_BSPC);
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_BSPC) SS_UP(X_LCTL));
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_HOME) SS_TAP(X_BSPC) SS_UP(X_LSFT) SS_UP(X_HOME));

            break;
        default:
            break;
    }
}

// enable keyboard reset key
// CURRENTLY NOT IN USE
void safe_reset(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            SEND_STRING("keyboard should be reset now");
            reset_keyboard();
            break;
        default:
            break;
    }
}


// defining app and tab switcher tapdance key
void td_apptab_switch(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_TAB);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_TAB);
            tap_code(KC_TAB);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_TAB);
            tap_code(KC_TAB);
            tap_code(KC_TAB);
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LALT) SS_UP(X_LCTL) );
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL));
        break;
        case TD_TRIPLE_HOLD:
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_TAB) SS_UP(X_LGUI));
        default:
            break;
    }
}

// defining esc and task manager tapdance key
    void td_esc_tm(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ESCAPE);
            break;
        case TD_DOUBLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_DEL) SS_UP(X_LCTL) SS_UP(X_LALT));
            break;
        default:
            break;
    }
}

// defining ae and enter tapdance
void td_ae_enter(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SCLN);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_ENT);
            break;
        default:
            reset_tap_dance(state);
            break;
    }
}

// defining previous tab tapdance key
void td_prev_tab(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LCTL) SS_UP(X_LSFT));
            break;
        default:
            break;
    }
}

// defining next tab tapdance key
void td_next_tab(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

// defining home and previous desktop tapdance key
void td_home_prev(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_HOME);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT) SS_UP(X_LCTL));
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LALT));
            break;
        default:
            break;
    }
}

// defining end and next desktop tapdance key
void td_end_next(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_END);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LALT) SS_UP(X_LCTL));
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LALT));
        default:
            break;
    }
}


// defining one shot mod shift-ctrl-alt and next desktop tapdance key
void td_osm_sft_ctl_alt(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_LSFT);
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_mods(MOD_LCTL);
            break;
        case TD_TRIPLE_TAP:
            set_oneshot_mods(MOD_LALT);
            break;
        case TD_SINGLE_HOLD:
            set_oneshot_mods(MOD_LGUI);
            break;
        case TD_DOUBLE_HOLD:
            tap_code(KC_LGUI);
            break;

        default:
            break;
    }
}

void td_left_skip_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_code(KC_LEFT);
}

void td_left_skip_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

void td_right_skip_each_tap(tap_dance_state_t *state, void *user_data) {
    tap_code(KC_RIGHT);
}

void td_right_skip_finished(tap_dance_state_t *state, void *user_data) {
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL));
            break;
        default:
            break;
    }
}

/*

typedef struct {
  bool is_press_action;
  int state;
} tap;

// define alttap state for oneshot functions
static tap alttap_state = {
  .is_press_action = true,
  .state = 0
};

// Defining oneshot layer functions
void alt_finished (tap_dance_state_t *state, void *user_data) {
  alttap_state.state = cur_dance(state);
  switch (alttap_state.state) {
    case TD_SINGLE_TAP: set_oneshot_layer(0, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    case TD_SINGLE_HOLD: register_code(KC_LALT); break;
    case TD_DOUBLE_TAP: set_oneshot_layer(0, ONESHOT_START); set_oneshot_layer(0, ONESHOT_PRESSED); break;
    case TD_DOUBLE_HOLD: register_code(KC_LALT); layer_on(0); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void alt_reset (tap_dance_state_t *state, void *user_data) {
  switch (alttap_state.state) {
    case TD_SINGLE_TAP: break;
    case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
    case TD_DOUBLE_TAP: break;
    case TD_DOUBLE_HOLD: layer_off(0); unregister_code(KC_LALT); break;
  }
  alttap_state.state = 0;

}
*/

// Create an instance of 'td_tap_t' for the 'layer reset and hold gui' tap dance.
static td_tap_t guitap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// for Layer reset and GUI hold tapdance; handle the possible states for each tapdance keycode you define

void lrst_gui_finished (tap_dance_state_t *state, void *user_data) {
    guitap_state.state = cur_dance(state);
    switch (guitap_state.state) {
        case TD_SINGLE_TAP:
            layer_move(_QWERTY);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LGUI)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        default:
            break;
  }
}

void lrst_gui_reset (tap_dance_state_t *state, void *user_data) {
    switch (guitap_state.state) {
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LGUI)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        default:

            break;
  }
   guitap_state.state = TD_NONE;
}

// define per key tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /*case TD(TD_OSM_SCAW):
            return 150;*/
        case TD(TD_BSPACE):
            return 150;
        case TD(TD_DELETE):
            return 150;
        case TD(TD_LEFT_SKIP):
            return 150;
        default:
            return TAPPING_TERM;
    }
}

//Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset),
    [TD_DELETE] = ACTION_TAP_DANCE_FN(td_delete),
    [TD_BSPACE] = ACTION_TAP_DANCE_FN(td_bspace),
    [TD_AE_ENTER] = ACTION_TAP_DANCE_FN(td_ae_enter),
    [TD_TEST_STRING] = ACTION_TAP_DANCE_FN(td_send_success_strings),
    [TD_AA_DK] = ACTION_TAP_DANCE_FN(td_aa),
    [TD_OE_DK] = ACTION_TAP_DANCE_FN(td_oe),
    [TD_APP_TAB] = ACTION_TAP_DANCE_FN(td_apptab_switch),
    [TD_HOME_P] = ACTION_TAP_DANCE_FN(td_home_prev),
    [TD_END_N] = ACTION_TAP_DANCE_FN(td_end_next),
    [TD_ESC_TM] = ACTION_TAP_DANCE_FN(td_esc_tm),
    [TD_NEXT_T] = ACTION_TAP_DANCE_FN(td_next_tab),
    [TD_PREV_T] = ACTION_TAP_DANCE_FN(td_prev_tab),
    //[ALT_OSL1]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL,alt_finished, alt_reset), // skipped because function is not finished yet
    [TD_OSM_SCAW] = ACTION_TAP_DANCE_FN(td_osm_sft_ctl_alt),
    [TD_LEFT_SKIP] = ACTION_TAP_DANCE_FN_ADVANCED(td_left_skip_each_tap, td_left_skip_finished, NULL),
    [TD_RIGHT_SKIP] = ACTION_TAP_DANCE_FN_ADVANCED(td_right_skip_each_tap, td_right_skip_finished, NULL),
    [TD_LRST_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lrst_gui_finished, lrst_gui_reset)
};
