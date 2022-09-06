/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define ART_ENABLE
#define CAPS_WORD_IDLE_TIMEOUT 5000
#define CASE_MODES_ENABLE
#define GAMING_ENABLE
#define IGNORE_MOD_TAP_INTERRUPT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
#define RGBLIGHT_LAYERS
#define TAPPING_TERM 200

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

/* Select hand configuration */
// #define MASTER_RIGHT
// #define EE_HANDS
