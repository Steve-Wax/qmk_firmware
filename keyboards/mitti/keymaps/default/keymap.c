#include QMK_KEYBOARD_H

const uint16_t PROGMEM quote_combo[] = {RALT_T(KC_L), RGUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM esc_combo[]   = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM del_combo[]   = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM del_combo2[]  = {KC_E, KC_R, COMBO_END};
combo_t                key_combos[]  = {
    COMBO(quote_combo, KC_QUOTE),
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(del_combo2, KC_DEL),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, MO(1), LSFT_T(KC_ENT), LCTL_T(KC_TAB), KC_BSPC, KC_SPC, MO(2)),
                                                              [1] = LAYOUT_split_3x5_3(XXXXXXX, KC_BTN1, KC_UP, KC_BTN2, KC_LPRN, KC_RPRN, KC_7, KC_8, KC_9, KC_0, KC_LGUI, LALT_T(KC_LEFT), LCTL_T(KC_DOWN), LSFT_T(KC_RIGHT), KC_LBRC, KC_RBRC, RSFT_T(KC_4), RCTL_T(KC_5), RALT_T(KC_6), RGUI_T(KC_PPLS), LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_LCBR, KC_RCBR, KC_1, KC_2, KC_3, KC_PMNS, _______, _______, _______, _______, _______, MO(3)),
                                                              [2] = LAYOUT_split_3x5_3(KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LGUI_T(KC_GRV), LALT_T(KC_PIPE), LCTL_T(KC_UNDS), LSFT_T(KC_PIPE), KC_UNDS, KC_EQL, RSFT_T(KC_PGUP), RCTL_T(KC_DEL), RALT_T(KC_INS), RGUI_T(KC_NUM_LOCK), KC_PSCR, KC_TILD, XXXXXXX, KC_BSLS, KC_MINS, KC_PPLS, KC_PGDN, KC_END, KC_HOME, XXXXXXX, MO(3), _______, _______, _______, _______, _______),
                                                              [3] = LAYOUT_split_3x5_3(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, LGUI_T(KC_F11), LALT_T(KC_F12), LCTL_T(KC_MPLY), LSFT_T(KC_MUTE), KC_VOLU, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX, KC_MSTP, KC_MPRV, KC_MNXT, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______)};
