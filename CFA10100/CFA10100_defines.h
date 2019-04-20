#ifndef __CFA10010_DEFINES_H__
#define __CFA10010_DEFINES_H__
//============================================================================
//
// Definitions specific to the CFA10100 board.
//
// 2018-11-21 Crystalfontz America, Inc. / Brent A. Crosby
//===========================================================================
//This is free and unencumbered software released into the public domain.
//
//Anyone is free to copy, modify, publish, use, compile, sell, or
//distribute this software, either in source code form or as a compiled
//binary, for any purpose, commercial or non-commercial, and by any
//means.
//
//In jurisdictions that recognize copyright laws, the author or authors
//of this software dedicate any and all copyright interest in the
//software to the public domain. We make this dedication for the benefit
//of the public at large and to the detriment of our heirs and
//successors. We intend this dedication to be an overt act of
//relinquishment in perpetuity of all present and future rights to this
//software under copyright law.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//OTHER DEALINGS IN THE SOFTWARE.
//
//For more information, please refer to <http://unlicense.org/>
//============================================================================

//////////////////////////////////////////////////////////////////////////////
// Do Not Change These, use them in the settings below. //////////////////////
#define TOUCH_NONE       (0)
#define TOUCH_RESISTIVE  (1)
#define TOUCH_CAPACITIVE (2)
#define CAP_DEV_DEFAULT  (0)
#define CAP_DEV_GT911    (1)
//////////////////////////////////////////////////////////////////////////////

#define DEVICE (FT813)
//#define TOUCH_TYPE (TOUCH_NONE)
//define TOUCH_TYPE (TOUCH_RESISTIVE)
#define TOUCH_TYPE (TOUCH_CAPACITIVE)
//#define TOUCH_CAP_DEVICE (CAP_DEV_DEFAULT)
#define TOUCH_CAP_DEVICE (CAP_DEV_GT911)

//Need the SD card to read in the audio file and background bitmap
#define CHATTY      (10)

//You can enable/disable the different demos here.
//There is not enough RAM_G space to hold all of the scrolling background,
//logo, audio, and blue marble at the same time

#define BMP_DEMO             (0)  //Background, uses uSD
#define   BMP_SCROLL         (1)  //1=scrolling background, 0=static image
#define SOUND_DEMO           (0)  //Uses uSD
#define   SOUND_VOICE        (0)  //1=VOI_8K.RAW, 0=MUS_8K.RAW
#define   SOUND_PLAY_TIMES   (10)
#define LOGO_DEMO            (1)  //Rotating logo (image in flash, no uSD)
#define   LOGO_PNG_0_ARGB2_1 (1)  //Compressed ARGB is 5614 bytes smaller
#define BOUNCE_DEMO          (1)
#define MARBLE_DEMO          (0)  //Uses uSD
#define TOUCH_DEMO           (1)
//----------------------------------------------------------------------------
// Turn on uSD code if one of the demos above uses it.
#if ((0 != SOUND_DEMO) || (0 != BMP_DEMO) || (0 != MARBLE_DEMO))
  #define BUILD_SD           (1)
#else
  #define BUILD_SD           (0)
#endif
//============================================================================
// Wiring for prototypes.
//   ARD      | Port | 10098/FT8xx         | Color
// -----------+------+---------------------|--------
//  #3/D3     |  PD3 | DEBUG_LED           | Green W/W
//  #7/D7     |  PD7 | FTDI_INT            | Purple
//  #8/D8     |  PB0 | FTDI_PD_NOT         | Blue
//  #9/D9     |  PB1 | FTDI_CS_NOT         | Brown
// #10/D10    |  PB2 | SD_CS_NOT           | Grey
// #11/D11    |  PB3 | MOSI (hardware SPI) | Yellow
// #12/D12    |  PB4 | MISO (hardware SPI) | Green
// #13/D13    |  PB5 | SCK  (hardware SPI) | orange

//Arduino style pin defines
// Interrupt from FT800 to Arduino - input, nou used in this example.
#define FTDI_INT    (7)
// PD_N from Arduino to FT800 - effectively FT800 reset
#define FTDI_PD_NOT (8)
// SPI chip select - defined separately since it's manipulated with GPIO calls
#define FTDI_CS_NOT (9)
// Reserved for use with the SD card library
#define SD_CS       (10)
// Debug LED, or used for scope triggeer or timing
#define DEBUG_LED   (3)

//Faster direct port access
#define CLR_FTDI_PD_NOT       (PORTB &= ~(0x01))
#define SET_FTDI_PD_NOT       (PORTB |=  (0x01))
#define CLR_FTDI_CS_NOT       (PORTB &= ~(0x02))
#define SET_FTDI_CS_NOT       (PORTB |=  (0x02))
#define CLR_SD_CS_NOT         (PORTB &= ~(0x04))
#define SET_SD_CS_NOT         (PORTB |=  (0x04))
#define CLR_MOSI              (PORTB &= ~(0x08))
#define SET_MOSI              (PORTB |=  (0x08))
#define CLR_MISO              (PORTB &= ~(0x10))
#define SET_MISO              (PORTB |=  (0x10))
#define CLR_SCK               (PORTB &= ~(0x20))
#define SET_SCK               (PORTB |=  (0x20))

#define CLR_DEBUG_LED         (PORTD &= ~(0x08))
#define SET_DEBUG_LED         (PORTD |=  (0x08))
//----------------------------------------------------------------------------
void SerPrintFF(const __FlashStringHelper *fmt, ... );
//============================================================================
#endif // __CFA10010_DEFINES_H__
