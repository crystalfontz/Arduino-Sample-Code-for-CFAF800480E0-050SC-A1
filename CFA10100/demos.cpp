//============================================================================
//
// Some demo routines for Crystalfontz CFA10100 FT8xx accelerated displays.
//
// These routines _could_ be made into classes. But in real life, there is
// not resources available to instantiate more than one of them at a time.
// Because of this I have just kept them simple and hopefully
// more understandable.
//
// The format is:
//   variables (global but limited in scope to this file)
//   init()
//   draw()
//   move()
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
//===========================================================================
#if TOUCH_DEMO
uint16_t Add_Touch_Dot_To_Display_List(uint16_t FWol,
                                       uint16_t touch_x,
                                       uint16_t touch_y)
  {
  //See if we are touched at all. Coordinates will be large if not.
  if(touch_x<1200)
    {
    // Set the variable color of the tocuhed dot to green.
    FWol=FT8xx_Cmd_Dat_0(FWol,
                         COLOR_RGB(0x00,0xFF,0x00));
    // Make it solid
    FWol=FT8xx_Cmd_Dat_0(FWol,
                         COLOR_A(0xFF));

    // Draw the touch dot -- a 60px point (filled circle)
    FWol=FT8xx_Point(FWol,
                     touch_x*16,
                     touch_y*16,
                     60*16);
    }
  //Give the updated write pointer back to the caller
  return(FWol);
  }
#endif //TOUCH_DEMO
//===========================================================================
#if (0 != BMP_DEMO)
//For a static background image, set BMP_SCROLL to 0
//We will select the file name based on that.

//Address of the 565 bitmap image in RAM_G
uint32_t
  Bitmap_RAM_G_Address;
//Length of the image in RAM_G
uint32_t
  Bitmap_RAM_G_Length;

//Keep track of where the background is as it slides arouns in a loop
int16_t
  background_slide;
uint8_t
  background_slide_slow;

#if BMP_DEMO
#endif // BMP_DEMO
//---------------------------------------------------------------------------
uint16_t Initialize_Bitmap_Demo(uint16_t FWol,
                                uint32_t *RAM_G_Unused_Start)
  {
  //Since the Arduino uSD card is slow, put up a "please wait" screen.
  FWol=Start_Busy_Spinner_Screen(FWol,
                                 //clear color
                                 CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                                 //text color
                                 COLOR_RGB(0xFF,0xFF,0xFF),
                                 //spinner color
                                 COLOR_RGB(0x00,0xFF,0x00),
#if (0 != BMP_SCROLL)
                                 F("Loading \"CLOUDS.RAW\" . . ."));
#else
                                 F("Loading \"SPLASH.RAW\" . . ."));
#endif

  //Start the slide at position 0.
  background_slide=0;
  background_slide_slow=0;

  //Attempt to load our RAW bitmap file from the uSD into RAM_G
  Bitmap_RAM_G_Address=*RAM_G_Unused_Start;
  Bitmap_RAM_G_Length=0;

  //If the Audio_RAM_G_Length returned is 0, then it has probably failed.
  //Not much to do in the way of error recovery though, as the FT8xx
  //would just be instructed to play a 0-lenght RAM_G buffer, which
  //hopefully it handles gracefully.
  //By the way, it appears that the SD library reports all file names
  //in all upper case. So even though Windows file explorer, CMD,
  //and Power Shell all report the name as lower case, we need to
  //feed the SD library an all uppercase string.
  Load_File_To_RAM_G(Bitmap_RAM_G_Address,
#if BMP_SCROLL
                     "CLOUDS.RAW",
#else
                     "SPLASH.RAW",
#endif
                     &Bitmap_RAM_G_Length);

  //Keep track of the RAM_G memory allocation, force to 8-byte aligned
  *RAM_G_Unused_Start=(*RAM_G_Unused_Start+Bitmap_RAM_G_Length+0x07)&0xFFFFFFF8;
  FWol=Stop_Busy_Spinner_Screen(FWol,
                                //clear color
                                CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                                //text color
                                COLOR_RGB(0xFF,0xFF,0xFF),
                                F("Done."));
  //Pass our updated offset back to the caller
  return(FWol);
  }
//---------------------------------------------------------------------------
uint16_t Add_Bitmap_To_Display_List(uint16_t FWol)
  {
  //We have two (LCD_WIDTH/2)xLCD_HEIGHT (400x480) tiles stored in RAM_G.
  //This is to overcome the 512x512 maximum bitmap limitation.
  //The particular image we have is seemlessly tileable in x -- letting
  //us make a continous scenery wheel scroll of the background
  uint32_t
    RAM_G_Address_1_and_3;
  uint32_t
    RAM_G_Address_2;
  int16_t
    tile_offset;

#if (0==BMP_SCROLL) //1 for scroll, 0 for static bitmap
  background_slide=400;
#endif // (0==BMP_SCROLL)

  //We will loop background_slide from 0 to LCD_WIDTH-1
  if(background_slide<400)
    {
    //The first tile starts up to LCD_WIDTH/2 pixels to the left of the visible
    //display.
    tile_offset=background_slide-(LCD_WIDTH/2);
    //Get the adresses of the tiles in RAM_G
    RAM_G_Address_1_and_3=Bitmap_RAM_G_Address;
    // 400x480x2 = 384000
    RAM_G_Address_2=Bitmap_RAM_G_Address+384000UL;
    }
  else
    {
    //The first tile starts up to LCD_WIDTH pixels to the left of the visible
    //display.
    tile_offset=background_slide-LCD_WIDTH;
    //Get the adresses of the tiles in RAM_G
    // 400x480x2 = 384000
    RAM_G_Address_1_and_3=Bitmap_RAM_G_Address+384000UL;
    RAM_G_Address_2=Bitmap_RAM_G_Address;
    }

  // Set the drawing color to white
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_A(255));

#if (1==BMP_SCROLL) //1 for scroll, 0 for static bitmap
  //First tile: pull the uncompressed RGB565 image from RAM_G onto the screen
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BEGIN(BITMAPS));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SOURCE(RAM_G_Address_1_and_3));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_LAYOUT(RGB565,(LCD_WIDTH/2)*2,LCD_HEIGHT));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SIZE(NEAREST,BORDER,BORDER,LCD_WIDTH/2,LCD_HEIGHT));
  //Render the bitmap it to the current frame
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       VERTEX2F((tile_offset)*16,0*16));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       END());
#endif // (1==BMP_SCROLL)

  //Second tile, move over LCD_WIDTH/2 pixels.
  tile_offset+=LCD_WIDTH/2;

  //Pull the uncompressed RGB565 image from RAM_G onto the screen
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BEGIN(BITMAPS));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SOURCE(RAM_G_Address_2));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_LAYOUT(RGB565,(LCD_WIDTH/2)*2,LCD_HEIGHT));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SIZE(NEAREST,BORDER,BORDER,(LCD_WIDTH/2),LCD_HEIGHT));
  //Render the bitmap it to the current frame
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       VERTEX2F((tile_offset)*16,0*16));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       END());

  //Third tile, move over LCD_WIDTH/2 pixels.
  tile_offset+=LCD_WIDTH/2;

  //Pull the uncompressed RGB565 image from RAM_G onto the screen
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BEGIN(BITMAPS));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SOURCE(RAM_G_Address_1_and_3));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_LAYOUT(RGB565,(LCD_WIDTH/2)*2,LCD_HEIGHT));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SIZE(NEAREST,BORDER,BORDER,(LCD_WIDTH/2),LCD_HEIGHT));
  //Render the bitmap it to the current frame
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       VERTEX2F((tile_offset)*16,0*16));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       END());

#if (1==BMP_SCROLL) //1 for scroll, 0 for static bitmap
  //Slide the background along at 1/3 frame rate ~20Hz
  if(0==background_slide_slow)
    {
    background_slide_slow=3;
    if(background_slide < LCD_WIDTH)
      {
      background_slide++;
      }
    else
      {
      background_slide=0;
      }
    }
  else
    {
    background_slide_slow--;
    }
#endif // (0==BMP_SCROLL)

  //Pass our updated offset back to the caller
  return(FWol);
  }
#endif // BMP_DEMO
//===========================================================================
#if MARBLE_DEMO
//Keep track of the Marble
int32_t
  marble_x_pos;
int32_t
  marble_x_vel;
int32_t
  marble_y_pos;
int32_t
  marble_y_vel;
int32_t
  marble_rotation;
int32_t
  marble_spin;
uint32_t
  Marble_RAM_G_Address;
uint32_t
  marble_width;
uint32_t
  marble_height;
//---------------------------------------------------------------------------
//Retuns the number of bytes it used in RAM_G.
//Requires uSD
uint16_t Initialize_Marble_Demo(uint16_t FWol,
                                uint32_t RAM_G_Unused_Start,
                                uint32_t *Marble_RAM_G_Length)
  {
  //Start somewhere reasonable
  marble_x_pos=LCD_WIDTH*(16/2);
  marble_x_vel=48;
  marble_y_pos=LCD_HEIGHT*(16/2);
  marble_y_vel=-32;
  marble_rotation=0;
  marble_spin=0;

  //Since the Arduino uSD card is slow, put up a please wait screen.
  FWol=Start_Busy_Spinner_Screen(FWol,
                                 //clear color
                                 CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                                 //text color
                                 COLOR_RGB(0xFF,0xFF,0xFF),
                                 //spinner color
                                 COLOR_RGB(0x00,0xFF,0x00),
                                 F("Loading \"BLUEMARB.RAW\" . . ."));

  //Attempt to load our RAW bitmap file from the uSD into RAM_G
  Marble_RAM_G_Address=RAM_G_Unused_Start;

  //You have to know ahead of time how big the image is and what
  //format it is in. Load_File_To_RAM_G just moves the data.
  marble_width=240;
  marble_height=240;


  //If the Marble_RAM_G_Length returned is 0, then it has probably failed.
  *Marble_RAM_G_Length=0;
  //Not much to do in the way of error recovery though, as the FT8xx
  //would just be instructed to play a 0-lenght RAM_G buffer, which
  //hopefully it handles gracefully.
  //By the way, it appears that the SD library reports all file names
  //in all upper case. So even though Windows file explorer, CMD,
  //and Power Shell all report the name as lower case, we need to
  //feed the SD library an all uppercase string.
  Load_File_To_RAM_G(Marble_RAM_G_Address,
                     "BLUEMARB.RAW",
                     Marble_RAM_G_Length);

  FWol=Stop_Busy_Spinner_Screen(FWol,
                                //clear color
                                CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                                //text color
                                COLOR_RGB(0xFF,0xFF,0xFF),
                                F("Done."));

  return(FWol);
  }
//---------------------------------------------------------------------------
#if TOUCH_DEMO
void Force_Marble_Position(uint32_t x,uint16_t y)
  {
  marble_x_pos=x;
  marble_y_pos=y;
  }
#endif //TOUCH_DEMO
//---------------------------------------------------------------------------
uint16_t Add_Marble_To_Display_List(uint16_t FWol)
  {
  //========== PUT BLUE MARBLE ON SCREEN ==========
  // Set the drawing color to white
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_A(255));

  //Pull the uncompressed bitmap from RAM_G onto the screen
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BEGIN(BITMAPS));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SOURCE(Marble_RAM_G_Address));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_LAYOUT(
                       ARGB1555,
                       marble_width*2,
                       marble_height));

  FWol=FT8xx_Cmd_Dat_0(FWol,
                       BITMAP_SIZE(
                       NEAREST, // BILINEAR, //BiLinear is much more work
                       BORDER,
                       BORDER,
                       marble_width,
                       marble_height));
   //Rotate the bitmap
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       CMD_LOADIDENTITY);
  //Translate to the center
  FWol=FT8xx_Cmd_Dat_2(FWol,
                       CMD_TRANSLATE,
                       +(to_16_16_fp(marble_width,0)/2),
                       +(to_16_16_fp(marble_height,0)/2));
  //The actual rotate command
  FWol=FT8xx_Cmd_Dat_1(FWol,
                       CMD_ROTATE,
                       to_16_16_fp(marble_rotation,0)/360);
  //Undo the translation
  FWol=FT8xx_Cmd_Dat_2(FWol,
                       CMD_TRANSLATE,
                       -(to_16_16_fp(marble_width,0)/2),
                       -(to_16_16_fp(marble_height,0)/2));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       CMD_SETMATRIX);
  //Render the bitmap it to the current frame
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       VERTEX2F(
                         (marble_x_pos-(marble_width*(16/2))),
                         (marble_y_pos-(marble_height*(16/2)))));
  FWol=FT8xx_Cmd_Dat_0(FWol,
                                 END());
  return(FWol);
  }
//---------------------------------------------------------------------------
void Move_Marble(void)
  {
  //We need the radius, not diameter, and in native x16 units
  uint16_t
    move_marble_width;
  move_marble_width=marble_width*(16/2);
  uint16_t
    move_marble_height;
  move_marble_height=marble_height*(16/2);

  //Move X, bouncing
  if(marble_x_vel < 0)
    {
    //Going left. OK to move again?
    if(0 < (marble_x_pos-(move_marble_width)+marble_x_vel))
      {
      //it will be onscreen after decrease
      marble_x_pos+=marble_x_vel;
      }
    else
      {
      //It would be too small, bounce.
      marble_x_pos=move_marble_width+(move_marble_width-(marble_x_pos+marble_x_vel));
      //Turn around.
      marble_x_vel=-marble_x_vel;
      marble_spin=marble_y_vel;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((marble_x_pos+(move_marble_width)+marble_x_vel) < (int32_t)LCD_WIDTH*16)
      {
      //it will be on screen after increase
      marble_x_pos+=marble_x_vel;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_x_ctr;
      max_x_ctr=(int32_t)LCD_WIDTH*16-move_marble_width;
      marble_x_pos=max_x_ctr-(max_x_ctr-(marble_x_pos+marble_x_vel));
      //Turn around.
      marble_x_vel=-marble_x_vel;
      marble_spin=-marble_y_vel;
      }
    }

  //Move Y, bouncing
  if(marble_y_vel < 0)
    {
    //Going left. OK to move again?
    if(0 < (marble_y_pos-(move_marble_height)+marble_y_vel))
      {
      //it will be onscreen after decrease
      marble_y_pos+=marble_y_vel;
      }
    else
      {
      //It would be too small, bounce.
      marble_y_pos=move_marble_height+(move_marble_height-(marble_y_pos+marble_y_vel));
      //Turn around.
      marble_y_vel=-marble_y_vel;
      marble_spin=-marble_x_vel;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((marble_y_pos+(move_marble_height)+marble_y_vel) < (int32_t)LCD_HEIGHT*16)
      {
      //it will be on screen after increase
      marble_y_pos+=marble_y_vel;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_y_ctr;
      max_y_ctr=(int32_t)LCD_WIDTH*16-move_marble_height;
      marble_y_pos=max_y_ctr-(max_y_ctr-(marble_y_pos+marble_y_vel));
      //Turn around.
      marble_y_vel=-marble_y_vel;
      marble_spin=marble_x_vel;
      }
    }
  //Do the twist.
  marble_rotation+=(marble_spin)/16;
  if(360 < marble_rotation)
    marble_rotation-=360;
  else
    if(marble_rotation < 0)
      marble_rotation+=360;

  }
#endif // MARBLE_DEMO
//===========================================================================
#if BOUNCE_DEMO
//Keep track of the ball
int32_t
  x_position;
int32_t
  x_velocity;
int32_t
  y_position;
int32_t
  y_velocity;
int32_t
  ball_size;
int32_t
  ball_delta;
//Cycle the color around
uint8_t
  r;
uint8_t
  g;
uint8_t
  b;
uint8_t
  transparency;
uint8_t
  transparency_direction;
//---------------------------------------------------------------------------
void Initialize_Bounce_Demo(void)
  {
  //Choose some starting color
  r=0xff;
  g=0x00;
  b=0x80;

  //Start ghostly, getting more solid.
  transparency=0;
  transparency_direction=1;

  // Define a default point x-location (1/16 anti-aliased)
  x_position = (LCD_WIDTH/2 * 16);
  x_velocity = 3*16;
  // Define a default point y-location (1/16 anti-aliased)
  y_position = (LCD_HEIGHT/2 * 16);
  y_velocity = -2*16;
  //Start small.
  ball_size=50*1;
  ball_delta=1*16;
  }
//---------------------------------------------------------------------------
uint16_t Add_Bounce_To_Display_List(uint16_t FWol)
  {
  // Set the variable color of the bouncing ball
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_RGB(r,g,b));
  // Make it transparent
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_A(transparency));

  // Draw the ball -- a point (filled circle)
  FWol=FT8xx_Point(FWol,
                   x_position,y_position,ball_size);

  //========== RUBBER BAND TETHER ==========
  //Draw the rubberband.
  //Maximum stretched would be LCD_WIDTH/2 + LCD_WIDTH/2 (manhatten) make that
  //1 pixels wide, make the minimum 10 pixels wide
  uint16_t
    rubberband_width;
  uint16_t
    x_distance;
  if((x_position/16)<(LCD_WIDTH/2))
    x_distance=(LCD_WIDTH/2)-(x_position/16);
  else
    x_distance=(x_position/16)-(LCD_WIDTH/2);
  uint16_t
    y_distance;
  if((y_position/16)<(LCD_HEIGHT/2))
    y_distance=(LCD_HEIGHT/2)-(y_position/16);
  else
    y_distance=(y_position/16)-(LCD_HEIGHT/2);

  //Straight math does not make it skinny enough. This seems like it should
  //underlow often, but in real life never goes below 1. Need to dissect.
  rubberband_width=10-((9+1)*(x_distance+y_distance))/((LCD_WIDTH/2)+(LCD_HEIGHT/2));
  //Check for underflow just in case.
  if(rubberband_width&0x8000)
    rubberband_width=1;

  //Now that we know the rubberband width, drawing it is simple.
  FWol=FT8xx_Cmd_Dat_0(FWol,
                       COLOR_RGB(200,0,0));
  //(transparency set above still in effect)
  FWol=FT8xx_Line(FWol,
                  LCD_WIDTH/2,LCD_HEIGHT/2,
                  x_position/16,y_position/16,
                  rubberband_width);
  return(FWol);
  }
//---------------------------------------------------------------------------
void Bounce_Ball(void)
  {
  //Update the colors
  r++;
  g--;
  b+=2;

  //Cycle the transparancy
  if(transparency_direction)
    {
    //Getting more solid
    if(transparency!=255)
      {
      transparency++;
      }
    else
      {
      transparency_direction=0;
      }
    }
  else
    {
    //Getting more clear
    if(128<transparency)
      {
      transparency--;
      }
    else
      {
      transparency_direction=1;
      }
    }

  //========== BOUNCE THE BALL AROUND ==========

  #define MIN_POINT_SIZE (10*16)
//  #define MAX_POINT_SIZE (int32_t)(((LCD_WIDTH/2)-20)*16)
  #define MAX_POINT_SIZE (int32_t)(((LCD_HEIGHT/2)-20)*16)

  //Change the point (ball) size.
  if(ball_delta < 0)
    {
    //Getting smaller. OK to decrease again?
    if(MIN_POINT_SIZE < (ball_size+ball_delta))
      {
      //it will be bigger than min after decrease
      ball_size+=ball_delta;
      }
    else
      {
      //It would be too small, bounce.
      ball_size=MIN_POINT_SIZE+(MIN_POINT_SIZE-(ball_size+ball_delta));
      //Turn around.
      ball_delta=-ball_delta;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((ball_size+ball_delta) < MAX_POINT_SIZE)
      {
      //it will be smaller than max after increase
      ball_size+=ball_delta;
      }
    else
      {
      //It would be too big, bounce.
      ball_size=MAX_POINT_SIZE-(MAX_POINT_SIZE-(ball_size+ball_delta));
      //Turn around.
      ball_delta=-ball_delta;
      }
    }

  //Move X, bouncing
  if(x_velocity < 0)
    {
    //Going left. OK to move again?
    if(0 < (x_position-(ball_size)+x_velocity))
      {
      //it will be onscreen after decrease
      x_position+=x_velocity;
      }
    else
      {
      //It would be too small, bounce.
      x_position=ball_size+(ball_size-(x_position+x_velocity));
      //Turn around.
      x_velocity=-x_velocity;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((x_position+(ball_size)+x_velocity) < (int32_t)LCD_WIDTH*16)
      {
      //it will be on screen after increase
      x_position+=x_velocity;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_x_ctr;
      max_x_ctr=(int32_t)LCD_WIDTH*16-ball_size;
      x_position=max_x_ctr-(max_x_ctr-(x_position+x_velocity));
      //Turn around.
      x_velocity=-x_velocity;
      }
    }

  //Move Y, bouncing
  if(y_velocity < 0)
    {
    //Going left. OK to move again?
    if(0 < (y_position-(ball_size)+y_velocity))
      {
      //it will be onscreen after decrease
      y_position+=y_velocity;
      }
    else
      {
      //It would be too small, bounce.
      y_position=ball_size+(ball_size-(y_position+y_velocity));
      //Turn around.
      y_velocity=-y_velocity;
      }
    }
  else
    {
    //Getting larger. OK to increase again?
    if((y_position+(ball_size)+y_velocity) < (int32_t)LCD_HEIGHT*16)
      {
      //it will be on screen after increase
      y_position+=y_velocity;
      }
    else
      {
      //It would be too big, bounce.
      int32_t
        max_y_ctr;
      max_y_ctr=(int32_t)LCD_WIDTH*16-ball_size;
      y_position=max_y_ctr-(max_y_ctr-(y_position+y_velocity));
      //Turn around.
      y_velocity=-y_velocity;
      }
    }
  }
#endif // BOUNCE_DEMO
//============================================================================
#if (0 != LOGO_DEMO)
//Remember where we put the logo image data in RAM_G
uint32_t
  Logo_RAM_G_Address;
//Remember how big the Logo image is.
uint32_t
  Logo_Width;
uint32_t
  Logo_Height;

// Keep track of the logo's orientation
uint16_t
  logo_rotate_degrees;
//Used to pause the logo between spinning sesions
uint16_t
  logo_rotate_pause;
//----------------------------------------------------------------------------
uint16_t Initialize_Logo_Demo(uint16_t FWol,
	                            uint32_t *RAM_G_Unused_Start)
  {
  // No rotation to start.
  logo_rotate_degrees=0;
  // Don't spin the logo right away, delay ~8 seconds at 60 frames per second
  logo_rotate_pause=8*60;

  //Remember where we put the logo in RAM_G so we can access it later.
  Logo_RAM_G_Address=*RAM_G_Unused_Start;
#if (0==LOGO_PNG_0_ARGB2_1)
  //Load and expand our 24-bit PNG (true color, lossless, with
  //transparency) into RAM_G
  //An indexed PNG is smaller, but the FT8xx does not handle
  //indexed color PNGs.
  FWol=FT8xx_Load_PNG_to_RAM_G(FWol,
                               CFAM800480xx050T_PNG_LOGO,
                               LOGO_SIZE_PNG,
                               RAM_G_Unused_Start,
                               &Logo_Width,
                               &Logo_Height);
#endif // 0==LOGO_PNG_0_ARGB2_1

#if (1==LOGO_PNG_0_ARGB2_1)
  //Load and INFLATE our 8-bit A2R2G2B2 (lossless) image into RAM_G

  //You have to know before hand how big the logo is. The INFLATE
  //is not aware of the content or format of the data.
  Logo_Width=LOGO_WIDTH_ARGB2;
  Logo_Height=LOGO_HEIGHT_ARGB2;

  FWol=FT8xx_Inflate_to_RAM_G(FWol,
                              CFAM800480xx050T_ARGB2_LOGO,
                              LOGO_SIZE_ARGB2,
                              RAM_G_Unused_Start);
#endif // 1==LOGO_PNG_0_ARGB2_1
  //Pass our updated offset back to the caller
  return(FWol);
  }
//----------------------------------------------------------------------------
uint16_t Add_Logo_To_Display_List(uint16_t FWol)
  {
  //========== PUT LOGO ON SCREEN ==========
  // Set the drawing color to white
  FWol=FT8xx_Cmd_Dat_0(FWol, COLOR_RGB(0xFF,0xFF,0xFF));
  //Solid color -- not transparent
  FWol=FT8xx_Cmd_Dat_0(FWol, COLOR_A(255));
  //Point to the uncompressed logo in RAM_G
  FWol=FT8xx_Cmd_Dat_0(FWol, BEGIN(BITMAPS));
  FWol=FT8xx_Cmd_Dat_0(FWol, BITMAP_SOURCE(Logo_RAM_G_Address));

#if 0==LOGO_PNG_0_ARGB2_1
  //Transparent PNG comes in as ARGB4, 2 bytes per pixel
  FWol=FT8xx_Cmd_Dat_0(FWol, BITMAP_LAYOUT(ARGB4,Logo_Width*2,Logo_Height));
#endif // 0==LOGO_PNG_0_ARGB2_1

#if 1==LOGO_PNG_0_ARGB2_1
  //ARGB2 comes in as ARGB2, 1 byte per pixel
  FWol=FT8xx_Cmd_Dat_0(FWol, BITMAP_LAYOUT(ARGB2,Logo_Width,Logo_Height));
#endif // 1==LOGO_PNG_0_ARGB2_1

  //In order to have a 240x240 logo rotate without clipping, we have
  //a 240*sqrt(2) x 240*sqrt(2) = 340 x 340 logo, with all the non
  //transparent content kept inside a 240 circle. Whatevs.
  FWol=FT8xx_Cmd_Dat_0(FWol,
                      BITMAP_SIZE(BILINEAR,BORDER,BORDER,Logo_Width,Logo_Height));
   //Rotate the bitmap
  FWol=FT8xx_Cmd_Dat_0(FWol,
                      CMD_LOADIDENTITY);
  //Translate to the center
  FWol=FT8xx_Cmd_Dat_2(FWol,
                      CMD_TRANSLATE,
                      to_16_16_fp(Logo_Width,0)/2,
                      to_16_16_fp(Logo_Height,0)/2);
  //The actual rotate command
  FWol=FT8xx_Cmd_Dat_1(FWol,
                      CMD_ROTATE,
                      to_16_16_fp(logo_rotate_degrees,0)/360);
  //Undo the translation, and move to the center of the screen.
  FWol=FT8xx_Cmd_Dat_2(FWol,CMD_TRANSLATE,
                      (to_16_16_fp(-Logo_Width/2+0/2,0)),
                      (to_16_16_fp(-Logo_Height/2+0/2,0)));
  FWol=FT8xx_Cmd_Dat_0(FWol, CMD_SETMATRIX);
  //Render the bitmap to the current frame
  FWol=FT8xx_Cmd_Dat_0(FWol,
                      VERTEX2F((LCD_WIDTH-Logo_Width)*(16/2),(LCD_HEIGHT-Logo_Height)*(16/2)));
  FWol=FT8xx_Cmd_Dat_0(FWol, END());


  // ROTATE THE LOGO -- MAINLY BECAUSE WE CAN.
  if(0 == logo_rotate_degrees)
    {
    //upright, stay here for logo_rotate_pause frames
    if(0 != logo_rotate_pause)
      {
      logo_rotate_pause--;
      }
    else
      {
      // ~ 7 seconds at 60 frames per second
      logo_rotate_pause=7*60;
      logo_rotate_degrees=1;
      }
    }
  else
    {
    if(logo_rotate_degrees<359)
      logo_rotate_degrees++;
    else
      logo_rotate_degrees=0;
    }
  //Pass our updated offset back to the caller
  return(FWol);
  }
#endif // LOGO_DEMO
//============================================================================
#if (0 != SOUND_DEMO)
//Remember where we put the audio data in RAM_G
uint32_t
  Audio_RAM_G_Address;
//Remember how big the audio data is.
uint32_t
  Audio_RAM_G_Length;
//Keep track of how many times we have played the sound.
uint8_t
  play_times;

//Play the sound in sync with the logo roatating
uint16_t
  sound_logo_rotate_degrees;
uint16_t
  sound_logo_rotate_pause;
//----------------------------------------------------------------------------
uint16_t Initialize_Sound_Demo(uint16_t FWol,
                               uint32_t *RAM_G_Unused_Start)
  {
  //Since the Arduino uSD card is slow, put up a please wait screen.
  FWol=Start_Busy_Spinner_Screen(FWol,
                                 //clear color
                                 CLEAR_COLOR_RGB(0x00,0x00,0xFF),
                                 //text color
                                 COLOR_RGB(0xFF,0xFF,0xFF),
                                 //spinner color
                                 COLOR_RGB(0x00,0xFF,0x00),
#if (0 != SOUND_VOICE)
                                 F("Loading \"VOI_8K.RAW\" . . ."));
#else
                                 F("Loading \"MUS_8K.RAW\" . . ."));
#endif

  //Play the sound the number of times the user requested.
  play_times=SOUND_PLAY_TIMES;
  // Sync the sound start with the logo rotating
  sound_logo_rotate_degrees=0;
  sound_logo_rotate_pause=8*60;  

  //Attempt to load our RAW audio file from the uSD into RAM_G
  Audio_RAM_G_Address=*RAM_G_Unused_Start;
  Audio_RAM_G_Length=0;

  //If the Audio_RAM_G_Length returned is 0, then it has probably failed.
  //Not much to do in the way of error recovery though, as the FT8xx
  //would just be instructed to play a 0-lenght RAM_G buffer, which
  //hopefully it handles gracefully.
  //By the way, it appears that the SD library reports all file names
  //in all upper case. So even though Windows file explorer, CMD,
  //and Power Shell all report the name as lower case, we need to
  //feed the SD library an all uppercase string.
  Load_File_To_RAM_G(Audio_RAM_G_Address,
#if (0 != SOUND_VOICE)
                     "VOI_8K.RAW",
#else
                     "MUS_8K.RAW",
#endif
                     &Audio_RAM_G_Length);

  //Keep track of the RAM_G memory allocation, force to 8-byte aligned
  *RAM_G_Unused_Start=(*RAM_G_Unused_Start+Audio_RAM_G_Length+0x07)&0xFFFFFFF8;

  //Pass our updated offset back to the caller
  return(FWol);
  }
//----------------------------------------------------------------------------
void Start_Sound_Demo_Playing(void)
  {
//  if(1 == sound_logo_rotate_degrees)
    {
//    if(0 != play_times)
      {
      //Do not start unless the previous sound has completed
      //1-audio playback is going on
      //0-audio playback has finished
      if(0 == FT8xx_REG_Read_8(REG_PLAYBACK_PLAY))
        {
        //Remember that we played the sound
        play_times--;
#if (0 != SOUND_VOICE)
        SerPrintFF(F("Playing: \"VOI_8K.RAW\".\n")),
#else
        SerPrintFF(F("Playing: \"MUS_8K.RAW\".\n")),
#endif
#if 1 //Audio file
        //Point the FT8xx audio stuff at our RAM_G audio data. Let it go.
        FT8xx_REG_Write_32(REG_PLAYBACK_START,Audio_RAM_G_Address);
        FT8xx_REG_Write_32(REG_PLAYBACK_LENGTH,Audio_RAM_G_Length);
        FT8xx_REG_Write_32(REG_PLAYBACK_FREQ,8000);
        FT8xx_REG_Write_32(REG_PLAYBACK_FORMAT,ULAW_SAMPLES);
        FT8xx_REG_Write_32(REG_VOL_PB,0);
        FT8xx_REG_Write_32(REG_PLAYBACK_LOOP,0);
        FT8xx_REG_Write_32(REG_PLAYBACK_PLAY,1);
        //Ramp the volume to avoid the pop at the start of playback
        //This is optional.
        for(uint8_t vol=1; 255 != vol;vol++)
          {
          FT8xx_REG_Write_32(REG_VOL_PB,vol);
          }
#endif
#if 0 //Synthesizer

        //Triangle wave
        FT8xx_REG_Write_8(REG_VOL_SOUND,96);
        FT8xx_REG_Write_16(REG_SOUND,0x04);
        FT8xx_REG_Write_8(REG_PLAY,1);
        SerPrintFF(F("Playing synth . . . "));


        
//while(0 != FT8xx_REG_Read_8(REG_PLAY));
 //       SerPrintFF(F("done.\n"));
#endif

        }
      }
    }
  // Sync the sound start with the logo rotating
  if(0 == sound_logo_rotate_degrees)
    {
    //upright, stay here for logo_rotate_pause frames
    if(0 != sound_logo_rotate_pause)
      {
      sound_logo_rotate_pause--;
      }
    else
      {
      // ~ 7 seconds at 60 frames per second
      sound_logo_rotate_pause=7*60;
      sound_logo_rotate_degrees=1;
      }
    }
  else
    {
    if(sound_logo_rotate_degrees<359)
      sound_logo_rotate_degrees++;
    else
      sound_logo_rotate_degrees=0;
    }
  }
#endif // SOUND_DEMO
//============================================================================
