/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define NUMB 1 // Numbers and Arrows
#define SYMB 2 // Symbols
#define ADJ 3  //  Function Keys
#define MOUS 4 // Mouse keys

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |L3      |   A  |   S  |  D   |   F  |   G  | LMB  |           |  _   |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |LS/Caps |   Z  |   X  |   C  |   V  |   B  |CTL/TAB|          |BS    |   N  |   M  | ,  < | . >  | /  ? | Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    | ESC      |   |L1     |                                 | L2   |   |DEL  |
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | RMB   |                      |       |
 *                                 ,------|-------|                      |-------|------.
 *                                 | Enter|       |                      |       |      |
 *                                 | Shift|  =    |                      |   _   |Space |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    KC_TAB,                 KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_PIPE,
    MO(ADJ), LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_BTN1,            KC_UNDS,  KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
    LSFT_T(KC_CAPS),KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   LCTL_T(KC_TAB), KC_BTN2,     KC_BSPC, KC_BSPC,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                                        KC_ESC, TT(NUMB), LSFT_T(KC_ENT), KC_EQL,        KC_UNDS, KC_SPC, TT(SYMB), LT(MOUS, KC_DEL)
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |  MB1 |  UP  | MB2  |  (   |                         |   )  |   7  |  8   |   9  |   0  |PageU   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      | LEFT |  DOWN| RIGHT|  [   |      |           |      |   ]  |   4  |  5   |  6   |  +   |PageD   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      | CUT  | COPY | PASTE|  {   |      |           |      |   }  |   1  |  2   |  3   |  -   | Home   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | 0   |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    XXXXXXX, XXXXXXX, KC_BTN1,   KC_UP, KC_BTN2, KC_LPRN,                                            KC_RPRN, KC_P7, KC_P8, KC_P9, KC_P0, KC_PGUP,
    XXXXXXX, XXXXXXX, KC_LEFT,  KC_DOWN, KC_RIGHT, KC_LBRC,  _______,                          _______, KC_RBRC, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PGDN,
    XXXXXXX, XXXXXXX, KC_CUT, LCTL(KC_C), LCTL(KC_V), KC_LCBR, _______, _______,        _______, _______, KC_RCBR, KC_P1, KC_P2, KC_P3,  KC_PMNS, KC_HOME,
                                        _______, _______, _______, _______,         _______,  _______, _______, KC_P0
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | ESC/~  |   !  |  @   |  #   |  $   |  %   |                         |  ^   |  &   |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |   `  |  -   |  _   |  \   |  _   |      |           |      |  =   |PageU |Delete|Insert|NumLck|        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |PScrn |      |      |      |  -   |      |           |      |   +  |PageD | End  |Home  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'r
 */
[SYMB] = LAYOUT_gergo(
    KC_GESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                            KC_CIRC,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
    XXXXXXX, KC_GRV, KC_MINS, KC_UNDS, KC_BSLS, KC_UNDS,  _______,                          _______, KC_EQL, KC_PGUP, KC_DEL,   KC_INS, KC_NLCK, XXXXXXX,
    XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, _______, _______,        _______, _______, KC_PPLS, KC_PGDN, KC_END, KC_HOME, XXXXXXX, XXXXXXX,
                                        _______, _______, _______, _______,         _______,  _______, _______, _______
    ),

/* Keymap 3: Function keys
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[ADJ] = LAYOUT_gergo(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, KC_F12, XXXXXXX, KC_MPLY, KC_MUTE, KC_VOLU, _______,                         _______, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,  RGB_MOD,
    XXXXXXX, BL_STEP, KC_MSTP, KC_MPRV, KC_MNXT, KC_VOLD, _______, _______,        _______, _______, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, RGB_RMOD,
                                        _______, _______, _______, _______,         _______,  _______, _______, _______
    ),
 
 /* Keymap 4: Mouse keys
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[MOUS] = LAYOUT_gergo(
    XXXXXXX, KC_WH_L, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_WH_L, KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,  _______,                          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX, _______, _______,        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______, _______, _______,         _______,  _______, _______, _______
    )
};
/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
 
 bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_ENT):
            return false;
        default:
            return true;
}
}
