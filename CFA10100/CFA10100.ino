//===========================================================================
//
// Crystalfontz FT8xx Seeeduino Simple Demonstration Program
//
// Code written for Seeeduino v4.2 set to 3.3v (important!)
// Seeeduino v4.2 is an Arduino Uno clone that can run at 3.3v.
//
//---------------------------------------------------------------------------
//
// This is a simplified / refactored version of the code in FTDI's AN_275:
//
//  http://brtchip.com/wp-content/uploads/Support/Documentation/Application_Notes/ICs/EVE/AN_275_FT800_Example_with_Arduino.pdf
//
// I have added support for the FT81x series.
//
// The write offset into the write buffer is passed into and back from
// functions rather than being a global.
//
// In the spirit of AN_275:
//
//   An “abstraction layer” concept was explicitly avoided in this
//   example. Rather, direct use of the Arduino libraries demonstrates
//   the simplicity of sending and receiving data through the FT800
//   while producing a graphic output.
//
// My main goal here is to be transparent about what is really happening
// from the high to lowest levels, without obfuscation, while still
// at least giving a nod to good programming practices.
//
// Plus, you probably don't have RAM and flash for all those fancy
// programming layers.
//
// A nod to Rudolf R and company over at
//   https://www.mikrocontroller.net/topic/395608
// for help understanding that the FT81x needs a 24-bit (full color)
// PNG, not an 8-bit paletized PNG.
//
//  2018 - 10 - 27 Brent A. Crosby / Crystalfontz
//---------------------------------------------------------------------------
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
// Adapted from:
// FTDIChip AN_275 FT800 with Arduino - Version 1.0
//
// Copyright (c) Future Technology Devices International
//
// THIS SOFTWARE IS PROVIDED BY FUTURE TECHNOLOGY DEVICES INTERNATIONAL
// LIMITED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL FUTURE TECHNOLOGY
// DEVICES INTERNATIONAL LIMITED BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES LOSS OF USE,
// DATA, OR PROFITS OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// This code is provided as an example only and is not guaranteed by
// FTDI/BridgeTek. FTDI/BridgeTek accept no responsibility for any issues
// resulting from its use. By using this code, the developer of the final
// application incorporating any parts of this sample project agrees to take
// full responsible for ensuring its safe and correct operation and for any
// consequences resulting from its use.
//===========================================================================
#include <Arduino.h>
#include <SPI.h>
#include <stdarg.h>
// Definitions for our display.
#include "CFA10100_defines.h"
#include "CFAF800480_050T.h"
// Transparent Logo
#include "CFAM800480xx-050T_Splash_PNG.h"
#include "CFAM800480xx-050T_Splash_ARGB2.h"

#if BUILD_SD
#include <SD.h>
#endif

// The FT80x registers are different compared to the FT81x. Choose the FT81x.
#define FT_81X_ENABLE
#include "FT8xx_defines.h"
#include "FT8xx_base.h"
#include "FT8xx_draw.h"
//Demonstrations of various FT8xx functions
#include "demos.h"
//============================================================================
// ref http://playground.arduino.cc/Main/Printf
//
// Example to dump a uint32_t in hex and decimal
//   SerPrintFF(F("RAM_G_Unused_Start: 0x%08lX = %lu\n"),RAM_G_Unused_Start,RAM_G_Unused_Start);
// Example to dump a uint16_t in hex and decimal
//   SerPrintFF(F("Initial Offest Read: 0x%04X = %u\n"),FWo ,FWo);
void SerPrintFF(const __FlashStringHelper *fmt, ... )
  {
  char
    tmp[128]; // resulting string limited to 128 chars
  va_list
    args;
  va_start(args, fmt );
  vsnprintf_P(tmp, 128, (const char *)fmt, args);
  va_end (args);
  Serial.print(tmp);
  }
//===========================================================================
void setup()
  {
  // Initialize UART for debugging messages
  Serial.begin(9600);
  Serial.println(F("Begin"));

  //Initialize GPIO port states
  // Set CS# high to start - SPI inactive
  SET_FTDI_CS_NOT;
  // Set PD# high to start
  SET_FTDI_PD_NOT;
  SET_SD_CS_NOT;

  //Initialize port directions
  // FT800 interrupt output (not used in this example)
  pinMode(FTDI_INT, INPUT_PULLUP);
  // FT800 Power Down (reset) input
  pinMode(FTDI_PD_NOT, OUTPUT);
  // FT800 SPI bus CS# input
  pinMode(FTDI_CS_NOT, OUTPUT);
  // USD card CS
  pinMode(SD_CS, OUTPUT);
  pinMode(DEBUG_LED, OUTPUT);

  // Initialize SPI
  SPI.begin();
  //Bump the clock to 8MHz. Appears to be the maximum.
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));

#if BUILD_SD
  // The prototype hardware appears to functon fine at 8MHz which
  // also appears to be the max that the ATmega328P can do.
  if (!SD.begin(8000000,SD_CS))
    {
    Serial.println(F("uSD card failed to initialize, or not present"));
    //Reset the SPI clock to fast. SD card library does not clean up well.
    //Bump the clock to 8MHz. Appears to be the maximum.
    SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
    }
  else
    {
    Serial.println(F("uSD card initialized."));
    }
#endif

  //See if we can find the FTDI FT8xx processor
  if(0 != FT8xx_Init())
    {
    // Send an error message on the UART
    Serial.println(F("FT8xx_Init() failed."));
    }
  } //  setup()
//===========================================================================
void loop()
  {
  Serial.println("Loop.");

#if (0 != BOUNCE_DEMO)
  SerPrintFF(F("Initialize_Bounce_Demo() . . ."));
  Initialize_Bounce_Demo();
  SerPrintFF(F(" done.\n"));
#endif // BOUNCE_DEMO

  //Get the currrent write pointer from the FT81x
  uint16_t
    FWo;
  FWo = FT8xx_REG_Read_16(REG_CMD_WRITE);
  SerPrintFF(F("Initial Offest Read: 0x%04X = %u\n"),FWo ,FWo);

  //Keep track of the RAM_G memory allocation
  uint32_t
    RAM_G_Unused_Start;
  RAM_G_Unused_Start=0;
  SerPrintFF(F("Initial RAM_G: 0x%08lX = %lu\n"),RAM_G_Unused_Start,RAM_G_Unused_Start);

#if (0 != LOGO_DEMO)
  SerPrintFF(F("Initialize_Logo_Demo() . . ."));
  FWo=Initialize_Logo_Demo(FWo,&RAM_G_Unused_Start);
  SerPrintFF(F(" done.\n"));
  SerPrintFF(F("RAM_G after logo: 0x%08lX = %lu\n"),RAM_G_Unused_Start,RAM_G_Unused_Start);
#endif // LOGO_DEMO

#if (0 != BMP_DEMO)
  SerPrintFF(F("Initialize_Bitmap_Demo() . . ."));
  FWo=Initialize_Bitmap_Demo(FWo,&RAM_G_Unused_Start);
  SerPrintFF(F(" done.\n"));
  SerPrintFF(F("RAM_G after bitmap: 0x%08lX = %lu\n"),RAM_G_Unused_Start,RAM_G_Unused_Start);
#endif // BMP_DEMO

#if (0 != SOUND_DEMO)
  SerPrintFF(F("Initialize_Sound_Demo() . . ."));
  FWo=Initialize_Sound_Demo(FWo,&RAM_G_Unused_Start);
  SerPrintFF(F(" done.\n"));
  SerPrintFF(F("RAM_G after sound: 0x%08lX = %lu\n"),RAM_G_Unused_Start,RAM_G_Unused_Start);
#endif // SOUND_DEMO

#if MARBLE_DEMO
  //Load the Blue Marble bitmap from the uSD to the RAM_G
  uint32_t
    Marble_RAM_G_Length;
  FWo=Initialize_Marble_Demo(FWo,
                             RAM_G_Unused_Start,
                             &Marble_RAM_G_Length);

  if(0==Marble_RAM_G_Length)
    {
    SerPrintFF(F("Error loading BLUEMARB.RAW from uSD.\n"));
    }
  //Keep track of the RAM_G memory allocation, force to 8-byte aligned
  RAM_G_Unused_Start=(RAM_G_Unused_Start+Marble_RAM_G_Length+0x07)&0xFFFFFFF8;
  SerPrintFF(F("RAM_G after marble: 0x%08lX = %lu\n"),RAM_G_Unused_Start,RAM_G_Unused_Start);
#endif //MARBLE_DEMO

#if TOUCH_DEMO
#if (TOUCH_TYPE != TOUCH_NONE)
  //Bitmask of valid points in the array
  uint8_t
      points_touched_mask;
#if (TOUCH_TYPE == TOUCH_RESISTIVE)
  int16_t
    x_points[1];
  int16_t
    y_points[1];
#endif // (TOUCH_TYPE == TOUCH_RESISTIVE)

#if (TOUCH_TYPE == TOUCH_CAPACITIVE)
  int16_t
    x_points[5];
  int16_t
    y_points[5];
#endif // (TOUCH_TYPE == TOUCH_CAPACITIVE)
  //Ask the user to calibrate the touch screen.
  FWo=Stop_Busy_Spinner_Screen(FWo,
                               //clear color
                               CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                               //text color
                               COLOR_RGB(0xFF,0xFF,0xFF),
                               F("Calibrate Touch"));
  FWo=Calibrate_Touch(FWo);

#if (TOUCH_TYPE==TOUCH_CAPACITIVE)
  //Capacitive.
  //Set multi-touch mode. You gots to do this _after_ the calibration.
  FT8xx_REG_Write_8(REG_CTOUCH_EXTEND, CTOUCH_EXTEND_EXTENDED);
#endif // (TOUCH_TYPE==TOUCH_CAPACITIVE)
  //Wait for the user to get their finger off the display--except
  //the cal does not exit until the finger is up -- so why does
  //this loop get executed up to ~ 85 times (for capacitive with
  //Goodix)? Removing this loop gives an initial, invalid, "false
  //touch" when the touch is read in the main loop. Very odd.
  do
    { 
    //Read the touch screen.
    points_touched_mask=Read_Touch(x_points,y_points);
    } while(0!=points_touched_mask);
#endif // (TOUCH_TYPE != TOUCH_NONE)
#endif // TOUCH_DEMO

  while(1)
    {
    //========== FRAME SYNCHRONIZING ==========
    // Wait for graphics processor to complete executing the current command
    // list. This happens when REG_CMD_READ matches REG_CMD_WRITE, indicating
    // that all commands have been executed.  We have a local copy of
    // REG_CMD_WRITE in FWo.
    //
    // This appears to only occur on frame completion, which is nice since it
    // allows us to step the animation along at a reasonable rate.
    //
    // If possible, I have tweaked the timing on the Crystalfontz displays
    // to all have ~60Hz frame rate.
    Wait_for_FT8xx_Execution_Complete(FWo);

#if TOUCH_DEMO
#if (TOUCH_TYPE != TOUCH_NONE)
    //Read the touch screen.
    points_touched_mask=Read_Touch(x_points,y_points);
#endif //  (TOUCH_TYPE != TOUCH_NONE)
#endif // TOUCH_DEMO

#if SOUND_DEMO
    //See if we should play a sound. The sound will synchronize
    //with the the start of the logo rotation.
    //If the previous sound is still playing it will wait until the
    //next time we call it.
//    Start_Sound_Demo_Playing();
#endif //SOUND_DEMO

    //========== START THE DISPLAY LIST ==========
    // Start the display list
    FWo=FT8xx_Cmd_Dat_0(FWo, (CMD_DLSTART));
    // Set the default clear color to black
    FWo=FT8xx_Cmd_Dat_0(FWo, CLEAR_COLOR_RGB(0,0,0));
    // Clear the screen - this and the previous prevent artifacts between lists
    FWo=FT8xx_Cmd_Dat_0(FWo,
                        CLEAR(1 /*CLR_COL*/,1 /*CLR_STN*/,1 /*CLR_TAG*/));

    //========== ADD GRAPHIC ITEMS TO THE DISPLAY LIST ==========

    //Fill background with white
    FWo=FT8xx_Filled_Rectangle(FWo,
                               0,0,LCD_WIDTH-1,LCD_HEIGHT-1);

#if (0 != BMP_DEMO)
    FWo=Add_Bitmap_To_Display_List(FWo);
#endif // BMP_DEMO

#if MARBLE_DEMO
#if TOUCH_DEMO
    //See if we are touched at all.
    if(0 != points_touched_mask)
      {
      //Loop through the possible touch points
      uint8_t
        mask;
      mask=0x01;
      for(uint8_t i=0;i<5;i++)
        {
        if(0 != (points_touched_mask&mask))
          {
#if 1     //If BILINEAR is chosen for the marble, adding many exceeds
          //the work the proessor can complete in one line
          //Set the marble's position
          Force_Marble_Position(x_points[i]*16,y_points[i]*16);
          //Put a marble there
          FWo=Add_Marble_To_Display_List(FWo);
#else     //colored dots
          static uint32_t colors[5]=
            {
            COLOR_RGB(0x00,0x00,0xFF),
            COLOR_RGB(0x00,0xFF,0x00),
            COLOR_RGB(0xFF,0x00,0x00),
            COLOR_RGB(0xFF,0x00,0xFF),
            COLOR_RGB(0xFF,0xFF,0x00)
            };
          FWo=FT8xx_Cmd_Dat_0(FWo,
                              colors[i]);
          // Make it solid
          FWo=FT8xx_Cmd_Dat_0(FWo,
                              COLOR_A(0xFF));
          // Draw the touch dot -- a 60px point (filled circle)
          FWo=FT8xx_Point(FWo,
                          x_points[i]*16,
                          y_points[i]*16,
                          60*16);
#endif
          }
        mask<<=1;
        }
      }
    else  // (0 != points_touched_mask)
      {
      //No points were touched
      //Just display one marble wherever it would normally be
      FWo=Add_Marble_To_Display_List( FWo);
      }
#else //TOUCH_DEMO
    //Marble demo is on and touch demo is off
    FWo=Add_Marble_To_Display_List( FWo);
#endif // TOUCH_DEMO
#endif // MARBLE_DEMO

#if BOUNCE_DEMO
    //========== BOUNCY BALL $ RUBBER BAND ==========
    FWo=Add_Bounce_To_Display_List( FWo);
#endif //BOUNCE_DEMO

#if BOUNCE_DEMO && TOUCH_DEMO
    //See if we are touched at all.
    if(0 != points_touched_mask)
      {
      //Loop through the possible touch points
      uint8_t
        mask;
      mask=0x01;
      for(uint8_t i=0;i<5;i++)
        {
        if(0 != (points_touched_mask&mask))
          {
          //colored dots
          static uint32_t colors[5]=
            {
            COLOR_RGB(0x00,0x00,0xFF),
            COLOR_RGB(0x00,0xFF,0x00),
            COLOR_RGB(0xFF,0x00,0x00),
            COLOR_RGB(0xFF,0x00,0xFF),
            COLOR_RGB(0xFF,0xFF,0x00)
            };
          FWo=FT8xx_Cmd_Dat_0(FWo,
                              colors[i]);
          // Make it solid
          FWo=FT8xx_Cmd_Dat_0(FWo,
                              COLOR_A(0xFF));
          // Draw the touch dot -- a 60px point (filled circle)
          FWo=FT8xx_Point(FWo,
                          x_points[i]*16,
                          y_points[i]*16,
                          60*16);
          }
        mask<<=1;
        }
      }
#endif //BOUNCE_DEMO && TOUCH_DEMO

#if (0 != LOGO_DEMO)
    FWo=Add_Logo_To_Display_List(FWo);
#endif // (0 != LOGO_DEMO)

    //========== FINSH AND SHOW THE DISPLAY LIST ==========
    // Instruct the graphics processor to show the list
    FWo=FT8xx_Cmd_Dat_0(FWo, DISPLAY());
    // Make this list active
    FWo=FT8xx_Cmd_Dat_0(FWo, CMD_SWAP);
    // Update the ring buffer pointer so the graphics processor starts executing
    FT8xx_REG_Write_16(REG_CMD_WRITE, (FWo));

#if BOUNCE_DEMO
    //========== MOVE THE BALL AND CYCLE COLOR AND TRANSPARENCY ==========
    Bounce_Ball();
#endif //BOUNCE_DEMO

#if MARBLE_DEMO
    //========== BOUNCE THE MARBLE AROUND ==========
    Move_Marble();
#endif //MARBLE_DEMO
    }  // while(1)
  } // loop()
//===========================================================================
