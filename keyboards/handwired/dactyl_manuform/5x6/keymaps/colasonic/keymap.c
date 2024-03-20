/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "secrets.h"
#include "features/layer_lock.h" //LLOCK

enum custom_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  LLOCK,
};
//Tap Dance Declarations
enum {
  CT_RSHFT,
  KC3_CTL,
  KC4_CTL,
  END_CTL,
  KC_UP_CTL,
  KC_DOWN_CTL,
  KC_LEFT_CTL,
  KC_RGHT_CTL,
};
//Quad Function Tap-Dance
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

uint8_t cur_dance(tap_dance_state_t *state);

//key mapping

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_5x6(
     QK_GESC , 	KC_1      , 	KC_2  , 		TD(KC3_CTL),    TD(KC4_CTL),	KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,		KC_MINS,
     KC_TAB , 	KC_Q      ,		KC_W  , 		KC_F  , 		KC_P  , 		KC_B  ,                         KC_J  , KC_L  , KC_U  , KC_Y  , KC_SCLN  ,	KC_EQL,
     KC_BSPC, 	KC_A      , 	KC_R  , 		KC_S  , 		KC_T  , 		KC_G  ,                         KC_M  , KC_N  , KC_E  , KC_I  , KC_O  ,		KC_QUOT,
     KC_LSFT, 	LT(1,KC_Z), 	LT(2,KC_X)  , 	LT(3,KC_C)  , 	KC_D  , 		KC_V  ,                         KC_K  , KC_H  ,	KC_COMM,KC_DOT ,KC_SLSH,	TD(CT_RSHFT),
                          		KC_LCTL,		KC_LALT,                                                						TT(4),		KC_RCTL,
			                                 	ALT_T(KC_ENT),	LCTL_T(KC_SPACE),                       				KC_SPACE, 		KC_ENT,
			                                  	OSL(2), 		OSL(1),                									KC_PGUP,  		KC_PGDN,
			                                  	LGUI_T(KC_HOME),TD(END_CTL),                        					KC_LBRC,		KC_DEL
			  ),

  [1] = LAYOUT_5x6(

     KC_TILD,	KC_EXLM,	     KC_AT,		    LCTL(LSFT(KC_3)),	LALT(KC_F4) ,		KC_PERC,                    KC_NUM,			KC_SLSH,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_DEL,
     KC_CALC,	LALT(KC_2),	     LCTL(KC_W),    LCTL(LSFT(KC_F)),	ST_MACRO_0,			ST_MACRO_1,               	KC_CLR, 			KC_P7 , 	KC_P8 , 	KC_P9 ,		KC_MINS,	KC_PIPE,
     KC_CAPS,	LALT(KC_1),	     LALT(KC_R),	LALT(KC_S),			LSFT(KC_F9) ,		ST_MACRO_2,               	LCTL(LSFT(KC_M)), 	KC_P4 , 	KC_P5 , 	KC_P6 ,		KC_PLUS,	KC_BSLS,
     TO(0)  ,	LALT(LSFT(KC_C)),ST_MACRO_3,	LCTL(KC_C),			LCTL(LSFT(KC_Y)),	LCTL(KC_V),               	_______, 			KC_P1 , 	KC_P2 , 	KC_P3 ,		KC_EQL ,	KC_UNDS,
                          	     KC_WBAK,		KC_WFWD,              												                        KC_COMM,	KC_DOT,
                                             	ST_MACRO_12,		KC_DELETE,          										KC_P0,		KC_P0,
                                              	LALT(LCTL(KC_DELETE)),_______,													KC_PSCR,	KC_PAUSE,
                                             	KC_PGUP,              KC_PGDN,            										KC_RBRC,	_______

  ),

  [2] = LAYOUT_5x6(
   	KC_F12 , 	KC_F1 , 	        KC_F2 , 			KC_F3 , 			KC_F4 , 			KC_F5 ,                  	KC_F6  , 	KC_F7 , 	KC_F8 , 	KC_F9 ,		KC_F10 ,	KC_F11 ,
    _______,	_______,	        LALT(KC_W),			ST_MACRO_4,			ST_MACRO_10,		KC_LBRC,                    KC_RBRC,	KC_INS ,	KC_UP,		_______,	KC_SCRL,	KC_MUTE,
  	KC_F12 ,	LCTL(KC_F1),        LCTL(LSFT(KC_R)),	LCTL(KC_S),		    LCTL(KC_F3),		LCTL(KC_F5),                KC_RPRN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	_______,	KC_VOLU,
 	TO(0)  ,	LALT(LSFT(KC_R)),	ST_MACRO_5,			ST_MACRO_6,			ST_MACRO_9,			ST_MACRO_7,               	_______,	_______,	_______,	_______,	_______,	KC_VOLD,
                          	_______,			_______,            																		KC_EQL ,	_______,
                                               	KC_PGUP,            KC_PGDN,            										_______,	_______,
                                               	_______,			LALT(LCTL(KC_END)),            								_______,	_______,
                                               	ST_MACRO_11,		LLOCK,            										LGUI(KC_L),	ST_MACRO_8
  ),

  [3] = LAYOUT_5x6(
   	_______,	_______,	_______,			_______, 			_______, 			_______,                  	_______, 	_______, 		_______, 	_______,		_______,	_______,
    _______,	LCTL(KC_Q),	_______,           TD(KC_UP_CTL),       _______,			_______,                    _______,	KC_MS_WH_UP,	KC_MS_UP,	KC_MS_WH_DOWN,	_______,	_______,
  	_______,	LALT(KC_1),	TD(KC_LEFT_CTL),   TD(KC_DOWN_CTL),     TD(KC_RGHT_CTL),	_______,                 	_______,	KC_MS_LEFT,		KC_MS_DOWN,	KC_MS_RIGHT,	_______,	_______,
 	TO(0)  ,	KC_LSFT,	_______,            _______,            _______,			ST_MACRO_9,               	_______,	_______,		_______,	_______,		_______,	_______,
                          	_______,            _______,            																		_______,	_______,
                                               	LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_RGHT)),            							KC_MS_BTN1,	KC_MS_BTN2,
                                               	_______,			LLOCK,            										KC_PGUP,  	KC_PGDN,
                                               	KC_HOME,            TD(END_CTL),            								_______,	_______
  ),
  [4] = LAYOUT_5x6(
     QK_GESC , 	KC_1      , 	KC_2  , 		KC_3,    		KC_4,			KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,		KC_MINS,
     KC_TAB , 	KC_Q      ,		KC_W  , 		KC_E  , 		KC_R  , 		KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,		KC_EQL,
     KC_BSPC, 	KC_A      , 	KC_S  , 		KC_D  , 		KC_F  , 		KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  , KC_SCLN,	KC_QUOT,
     KC_LSFT, 	KC_Z	, 		KC_X  , 		KC_C  , 		KC_V  , 		KC_B  ,                         KC_N  , KC_M  ,	KC_COMM,KC_DOT ,KC_SLSH,	CT_RSHFT,
                          		KC_LCTL,		KC_LALT,                                                						_______,		KC_RCTL,
			                                 	ALT_T(KC_ENT),	LCTL_T(KC_SPACE),                       				KC_SPACE, 		KC_ENT,
			                                  	KC_LBRC,		KC_RBRC,                 								KC_PGUP,  		KC_PGDN,
			                                  	KC_HOME,		KC_END,                        							KC_LBRC,		KC_DEL
			  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; } //LLOCK
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_Y)) SS_DELAY(100) SS_LALT(SS_TAP(X_1)) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_3));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_Y)) SS_DELAY(100) SS_TAP(X_1) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_A));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_Y)) SS_DELAY(100) SS_TAP(X_1) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_9));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_D)) SS_DELAY(100) SS_TAP(X_F) SS_DELAY(100) SS_TAP(X_F));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_F)) SS_DELAY(100) SS_LCTL(SS_TAP(X_V))  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_F10)) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(100) SS_TAP(X_V));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_F10)) SS_DELAY(100) SS_TAP(X_E) SS_DELAY(100) SS_TAP(X_E));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_E)) SS_DELAY(100) SS_TAP(X_S) SS_DELAY(100) SS_TAP(X_V)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)) SS_DELAY(2000) SS_TAP(X_U) SS_DELAY(1000) SS_TAP(X_U));

 	}
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_F10)) SS_DELAY(100) SS_TAP(X_T) SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F3) SS_DELAY(100) SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));

    }
    break;
    case ST_MACRO_11: //Excel go to visible ranges
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_G)) SS_DELAY(100) SS_LALT(SS_TAP(X_S)) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_Y)) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_2));

    }
    break;
  }
  return true;
};

//Tap Dance

void dance_rshft_finished(tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2: SEND_STRING(SS_LALT(SS_TAP(X_Y)) SS_DELAY(100) SS_TAP(X_1) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_3)); break;
    case 3: SEND_STRING(SS_LALT(SS_TAP(X_Y)) SS_DELAY(100) SS_TAP(X_1) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_4)); break;
    case 4: send_string_with_delay(PASSWORD1,20); SEND_STRING(SS_TAP(X_ENTER)); break; // SEND_STRING(SS_TAP(X_ENTER));
    case 5: send_string_with_delay(PASSWORD2,20); SEND_STRING(SS_TAP(X_ENTER)); break; // SEND_STRING(SS_TAP(X_ENTER));
    case 6: send_string_with_delay(PASSWORD3,20); break; //old windows password
    case 7: reset_keyboard();
    default: register_code(KC_RSFT);
  }
}

void dance_rshft_reset(tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2: break;
    case 3: break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: break;
    default: unregister_code(KC_RSFT);
  }
}

uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

// Create an instance of 'tap' for the 't' tap dance.
static tap ttap_state = {
    .is_press_action = true,
    .state = 0
};
static tap stap_state = {
    .is_press_action = true,
    .state = 0
};

void kc4_finished(tap_dance_state_t *state, void *user_data) {
    ttap_state.state = cur_dance(state);
    switch (ttap_state.state) {
        case SINGLE_TAP: register_code(KC_4); break;
        case SINGLE_HOLD: register_code(KC_LGUI); register_code(KC_DOWN); break;
        case DOUBLE_TAP: register_code(KC_LGUI); register_code(KC_RGHT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_4); register_code(KC_4);
    }
}

void kc4_reset(tap_dance_state_t *state, void *user_data) {
    switch (ttap_state.state) {
        case SINGLE_TAP: unregister_code(KC_4); break;
        case SINGLE_HOLD: unregister_code(KC_DOWN); unregister_code(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code(KC_RGHT); unregister_code(KC_LGUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_4);
    }
    ttap_state.state = 0;
}

void kc3_finished(tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_3); break;
        case SINGLE_HOLD: register_code(KC_LGUI); register_code(KC_UP); break;
        case DOUBLE_TAP: register_code(KC_LGUI); register_code(KC_LEFT); break;
        case TRIPLE_TAP: // this is for close remote desktop
            // Press Ctrl+Alt+Home
            register_code(KC_LCTL);
            register_code(KC_LALT);
            _delay_ms(100);
            tap_code(KC_HOME);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);

            // Short delay to ensure the keys are processed
            _delay_ms(200);

            // Press Alt+F4
            register_code(KC_LALT);
            tap_code(KC_F4);
            unregister_code(KC_LALT);
            break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_3); register_code(KC_3);
    }
}

void kc3_reset(tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_3); break;
        case SINGLE_HOLD: unregister_code(KC_UP); unregister_code(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code(KC_LEFT); unregister_code(KC_LGUI); break;
        case TRIPLE_TAP: break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_3);
    }
    stap_state.state = 0;
}

void end_finished(tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_END); break;
        case SINGLE_HOLD: register_code(KC_LCTL); register_code(KC_END); break;
        case DOUBLE_TAP: register_code(KC_LCTL); register_code(KC_LALT); _delay_ms(100); register_code(KC_HOME); break;
        case DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_HOME);
    }
}

void end_reset(tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_END); break;
        case SINGLE_HOLD: unregister_code(KC_END); unregister_code(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code(KC_HOME); _delay_ms(100); unregister_code(KC_LALT); unregister_code(KC_LCTL); break;
        case DOUBLE_HOLD: unregister_code(KC_HOME); unregister_code(KC_LCTL);
    }
    stap_state.state = 0;
}

void kc_up_finished(tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_UP); break;
        case SINGLE_HOLD: register_code(KC_PGUP); break;
        case DOUBLE_TAP: tap_code(KC_UP); register_code(KC_UP); break;
        case DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_UP); break;
        case TRIPLE_TAP: tap_code(KC_UP); tap_code(KC_UP); register_code(KC_UP); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_UP); register_code(KC_UP);
    }
}

void kc_up_reset(tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_UP); break;
        case SINGLE_HOLD: unregister_code(KC_PGUP); break;
        case DOUBLE_TAP: unregister_code(KC_UP); break;
        case DOUBLE_HOLD: unregister_code(KC_UP); unregister_code(KC_LCTL); break;
        case TRIPLE_TAP: unregister_code(KC_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_UP);
    }
    stap_state.state = 0;
}

void kc_down_finished(tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_DOWN); break;
        case SINGLE_HOLD: register_code(KC_PGDN); break;
        case DOUBLE_TAP: tap_code(KC_DOWN); register_code(KC_DOWN); break;
        case DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_DOWN); break;
        case TRIPLE_TAP: tap_code(KC_DOWN); tap_code(KC_DOWN); register_code(KC_DOWN); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_DOWN); register_code(KC_DOWN);
    }
}

void kc_down_reset(tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_DOWN); break;
        case SINGLE_HOLD: unregister_code(KC_PGDN); break;
        case DOUBLE_TAP: unregister_code(KC_DOWN); break;
        case DOUBLE_HOLD: unregister_code(KC_DOWN); unregister_code(KC_LCTL); break;
        case TRIPLE_TAP: unregister_code(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_DOWN);
    }
    stap_state.state = 0;
}

void kc_left_finished(tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_LEFT); break;
        case SINGLE_HOLD: register_code(KC_LALT); register_code(KC_PGUP); break;
        case DOUBLE_TAP: tap_code(KC_LEFT); register_code(KC_LEFT); break;
        case DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_LEFT); break;
        case TRIPLE_TAP: tap_code(KC_LEFT); tap_code(KC_LEFT); register_code(KC_LEFT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_LEFT); register_code(KC_LEFT);
    }
}

void kc_left_reset(tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code(KC_PGUP); unregister_code(KC_LALT); break;
        case DOUBLE_TAP: unregister_code(KC_LEFT); break;
        case DOUBLE_HOLD: unregister_code(KC_LEFT); unregister_code(KC_LCTL); break;
        case TRIPLE_TAP: unregister_code(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_LEFT);
    }
    stap_state.state = 0;
}

void kc_rght_finished(tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_RGHT); break;
        case SINGLE_HOLD: register_code(KC_LALT); register_code(KC_PGDN); break;
        case DOUBLE_TAP: tap_code(KC_RGHT); register_code(KC_RGHT); break;
        case DOUBLE_HOLD: register_code(KC_LCTL); register_code(KC_RGHT); break;
        case TRIPLE_TAP: tap_code(KC_RGHT); tap_code(KC_RGHT); register_code(KC_RGHT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_RGHT); register_code(KC_RGHT);
    }
}

void kc_rght_reset(tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_RGHT); break;
        case SINGLE_HOLD: unregister_code(KC_PGDN); unregister_code(KC_LALT); break;
        case DOUBLE_TAP: unregister_code(KC_RGHT); break;
        case DOUBLE_HOLD: unregister_code(KC_RGHT); unregister_code(KC_LCTL); break;
        case TRIPLE_TAP: unregister_code(KC_RGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code(KC_RGHT);
    }
    stap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [CT_RSHFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rshft_finished, dance_rshft_reset),
    [KC4_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc4_finished, kc4_reset),
    [KC3_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc3_finished, kc3_reset),
    [END_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, end_finished, end_reset),
    [KC_UP_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_up_finished, kc_up_reset),
    [KC_DOWN_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_down_finished, kc_down_reset),
    [KC_LEFT_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_left_finished, kc_left_reset),
    [KC_RGHT_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, kc_rght_finished, kc_rght_reset),
};

//HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_Z):
            // Immediately select the hold action when another key is pressed.
            return true;
        case ALT_T(KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LCTL_T(KC_SPACE):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LGUI_T(KC_HOME):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
