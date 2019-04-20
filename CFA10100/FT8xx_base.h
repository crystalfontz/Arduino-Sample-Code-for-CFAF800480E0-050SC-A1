#ifndef __FT8XX_BASE_H__
#define __FT8XX_BASE_H__
//============================================================================
//
// Low-Level routines for FT8xx accelerators.
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
void _FT8xx_Select_and_Address(uint32_t Address, uint8_t Operation);
void _FT8xx_send_32(uint32_t Data);
void FT8xx_REG_Write_8(uint32_t REG_Address, uint8_t ftData8);
void FT8xx_REG_Write_16(uint32_t REG_Address, uint16_t ftData16);
void FT8xx_REG_Write_32(uint32_t REG_Address, uint32_t ftData32);
uint16_t FT8xx_Cmd_Dat_0(uint16_t FWol,
                         uint32_t command);
uint16_t FT8xx_Cmd_Dat_1(uint16_t FWol,
                         uint32_t command,uint32_t data0);
uint16_t FT8xx_Cmd_Dat_2(uint16_t FWol,
                         uint32_t command,uint32_t data0, uint32_t data1);
uint8_t FT8xx_REG_Read_8(uint32_t REG_Address);
uint16_t FT8xx_REG_Read_16(uint32_t REG_Address);
uint32_t FT8xx_REG_Read_32(uint32_t REG_Address);
#if 0
#define Wait_for_FT8xx_Execution_Complete(SW_write_offset) while(FT8xx_REG_Read_16(REG_CMD_READ) != SW_write_offset)
#else
void Wait_for_FT8xx_Execution_Complete(uint16_t SW_write_offset);
#endif
#define FT8xx_Command_Write_8(command) _FT8xx_Select_and_Address(0,command); SET_FTDI_CS_NOT;
uint16_t Get_Free_CMD_Space(uint16_t FWol);
uint16_t Get_RAM_G_Pointer_After_INFLATE(uint16_t FWol,
                                         uint32_t *RAM_G_First_Available);
uint16_t Get_RAM_G_Properties_After_LOADIMAGE(uint16_t FWol,
                                              uint32_t *RAM_G_First_Available,
                                              uint32_t *Width,
                                              uint32_t *Height);
#if TOUCH_TYPE==TOUCH_RESISTIVE
uint8_t Read_Touch(int16_t x_points[1], int16_t y_points[1]);
#endif // TOUCH_TYPE==TOUCH_RESISTIVE
#if TOUCH_TYPE==TOUCH_CAPACITIVE
uint8_t Read_Touch(int16_t x_points[5], int16_t y_points[5]);
#endif // TOUCH_TYPE==TOUCH_CAPACITIVE
uint8_t Read_Touch(int16_t x_points[5], int16_t y_points[5]);
uint8_t quiet_backlight_128(uint8_t portion_of_128);
uint8_t quiet_backlight_percent(uint8_t percent);
uint8_t FT8xx_Init(void);
//============================================================================
#endif // __FT8XX_BASE_H__
