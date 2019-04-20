#ifndef __DEMOS_H__
#define __DEMOS_H__
//============================================================================
//
// Some demo routines for Crystalfontz CFA10100 FT8xx accelerated displays.
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
#if (0 != TOUCH_DEMO)
uint16_t Add_Touch_Dot_To_Display_List(uint16_t FWol,
                                       uint16_t touch_x,
                                       uint16_t touch_y);
#endif //TOUCH_DEMO
//----------------------------------------------------------------------------
#if (0 != BMP_DEMO)
uint16_t Initialize_Bitmap_Demo(uint16_t FWol,
                                uint32_t *RAM_G_Unused_Start);
uint16_t Add_Bitmap_To_Display_List(uint16_t FWol);
#endif // BMP_DEMO
//----------------------------------------------------------------------------
#if (0 != MARBLE_DEMO) //Requires uSD
uint16_t Initialize_Marble_Demo(uint16_t FWol,
                                uint32_t RAM_G_Unused_Start,
                                uint32_t *Marble_RAM_G_Length);
#if (0 != TOUCH_DEMO)
void Force_Marble_Position(uint32_t x,uint16_t y);
#endif //TOUCH_DEMO
uint16_t Add_Marble_To_Display_List(uint16_t FWol);
void Move_Marble(void);
#endif // MARBLE_DEMO
//----------------------------------------------------------------------------
#if (0 != BOUNCE_DEMO)
void Initialize_Bounce_Demo(void);
uint16_t Add_Bounce_To_Display_List(uint16_t FWol);
void Bounce_Ball(void);
#endif // BOUNCE_DEMO
//----------------------------------------------------------------------------
#if (0 != LOGO_DEMO)
uint16_t Initialize_Logo_Demo(uint16_t FWol,
                              uint32_t *RAM_G_Unused_Start);
uint16_t Add_Logo_To_Display_List(uint16_t FWol);
#endif // LOGO_DEMO
//----------------------------------------------------------------------------
#if (0 != SOUND_DEMO)
uint16_t Initialize_Sound_Demo(uint16_t FWol,
                               uint32_t *RAM_G_Unused_Start);
void Start_Sound_Demo_Playing(void);
#endif // SOUND_DEMO
//============================================================================
#endif // __DEMOS_H__
