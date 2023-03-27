#include QMK_KEYBOARD_H
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_RAYCAST LGUI(KC_SPACE)
#define KC_SWITCH LGUI(KC_TAB)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | GRV  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QUTE |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  [   |
 * |------+------+------+------+------+------| RAISE |    |LOWER  |------+------+------+------+------+------|
 * |LS/TAB|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  ]   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTR | LALT |LGUI  | /SWWIN  /       \Space \  |Raycst|BackSP| Enter|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * SWWIN: Switch active window
 * Raycst: Opens Raycast
 * LS/TAB: Tap for Tab, Hold for Left Shift
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,       KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,        KC_7,         KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_GRV,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,        KC_U,         KC_I,    KC_O,    KC_P,    KC_EQUAL,
  KC_QUOT,      KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,        KC_J,         KC_K,    KC_L,    KC_SCLN, KC_LBRC,
MT(MOD_LSFT, KC_TAB), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   MO(_RAISE),    MO(_LOWER),  KC_N,        KC_M,         KC_COMM, KC_DOT,  KC_SLSH,  KC_RBRC,
                        KC_LCTL, KC_LALT, KC_LGUI,        KC_SWITCH,     KC_SPACE,    KC_RAYCAST,  KC_BACKSPACE, KC_ENTER
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  UP  |      |      |      |                    |      | HOME | PGUP |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LEFT | DOWN |RIGHT |      |      |-------.    ,-------|      | END  | PGDN |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |  \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CUT  | COPY |PASTE | / CAPS  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 * 
 * CAPS: Caps Word toggle
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,XXXXXXX,
  XXXXXXX,KC_LEFT,KC_DOWN,KC_RIGHT,XXXXXXX,XXXXXXX,                         XXXXXXX, KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_MAC_CUT, KC_MAC_COPY, KC_MAC_PASTE, CW_TOGG, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \NLOCK \  |  0   |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_KP_7,KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_KP_4,KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM_LOCK,  KC_KP_0, XXXXXXX, XXXXXXX
)};