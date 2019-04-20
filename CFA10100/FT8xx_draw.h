#ifndef __FT8XX_DRAW_H__
#define __FT8XX_DRAW_H__
//============================================================================
//
// Drawing and helper routines for FT8xx accelerators.
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
uint16_t FT8xx_Point(uint16_t FWol,
                     uint16_t point_x,
                     uint16_t point_y,
                     uint16_t ball_size);
uint16_t FT8xx_Line(uint16_t FWol,
                    uint16_t x0,
                    uint16_t y0,
                    uint16_t x1,
                    uint16_t y1,
                    uint16_t width);
uint16_t FT8xx_Filled_Rectangle(uint16_t FWol,
                                uint16_t x0,
                                uint16_t y0,
                                uint16_t x1,
                                uint16_t y1);
uint16_t FT8xx_Open_Rectangle(uint16_t FWol,
                              uint16_t x0,
                              uint16_t y0,
                              uint16_t x1,
                              uint16_t y1,
                              uint16_t width);
uint16_t FT8xx_Text(uint16_t FWol,
                    uint16_t x,
                    uint16_t y,
                    uint16_t Font,
                    uint16_t Options,
                    const __FlashStringHelper *message);
uint16_t Start_Busy_Spinner_Screen(uint16_t FWol,
                                   uint32_t Clear_Color,
                                   uint32_t Text_Color,
                                   uint32_t Spinner_Color,
                                   const __FlashStringHelper *message);
uint16_t Stop_Busy_Spinner_Screen(uint16_t FWol,
                                  uint32_t Clear_Color,
                                  uint32_t Text_Color,
                                  const __FlashStringHelper *message);
uint16_t Calibrate_Touch(uint16_t FWol);
uint16_t FT8xx_Load_PNG_to_RAM_G(uint16_t FWol,
                                 const uint8_t *PNG_data,
                                 uint32_t PNG_length,
                                 uint32_t *RAM_G_Address,
                                 uint32_t *Image_Width,
                                 uint32_t *Image_Height);
uint16_t FT8xx_Inflate_to_RAM_G(uint16_t FWol,
                                const uint8_t *Flash_Data,
                                uint32_t data_length,
                                uint32_t *RAM_G_Address);
void Load_File_To_RAM_G(uint32_t RAM_G_Address,
                        const char *File_Name,
                        uint32_t *RAM_G_Used);
//============================================================================
#endif // __FT8XX_DRAW_H__
