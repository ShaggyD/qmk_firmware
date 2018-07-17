#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


//#include "keymap_german.h"

//#include "keymap_nordic.h"

// Default Methods
__attribute__ ((weak))
void matrix_init_keymap(void) {}




enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

//define layer change stuff for underglow indicator
bool skip_leds = false;



// Tapdance definitions
enum {
  TD_ESCAPE_CAPS = 0,
  TD_CC_TERMINAL,
  TD_CTL_CODE,
  TD_DOT_MENU,
  TD_HH_WINDOW,
  TD_SEMI_TAB,
  TD_SEMI_QUOTE,
  TD_ALL_APPLICATIONS,
  TD_ALL_WINDOWS,
  TD_DELETE
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESCAPE_CAPS]      = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_HH_WINDOW]        = ACTION_TAP_DANCE_DOUBLE(KC_H, LGUI(KC_TAB)),
  [TD_SEMI_TAB]         = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, LGUI(KC_GRAVE)),
  [TD_SEMI_QUOTE]       = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_SCOLON),
  [TD_DOT_MENU]         = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, LCTL(LSFT(KC_SPACE))),
  [TD_CC_TERMINAL]      = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, LGUI(KC_ESCAPE)),
  [TD_CTL_CODE]         = ACTION_TAP_DANCE_DOUBLE(KC_TAB, TT(1)),
  [TD_ALL_WINDOWS]      = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_UP), LCTL(KC_UP)),
  [TD_DELETE]           = ACTION_TAP_DANCE_DOUBLE(KC_BSPACE, KC_DEL),
  [TD_ALL_APPLICATIONS] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_DOWN), LCTL(KC_DOWN))
  // Other declarations would go here, separated by commas, if you have them
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layers based on  https://configure.ergodox-ez.com/keyboard_layouts/kwbbaw/edit

  // Base Typing Layer
  [0] = KEYMAP(
               // ================= Left Hand  =================

               // Left Top Row
               KC_GRAVE,             KC_1,KC_2,KC_3,KC_4,KC_5,        KC_HOME,

               // Left Alphas
               KC_TAB,               KC_Q,KC_W,KC_E,KC_R,KC_T,        KC_TRANSPARENT,
               TD(TD_ESCAPE_CAPS),   KC_A,KC_S,KC_D,GUI_T(KC_F),KC_G,
               KC_LSHIFT,   KC_Z,KC_X,KC_C,KC_V,KC_B,                 KC_GRAVE,

               // Left bottom row
               LCTL(LSFT(KC_SPACE)),KC_LALT,GUI_T(KC_NO),KC_MINUS,LT(8,KC_PGUP),

               // Left Thumb Cluster
                         KC_TRANSPARENT,  KC_TRANSPARENT,
                                          KC_TRANSPARENT,
               KC_SPACE, KC_LBRACKET,     KC_MINUS,

               // ================= Right Hand  =================
               // Right Alphas
               KC_END,             KC_6,KC_7,KC_8,KC_9,KC_0,                       KC_BSPACE,
               KC_TRANSPARENT,     KC_Y,KC_U,KC_I,KC_O,KC_P,   KC_BSLASH,
                                   KC_H,GUI_T(KC_J),CTL_T(KC_K),KC_L,KC_SCOLON,           KC_QUOTE,
               CTL_T(KC_QUOTE),    KC_N,KC_M,TD(TD_CC_TERMINAL),KC_DOT,KC_SLASH,   KC_RSHIFT,

               // Right bottom row
               GUI_T(KC_PGDOWN),KC_EQUAL,TD(TD_ALL_WINDOWS),TD(TD_ALL_APPLICATIONS),LCTL(LSFT(KC_SPACE)),

               // Right Thumb Cluster
               KC_TRANSPARENT,              KC_TRANSPARENT,
               KC_TRANSPARENT,
               KC_EQUAL,     KC_RBRACKET,    LT(6, KC_ENTER)
  ),

  // Development Layer
  [1] = KEYMAP(
               // ================= Left Hand  =================

               // Left Top Row
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,

               // Left Alphas
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,

               // Left bottom row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Left Thumb Cluster
                               KC_TRANSPARENT,   KC_TRANSPARENT,
                                                 KC_TRANSPARENT,
               KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,

               // ================= Right Hand  =================
               // Right Alphas
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
                                           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        MT(MOD_LSFT, KC_RBRACKET),

               // Right bottom row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Right Thumb Cluster
               KC_TRANSPARENT ,    KC_TRANSPARENT,
               KC_TRANSPARENT,
               KC_TRANSPARENT,     KC_TRANSPARENT,    KC_TRANSPARENT
  ),
  [2] = KEYMAP(
               // ================= Left Hand  =================

               // Left Top Row
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,

               // Left Alphas
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,

               // Left bottom row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Left Thumb Cluster
                               KC_TRANSPARENT,   KC_TRANSPARENT,
                                                 KC_TRANSPARENT,
               KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,

               // ================= Right Hand  =================
               // Right Alphas
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
                                           KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,
               KC_TRANSPARENT,             KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,        KC_TRANSPARENT,

               // Right bottom row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Right Thumb Cluster
               KC_TRANSPARENT ,    KC_TRANSPARENT,
               KC_TRANSPARENT,
               KC_TRANSPARENT,     KC_TRANSPARENT,    KC_TRANSPARENT
  ),
  [3] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [4] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [5] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  // Mouse/Navigation Layer
  [6] = KEYMAP(
               // ================= Left Hand  =================

               // Left Top Row
               KC_GRAVE,      LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                      RESET,

               // Left Alphas
               LGUI(KC_TAB),   KC_TRANSPARENT,LGUI(KC_W),KC_MS_UP,LGUI(KC_R),LGUI(KC_T),                    KC_MS_ACCEL1,
               KC_MS_WH_LEFT,  KC_MS_WH_UP,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_UP,
               KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,  KC_MS_ACCEL0,

               // Left Bottom Row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Left Thumb Cluster
               LCTL(LSFT(KC_SPACE)), LCTL(LGUI(LSFT(KC_4))),
               KC_TRANSPARENT,
               KC_MS_BTN1,           KC_MS_BTN2,             LGUI(KC_ESCAPE),

               // ================= Left Hand  =================

               // Right Top Row
               KC_TRANSPARENT,    LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),                     KC_MINUS,
               KC_AUDIO_VOL_UP,   KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT, KC_TRANSPARENT,
               KC_LEFT,KC_DOWN,   KC_UP,KC_RIGHT,KC_MS_WH_DOWN,KC_MS_WH_RIGHT,
               KC_AUDIO_VOL_DOWN, KC_TRANSPARENT,TD(TD_DOT_MENU),KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,       KC_TRANSPARENT,

               // Right Bottom Row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Right Thumb Cluster
               KC_TRANSPARENT,KC_TRANSPARENT,
               KC_TRANSPARENT,
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
   ),

  // Quick Mouse layer
  [7] = KEYMAP(
               // ================= Left Hand  =================

               // Left Top Row
               KC_GRAVE,      LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),                      RESET,

               // Left Alphas
               LGUI(KC_TAB),   KC_TRANSPARENT,LGUI(KC_W),KC_MS_UP,LGUI(KC_R),LGUI(KC_T),                    KC_MS_ACCEL1,
               KC_MS_WH_LEFT,  KC_MS_WH_UP,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_UP,
               KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,  KC_MS_ACCEL0,

               // Left Bottom Row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Left Thumb Cluster
               LCTL(LSFT(KC_SPACE)), LCTL(LGUI(LSFT(KC_4))),
               KC_TRANSPARENT,
               KC_MS_BTN1,           KC_MS_BTN2,             LGUI(KC_ESCAPE),

               // ================= Left Hand  =================

               // Right Top Row

               KC_TRANSPARENT,    LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),                     KC_MINUS,
               KC_AUDIO_VOL_UP,   KC_TRANSPARENT,KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,KC_TRANSPARENT, KC_TRANSPARENT,
                                  KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,                    KC_TRANSPARENT,
               KC_AUDIO_VOL_DOWN, KC_TRANSPARENT,TT(7),KC_LBRACKET,KC_RBRACKET,KC_TRANSPARENT,       KC_TRANSPARENT,

               // Right Bottom Row
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

               // Right Thumb Cluster
               KC_TRANSPARENT,KC_TRANSPARENT,
               KC_TRANSPARENT,
               KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT
   ),

  // Window Placement layer
  [8] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(LCTL(LGUI(KC_Q))),LALT(LCTL(LGUI(KC_UP))),LALT(LCTL(LGUI(KC_E))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(LCTL(LGUI(KC_LEFT))),LALT(LCTL(LGUI(KC_F))),LALT(LCTL(LGUI(KC_RIGHT))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LALT(LCTL(LGUI(KC_Z))),LALT(LCTL(LGUI(KC_DOWN))),LALT(LCTL(LGUI(KC_C))),KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),



};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
  /* turn to green */
  rgblight_mode(1);
  rgblight_setrgb(0x00,0xff,0x00);
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

void matrix_scan_keymap(void) {  // runs frequently to update info
  uint8_t modifiders = get_mods();
  // uint8_t led_usb_state = host_keyboard_leds();
  uint8_t one_shot = get_oneshot_mods();

  if (!skip_leds) {

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // Since we're not using the LEDs here for layer indication anymore,
    // then lets use them for modifier indicators.  Shame we don't have 4...
    // Also, no "else", since we want to know each, independently.
    if (modifiders & MODS_GUI_MASK || one_shot & MODS_GUI_MASK) {

      ergodox_right_led_2_on();
      ergodox_right_led_2_set( 10 );
    }
    if (modifiders & MODS_CTRL_MASK || one_shot & MODS_CTRL_MASK) {
      ergodox_right_led_1_on();
      ergodox_right_led_1_set( 10 );
    }
    if (modifiders & MODS_ALT_MASK || one_shot & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
      ergodox_right_led_3_set( 10 );
    }

  }
};


LEADER_EXTERNS();
void matrix_scan_leaders(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    /*
    SEQ_ONE_KEY(KC_F) {
      register_code(KC_S);
      unregister_code(KC_S);
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_H);
      unregister_code(KC_H);
    }
    */

    SEQ_ONE_KEY(KC_W) {
      register_code(KC_ESCAPE);
      unregister_code(KC_ESCAPE);

      // KC_LSHIFT
      register_code(KC_LSHIFT);
      register_code(KC_SCOLON);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_SCOLON);


      register_code(KC_W);
      unregister_code(KC_W);
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();

  // Handle RGB strip colors
  //uint8_t layer = biton32(state);

  // switch (layer) {
  //   case 0:
  //     /* turn to green */
  //     rgblight_mode(1);
  //     rgblight_setrgb(128,0,128);
  //     break;
  //   case 1:
  //     /* turn to green */
  //     rgblight_mode(1);
  //     rgblight_setrgb(0,255,0);
  //     break;
  //   case 6:
  //     rgblight_mode(1);
  //     rgblight_setrgb(0, 0, 255);
  //     break;
  //   default:
  //     break;
  // }
  return state;

};

// No global matrix scan code, so just run keymap's matix
// scan function
void matrix_scan_user(void) {
  matrix_scan_keymap();
  matrix_scan_leaders();
}
