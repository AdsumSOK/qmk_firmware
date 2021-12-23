 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

extern uint8_t is_master;
uint8_t mod_state;

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _GAME
};

#define QWERTY MO(_QWERTY)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define GAME MO(_GAME)

#ifdef RGBLIGHT_ENABLE
#define COLORSURB 0, 255, 255   // RED
#define COLORSURB2 51, 87, 100  // WHITE
#define ORANGE_JUL 17, 255,50

void set_rgb_anilatuion_by_layer(layer_state_t state){
    /*
    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    case _LOWER:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    case _RAISE:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    case _GAME:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    default:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
    }*/
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,
                             MO(1),   KC_LGUI, KC_LALT, KC_SPC,   KC_ENT,   KC_RALT, KC_NUBS, TT(2)
),
[_LOWER] = LAYOUT(
  KC_VOLU, _______, _______, _______, _______, _______,                   _______, _______, _______,RGB_M_P, RGB_M_B, RGB_M_R,
  KC_VOLD, _______, _______, _______, _______, _______,                   _______, _______, _______,RGB_M_SW, RGB_M_SN, RGB_M_K,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,RGB_M_X, RGB_M_G, RGB_M_T,
  KC_MUTE, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT,  _______, _______, _______,_______, _______, _______,
                             _______, _______, _______, KC_MPLY, KC_MSTP,  _______, _______, _______
),
[_RAISE] = LAYOUT(
  KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS,  KC_SLCK, KC_DEL,  KC_END,  KC_HOME, KC_INS,                     KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PMNS, KC_F12,
  KC_TRNS,  KC_PAUS, KC_PGUP, KC_UP,   KC_PGDN, KC_TRNS,                    KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PSLS, TO(3),
  KC_TRNS,  KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_CAPS, KC_NLCK,  KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_TRNS, KC_TRNS,
                               TO(0), KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_P0,   KC_PDOT, _______
),
  [_GAME] = LAYOUT(
  KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_ESC,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,
  KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                   KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,
  KC_TRNS,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,
  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_H,    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,
                               TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTRL,KC_M,     KC_U,   KC_O
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    //state = update_tri_layer_state(state, _RAISE, _LOWER, _GAME);
#ifdef RGBLIGHT_ENABLE// RGBLIGHT_ENABLE
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAME));
#endif // RGBLIGHT_ENABLE
    return state;

};
#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 70, ORANGE_JUL}
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,70, HSV_PURPLE},
    {11,2, HSV_BLUE},
    {24,1, HSV_BLUE},
    {65,2, HSV_BLUE},
    {30,2, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,70, HSV_BLUE},// Light 70 LEDs, starting with LED 0
    {20,1, COLORSURB},
    {26,3, COLORSURB},
    {50,6, COLORSURB},
    {62,3, COLORSURB},
    {67,1, COLORSURB},
    {6,5, COLORSURB2},
    {41,7, COLORSURB2}

);

const rgblight_segment_t PROGMEM my_game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,70, HSV_GREEN},// Light 70 LEDs, starting with LED 0
    {6,5, COLORSURB2},
    {13,5, COLORSURB2},
    {21,2, COLORSURB2},
    {30,1, COLORSURB2},
    {55,1, COLORSURB},
    {61,3, COLORSURB}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_lower_layer,
    my_raise_layer,
    my_game_layer
);

layer_state_t default_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    return state;
}

#endif // RGBLIGHT_ENABLE

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }

}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;


const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        //keylog_str[0] = code_to_name[keycode];
        keylog_str[0] = '*';
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);

}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("BASE"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("SPEC"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("PLUS"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("GAME"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

bool oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool delkey_registered=false;
    static bool ctrlkey_registered=false;
    mod_state = get_mods();
    if (record->event.pressed) {
        add_keylog(keycode);
        switch(keycode){
            case KC_DEL:
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_BSPC);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
                break;

            case KC_LCTRL:
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_RCTRL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    ctrlkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
                break;

        }
    }else{
        switch(keycode){
           case KC_DEL:
                if (delkey_registered) {
                        unregister_code(KC_BSPC);
                        delkey_registered = false;
                        return false;
                }
            break;

            case KC_LCTRL:
                if (ctrlkey_registered) {
                        unregister_code(KC_RCTRL);
                        ctrlkey_registered = false;
                        return false;
                }
            break;
        }
    }

    return true;
}



// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if(IS_LAYER_ON(_RAISE)) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_MNXT);
      } else {
          tap_code(KC_MPRV);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_LOWER)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_RIGHT);
      } else {
          tap_code(KC_LEFT);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_DOWN);
      } else {
          tap_code(KC_UP);
      }
    }
  }
    return true;
}
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
   rgblight_layers = my_rgb_layers;
   rgblight_sethsv_noeeprom(ORANGE_JUL);
   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}
#endif
