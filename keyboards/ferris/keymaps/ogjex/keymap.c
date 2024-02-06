#include "keymap_danish.h"
#include "keymap.h"

#include "features/tapdance.h"
#include "features/macros.h"

// define the various layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    // Base key input layer--------------------                                     -----------------------------------------------
    KC_Q, KC_W, KC_E, KC_R, KC_T,                                                   KC_Y, KC_U, KC_I, TD(TD_OE_DK), KC_P,
    //-----------------------------------------                                     -----------------------------------------------
    TD(TD_AA_DK), KC_S, KC_D, KC_F, KC_G,                                           KC_H, KC_J, KC_K, KC_L, TD(TD_AE_ENTER),
    //-----------------------------------------                                     -----------------------------------------------
    KC_Z, KC_X , KC_C, KC_V, TD(TD_DELETE),                                         KC_B, KC_N, KC_M, KC_COMM, KC_DOT,
    //-----------------------------------------                                     -----------------------------------------------
                TD(TD_LRST_GUI), MT(MOD_LSFT, KC_SPC),                              OSL(_SYMB), TD(TD_OSM_SCAW)
    ),

    [_SYMB] = LAYOUT(
    // Signs and symbols layer, from layer 0---                                     ----------------------------------------------
    TD(TD_ESC_TM), ALGR(KC_2), LSFT(KC_3), ALGR(KC_4), LSFT(KC_4),                  LSFT(KC_6), LSFT(KC_7), KC_NO, KC_SLSH, LSFT(KC_SLSH),
    // ----------------------------------------                                     ----------------------------------------------
    KC_EQL, LSFT(KC_EQL), LSFT(KC_2), KC_NUHS, KC_PAST,                             LSFT(KC_1), LSFT(KC_8), LSFT(KC_9), LSFT(KC_MINS), ALGR(KC_EQL),
    // ----------------------------------------                                     ----------------------------------------------
    KC_NUBS, LSFT(KC_NUBS), ALGR(KC_RBRC), KC_RBRC, KC_GRV,                         ALGR(KC_8), ALGR(KC_7), ALGR(KC_0), ALGR(KC_9), TO(_NAV),
    // ----------------------------------------                                     ----------------------------------------------
                            KC_TRNS, KC_TRNS,                                       TO(_NMPAD), KC_TRNS
    ),

    [_NMPAD] = LAYOUT(
    // Numpad layer, from layer 1--------------                                     ---------------------------------------------
    KC_TRNS, KC_NO, LSFT(KC_0), KC_PPLS, KC_PMNS,                                   KC_COMM, KC_7, KC_8, KC_9, TD(TD_BSPACE),
    // ----------------------------------------                                     ---------------------------------------------
    TD(TD_APP_TAB), KC_NO, KC_NO, KC_PSLS, KC_PAST,                                 KC_PERC, KC_4, KC_5, KC_6, KC_ENT,
    // ----------------------------------------                                     ---------------------------------------------
    KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_TRNS,                                    KC_0, KC_1, KC_2, KC_3, KC_DOT,
    // ----------------------------------------                                     ---------------------------------------------
                                KC_TRNS, KC_TRNS,                                   TO(_FKEY), KC_TRNS
    ),

    [_NAV] = LAYOUT(
    // Navigation layer, from base layer 0-----                                     --------------------------------------------
    TD(TD_ESC_TM), KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                              TD(TD_HOME_P), TD(TD_PREV_T), TD(TD_NEXT_T), TD(TD_END_N), TD(TD_BSPACE),
    // ----------------------------------------                                     --------------------------------------------
    TD(TD_APP_TAB), KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                             TD(TD_LEFT_SKIP), KC_DOWN, KC_UP, TD(TD_RIGHT_SKIP), KC_ENT,
    // ----------------------------------------                                     --------------------------------------------
    KC_BTN2, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), TD(TD_DELETE),                     KC_ACL0, KC_ACL1, KC_ACL2, KC_PGDN, KC_PGUP,
    // ----------------------------------------                                     --------------------------------------------
                            KC_TRNS, KC_TRNS,                                       KC_BTN1, TD(TD_OSM_SCAW)
    ),

    [_FKEY] = LAYOUT(
    // F Key layer, from _NMPAD layer------------                                   --------------------------------------------
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    // ----------------------------------------                                     ---------------------------------------------
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_NO, KC_NO, KC_NO, KC_F11, KC_F12,
    // ----------------------------------------                                     ---------------------------------------------
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // ----------------------------------------                                     ---------------------------------------------
                                KC_TRNS, KC_TRNS,                                   KC_NO, KC_TRNS
    ),
};

// commented for troubleshoot reasons
/* Defining all macros for oneshot layers
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_TRNS:
    case KC_NO:
      // Always cancel one-shot layer when another key gets pressed
      if (record->event.pressed && is_oneshot_layer_active()){
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return true;
      }
    case QK_BOOTLOADER:
      // Don't allow reset from oneshot layer state
      if (record->event.pressed && is_oneshot_layer_active()){
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      }
      return true;
    default:
      return true;
  }
  return true;
}
*/



/*
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_LEFT_SKIP):
            return QUICK_TAP_TERM - 20;
        default:
            return QUICK_TAP_TERM;
    }
}
*/

// old code from here

// -------------------------------------------------------------------------------------
// ONESHOT MOD INITIALISATION
// -------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------
// MACRO INITIALISATION
// -------------------------------------------------------------------------------------

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

