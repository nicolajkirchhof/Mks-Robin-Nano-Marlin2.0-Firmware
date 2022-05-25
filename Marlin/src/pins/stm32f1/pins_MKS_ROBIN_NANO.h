/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * MKS Robin nano (STM32F103VET6) board pin assignments
 * https://github.com/makerbase-mks/MKS-Robin-Nano-V1.X/tree/master/hardware
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME "Kywoo3D"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_JTAG

//
// Thermocouples
//
//#define TEMP_0_CS_PIN                     PE5   // TC1 - CS1
//#define TEMP_0_CS_PIN                     PE6   // TC2 - CS2

//#define LED_PIN                           PB2

#include "pins_MKS_ROBIN_NANO_common.h"

#if HAS_TMC_UART

#define X_SERIAL_TX_PIN PA10
#define X_SERIAL_RX_PIN PA10

#define Y_SERIAL_TX_PIN PA9
#define Y_SERIAL_RX_PIN PA9

#define Z_SERIAL_TX_PIN PC7
#define Z_SERIAL_RX_PIN PC7

#define E0_SERIAL_TX_PIN PC13
#define E0_SERIAL_RX_PIN PC13

// Reduce baud rate to improve software serial reliability
#define TMC_BAUD_RATE 19200
#endif // HAS_TMC_UART
 //
// Misc. Functions
//

#if HAS_TFT_LVGL_UI
  // LVGL
  #ifndef TOUCH_CALIBRATION_X
    #define TOUCH_CALIBRATION_X             17880
  #endif
  #ifndef TOUCH_CALIBRATION_Y
    #define TOUCH_CALIBRATION_Y            -12234
  #endif
  #ifndef TOUCH_OFFSET_X
    #define TOUCH_OFFSET_X                    -45
  #endif
  #ifndef TOUCH_OFFSET_Y
    #define TOUCH_OFFSET_Y                    349
  #endif
  #ifndef TOUCH_ORIENTATION
    #define TOUCH_ORIENTATION    TOUCH_LANDSCAPE
  #endif

  //#define MKSPWC
  #ifdef MKSPWC
    #define SUICIDE_PIN                     PB2   // Enable MKSPWC SUICIDE PIN
    #define SUICIDE_PIN_INVERTING          false  // Enable MKSPWC PIN STATE
    #define KILL_PIN                        PA2   // Enable MKSPWC DET PIN
    #define KILL_PIN_STATE                  true  // Enable MKSPWC PIN STATE
  #endif

  #define MT_DET_1_PIN                      PA4   // LVGL UI FILAMENT RUNOUT1 PIN
  #define MT_DET_2_PIN                      PE6   // LVGL UI FILAMENT RUNOUT2 PIN
  #define MT_DET_PIN_INVERTING             false  // LVGL UI filament RUNOUT PIN STATE

  #define WIFI_IO0_PIN                      PC13  // MKS ESP WIFI IO0 PIN
  #define WIFI_IO1_PIN                      PC7   // MKS ESP WIFI IO1 PIN
  #define WIFI_RESET_PIN                    PA5   // MKS ESP WIFI RESET PIN
#else
  //#define POWER_LOSS_PIN                  PA2   // PW_DET
  //#define PS_ON_PIN                       PB2   // PW_OFF
  #define FIL_RUNOUT_PIN                    PA4
  #define FIL_RUNOUT2_PIN                   PE6
#endif
