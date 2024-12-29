#include QMK_KEYBOARD_H

const uint16_t PROGMEM quote_combo[] = {RALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM esc_combo[]   = {KC_Q, KC_U, COMBO_END};
const uint16_t PROGMEM del_combo[]   = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM del_combo2[]  = {KC_E, KC_R, COMBO_END};
combo_t                key_combos[]  = {
    COMBO(quote_combo, KC_QUOTE),
    COMBO(esc_combo, LCTL(KC_ESC)),
    COMBO(del_combo, LCTL(KC_DEL)),
    COMBO(del_combo2, LCTL(KC_DEL)),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return true;
        default:
            return false;
    }
}