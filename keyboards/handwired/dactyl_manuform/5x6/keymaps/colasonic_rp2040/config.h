/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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
//for rp2040
#define MCU RP2040
#define BOOTLOADER rp2040

#pragma once

#define MASTER_LEFT
//#define MASTER_RIGHT
#define TAPPING_TERM 200 //this is for some high latency connections like vpn
//#define EE_HANDS
#define TAPPING_TOGGLE 2
//auto shift
#define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_SPECIAL
#define RETRO_SHIFT 500
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET