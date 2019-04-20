#ifndef __FT8XX_DEFINES_H__
#define __FT8XX_DEFINES_H__

/*******************************************************************************

Copyright (c) Future Technology Devices International

THIS SOFTWARE IS PROVIDED BY FUTURE TECHNOLOGY DEVICES INTERNATIONAL LIMITED "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
FUTURE TECHNOLOGY DEVICES INTERNATIONAL LIMITED BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES LOSS OF USE, DATA, OR PROFITS OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

FTDI DRIVERS MAY BE USED ONLY IN CONJUNCTION WITH PRODUCTS BASED ON FTDI PARTS.

FTDI DRIVERS MAY BE DISTRIBUTED IN ANY FORM AS LONG AS LICENSE INFORMATION IS NOT MODIFIED.

IF A CUSTOM VENDOR ID AND/OR PRODUCT ID OR DESCRIPTION STRING ARE USED, IT IS THE
RESPONSIBILITY OF THE PRODUCT MANUFACTURER TO MAINTAIN ANY CHANGES AND SUBSEQUENT WHQL
RE-CERTIFICATION AS A RESULT OF MAKING THESE CHANGES.

********************************************************************************

This code is provided as an example only and is not guaranteed by FTDI/BridgeTek.
FTDI/BridgeTek accept no responsibility for any issues resulting from its use.
By using this code, the developer of the final application incorporating any
parts of this sample project agrees to take full responsible for ensuring its
safe and correct operation and for any consequences resulting from its use.

Revision History:

Version Author              Date        Description
******* ******************* *********** ****************************************
1.0     BridgeTek / FTDI    Feb 2017    Initial version taken from sample app

*/


//#ifdef  __cplusplus
//extern "C" {
//#endif

//The arduino library has "DISPLAY" defined. Undo that.
#undef DISPLAY
//
//I don't know what they are thinking with this bit. It unconditionally enables
//the FT81x and unconditionally disable that FT80x. Don't do that.
//#ifndef FT_81X_ENABLE
//#define FT_81X_ENABLE
//#endif

// Might be useful for the TF8xx's 16.16 fixed point
#define to_16_16_fp(int_part,frc_part)  ((uint32_t)((((uint32_t)int_part)<<16)|((uint32_t)frc_part)))

//For some reason these were in the main file. Seems like they should be in here.
// FT800 Chip Commands - use with cmdWrite
#define FT800_ACTIVE  0x00      // Initializes FT800
#define FT800_STANDBY 0x41      // Place FT800 in Standby (clk running)
#define FT800_SLEEP   0x42      // Place FT800 in Sleep (clk off)
#define FT800_PWRDOWN 0x50      // Place FT800 in Power Down (core off)
#define FT800_CLKEXT  0x44      // Select external clock source
#define FT800_CLK48M  0x62      // Select 48MHz PLL
#define FT800_CLK36M  0x61      // Select 36MHz PLL
#define FT800_CORERST 0x68      // Reset core - all registers default

// FT800 Memory Commands - use with ft800memWritexx and ft800memReadxx
#define MEM_WRITE 0x80      // FT800 Host Memory Write
#define MEM_READ  0x00      // FT800 Host Memory Read

/* Definitions used for FT800 co processor command buffer */
#define FT_DL_SIZE           (8*1024L)  //8KB Display List buffer size
#define FT_CMD_FIFO_SIZE     (4*1024L)  //4KB coprocessor Fifo size
#define FT_CMD_SIZE          (4)       //4 byte per coprocessor command of EVE

#ifndef FT_81X_ENABLE

/* For FT801 enable the switch in platform.h file */
/* Lower boundary of trimming */
#define LOW_FREQ_BOUND  47040000L//98% of 48Mhz

#define FT800_VERSION   "1.9.0"
#define RAM_G_SIZE           (256UL*1024UL)
#define ADC_DIFFERENTIAL     1UL
#define ADC_SINGLE_ENDED     0UL
#define ADPCM_SAMPLES        2UL
#define ALWAYS               7UL
#define ARGB1555             0UL
#define ARGB2                5UL
#define ARGB4                6UL
#define BARGRAPH             11UL
#define BILINEAR             1UL
#define BITMAPS              1UL
#define BORDER               0UL

#define CMDBUF_SIZE          4096UL
#define CMD_APPEND           (4294967070UL) // 0xFFFFFF1E
#define CMD_BGCOLOR          (4294967049UL) // 0xFFFFFF09
#define CMD_BITMAP_TRANSFORM (4294967073UL) // 0xFFFFFF21
#define CMD_BUTTON           (4294967053UL) // 0xFFFFFF0D
#define CMD_CALIBRATE        (4294967061UL) // 0xFFFFFF15
#define CMD_CSKETCH          (4294967093UL) // 0xFFFFFF35
#define CMD_CLOCK            (4294967060UL) // 0xFFFFFF14
#define CMD_COLDSTART        (4294967090UL) // 0xFFFFFF32
#define CMD_CRC              (4294967043UL) // 0xFFFFFF03
#define CMD_DIAL             (4294967085UL) // 0xFFFFFF2D
#define CMD_DLSTART          (4294967040UL) // 0xFFFFFF00
#define CMD_EXECUTE          (4294967047UL) // 0xFFFFFF07
#define CMD_FGCOLOR          (4294967050UL) // 0xFFFFFF0A
#define CMD_GAUGE            (4294967059UL) // 0xFFFFFF13
#define CMD_GETMATRIX        (4294967091UL) // 0xFFFFFF33
#define CMD_GETPOINT         (4294967048UL) // 0xFFFFFF08
#define CMD_GETPROPS         (4294967077UL) // 0xFFFFFF25
#define CMD_GETPTR           (4294967075UL) // 0xFFFFFF23
#define CMD_GRADCOLOR        (4294967092UL) // 0xFFFFFF34
#define CMD_GRADIENT         (4294967051UL) // 0xFFFFFF0B
#define CMD_HAMMERAUX        (4294967044UL) // 0xFFFFFF04
#define CMD_IDCT             (4294967046UL) // 0xFFFFFF06
#define CMD_INFLATE          (4294967074UL) // 0xFFFFFF22
#define CMD_INTERRUPT        (4294967042UL) // 0xFFFFFF02
#define CMD_KEYS             (4294967054UL) // 0xFFFFFF0E
#define CMD_LOADIDENTITY     (4294967078UL) // 0xFFFFFF26
#define CMD_LOADIMAGE        (4294967076UL) // 0xFFFFFF24
#define CMD_LOGO             (4294967089UL) // 0xFFFFFF31
#define CMD_MARCH            (4294967045UL) // 0xFFFFFF05
#define CMD_MEMCPY           (4294967069UL) // 0xFFFFFF1D
#define CMD_MEMCRC           (4294967064UL) // 0xFFFFFF18
#define CMD_MEMSET           (4294967067UL) // 0xFFFFFF1B
#define CMD_MEMWRITE         (4294967066UL) // 0xFFFFFF1A
#define CMD_MEMZERO          (4294967068UL) // 0xFFFFFF1C
#define CMD_NUMBER           (4294967086UL) // 0xFFFFFF2E
#define CMD_PROGRESS         (4294967055UL) // 0xFFFFFF0F
#define CMD_REGREAD          (4294967065UL) // 0xFFFFFF19
#define CMD_ROTATE           (4294967081UL) // 0xFFFFFF29
#define CMD_SCALE            (4294967080UL) // 0xFFFFFF28
#define CMD_SCREENSAVER      (4294967087UL) // 0xFFFFFF2F
#define CMD_SCROLLBAR        (4294967057UL) // 0xFFFFFF11
#define CMD_SETFONT          (4294967083UL) // 0xFFFFFF2B
#define CMD_SETMATRIX        (4294967082UL) // 0xFFFFFF2A
#define CMD_SKETCH           (4294967088UL) // 0xFFFFFF30
#define CMD_SLIDER           (4294967056UL) // 0xFFFFFF10
#define CMD_SNAPSHOT         (4294967071UL) // 0xFFFFFF1F
#define CMD_SPINNER          (4294967062UL) // 0xFFFFFF16
#define CMD_STOP             (4294967063UL) // 0xFFFFFF17
#define CMD_SWAP             (4294967041UL) // 0xFFFFFF01
#define CMD_TEXT             (4294967052UL) // 0xFFFFFF0C
#define CMD_TOGGLE           (4294967058UL) // 0xFFFFFF12
#define CMD_TOUCH_TRANSFORM  (4294967072UL) // 0xFFFFFF20
#define CMD_TRACK            (4294967084UL) // 0xFFFFFF2C
#define CMD_TRANSLATE        (4294967079UL) // 0xFFFFFF27

#define DECR                      (    4UL) // 0x000004
#define DECR_WRAP                 (    7UL) // 0x000007
#define DLSWAP_DONE               (    0UL) // 0x000000
#define DLSWAP_FRAME              (    2UL) // 0x000002
#define DLSWAP_LINE               (    1UL) // 0x000001
#define DST_ALPHA                 (    3UL) // 0x000003
#define EDGE_STRIP_A              (    7UL) // 0x000007
#define EDGE_STRIP_B              (    8UL) // 0x000008
#define EDGE_STRIP_L              (    6UL) // 0x000006
#define EDGE_STRIP_R              (    5UL) // 0x000005
#define EQUAL                     (    5UL) // 0x000005
#define GEQUAL                    (    4UL) // 0x000004
#define GREATER                   (    3UL) // 0x000003
#define INCR                      (    3UL) // 0x000003
#define INCR_WRAP                 (    6UL) // 0x000006
#define INT_CMDEMPTY              (   32UL) // 0x000020
#define INT_CMDFLAG               (   64UL) // 0x000040
#define INT_CONVCOMPLETE          (  128UL) // 0x000080
#define INT_PLAYBACK              (   16UL) // 0x000010
#define INT_SOUND                 (    8UL) // 0x000008
#define INT_SWAP                  (    1UL) // 0x000001
#define INT_TAG                   (    4UL) // 0x000004
#define INT_TOUCH                 (    2UL) // 0x000002
#define INVERT                    (    5UL) // 0x000005
#define KEEP                      (    1UL) // 0x000001
#define L1                        (    1UL) // 0x000001
#define L4                        (    2UL) // 0x000002
#define L8                        (    3UL) // 0x000003
#define LEQUAL                    (    2UL) // 0x000002
#define LESS                      (    1UL) // 0x000001
#define LINEAR_SAMPLES            (    0UL) // 0x000000
#define LINES                     (    3UL) // 0x000003
#define LINE_STRIP                (    4UL) // 0x000004
#define NEAREST                   (    0UL) // 0x000000
#define NEVER                     (    0UL) // 0x000000
#define NOTEQUAL                  (    6UL) // 0x000006
#define ONE                       (    1UL) // 0x000001
#define ONE_MINUS_DST_ALPHA       (    5UL) // 0x000005
#define ONE_MINUS_SRC_ALPHA       (    4UL) // 0x000004
#define OPT_CENTER                ( 1536UL) // 0x000600
#define OPT_CENTERX               (  512UL) // 0x000200
#define OPT_CENTERY               ( 1024UL) // 0x000400
#define OPT_FLAT                  (  256UL) // 0x000100
#define OPT_MONO                  (    1UL) // 0x000001
#define OPT_NOBACK                ( 4096UL) // 0x001000
#define OPT_NODL                  (    2UL) // 0x000002
#define OPT_RGB565                (    0UL) //   0x000000
#define OPT_NOHANDS               (49152UL) // 0x00C000
#define OPT_NOHM                  (16384UL) // 0x004000
#define OPT_NOPOINTER             (16384UL) // 0x004000
#define OPT_NOSECS                (32768UL) // 0x008000
#define OPT_NOTICKS               ( 8192UL) // 0x002000
#define OPT_RIGHTX                ( 2048UL) // 0x000800
#define OPT_SIGNED                (  256UL) // 0x000100
#define PALETTED                  (    8UL) // 0x000008
#define FTPOINTS                  (    2UL) // 0x000002
#define RECTS                     (    9UL) // 0x000009

#define RAM_CMD                 (1081344UL) // 0x108000
#define MEM_WRITE               (1048576UL) // 0x100000
#define RAM_G                   (      0UL) // 0x000000
#define RAM_PAL                 (1056768UL) // 0x102000
#define RAM_REG                 (1057792UL) // 0x102400

#define ROMFONT_TABLEADDRESS    (1048572UL) // 0x0FFFFC

#define REG_ANALOG              (1058104UL) // 0x102538
#define REG_ANA_COMP            (1058160UL) // 0x102570
#define REG_CLOCK               (1057800UL) // 0x102408
#define REG_CMD_DL              (1058028UL) // 0x1024EC
#define REG_CMD_READ            (1058020UL) // 0x1024E4
#define REG_CMD_WRITE           (1058024UL) // 0x1024E8
#define REG_CPURESET            (1057820UL) // 0x10241C
#define REG_CRC                 (1058152UL) // 0x102568
#define REG_CSPREAD             (1057892UL) // 0x102464
#define REG_CYA0                (1058000UL) // 0x1024D0
#define REG_CYA1                (1058004UL) // 0x1024D4
#define REG_CYA_TOUCH           (1058100UL) // 0x102534
#define REG_DATESTAMP           (1058108UL) // 0x10253C
#define REG_DITHER              (1057884UL) // 0x10245C
#define REG_DLSWAP              (1057872UL) // 0x102450
#define REG_FRAMES              (1057796UL) // 0x102404
#define REG_FREQUENCY           (1057804UL) // 0x10240C
#define REG_GPIO                (1057936UL) // 0x102490
#define REG_GPIO_DIR            (1057932UL) // 0x10248C
#define REG_HCYCLE              (1057832UL) // 0x102428
#define REG_HOFFSET             (1057836UL) // 0x10242C
#define REG_HSIZE               (1057840UL) // 0x102430
#define REG_HSYNC0              (1057844UL) // 0x102434
#define REG_HSYNC1              (1057848UL) // 0x102438
#define REG_ID                  (1057792UL) // 0x102400
#define REG_INT_EN              (1057948UL) // 0x10249C
#define REG_INT_FLAGS           (1057944UL) // 0x102498
#define REG_INT_MASK            (1057952UL) // 0x1024A0
#define REG_MACRO_0             (1057992UL) // 0x1024C8
#define REG_MACRO_1             (1057996UL) // 0x1024CC
#define REG_OUTBITS             (1057880UL) // 0x102458
#define REG_PCLK                (1057900UL) // 0x10246C
#define REG_PCLK_POL            (1057896UL) // 0x102468
#define REG_PLAY                (1057928UL) // 0x102488
#define REG_PLAYBACK_FORMAT     (1057972UL) // 0x1024B4
#define REG_PLAYBACK_FREQ       (1057968UL) // 0x1024B0
#define REG_PLAYBACK_LENGTH     (1057960UL) // 0x1024A8
#define REG_PLAYBACK_LOOP       (1057976UL) // 0x1024B8
#define REG_PLAYBACK_PLAY       (1057980UL) // 0x1024BC
#define REG_PLAYBACK_READPTR    (1057964UL) // 0x1024AC
#define REG_PLAYBACK_START      (1057956UL) // 0x1024A4
#define REG_PWM_DUTY            (1057988UL) // 0x1024C4
#define REG_PWM_HZ              (1057984UL) // 0x1024C0
#define REG_RENDERMODE          (1057808UL) // 0x102410
#define REG_ROMSUB_SEL          (1058016UL) // 0x1024E0
#define REG_ROTATE              (1057876UL) // 0x102454
#define REG_SNAPSHOT            (1057816UL) // 0x102418
#define REG_SNAPY               (1057812UL) // 0x102414
#define REG_SOUND               (1057924UL) // 0x102484
#define REG_SWIZZLE             (1057888UL) // 0x102460
#define REG_TAG                 (1057912UL) // 0x102478
#define REG_TAG_X               (1057904UL) // 0x102470
#define REG_TAG_Y               (1057908UL) // 0x102474
#define REG_TAP_CRC             (1057824UL) // 0x102420
#define REG_TAP_MASK            (1057828UL) // 0x102424
#define REG_TOUCH_ADC_MODE      (1058036UL) // 0x1024F4
#define REG_TOUCH_CHARGE        (1058040UL) // 0x1024F8
#define REG_TOUCH_DIRECT_XY     (1058164UL) // 0x102574
#define REG_TOUCH_DIRECT_Z1Z2   (1058168UL) // 0x102578
#define REG_TOUCH_MODE          (1058032UL) // 0x1024F0
#define REG_TOUCH_OVERSAMPLE    (1058048UL) // 0x102500
#define REG_TOUCH_RAW_XY        (1058056UL) // 0x102508
#define REG_TOUCH_RZ            (1058060UL) // 0x10250C
#define REG_TOUCH_RZTHRESH      (1058052UL) // 0x102504
#define REG_TOUCH_SCREEN_XY     (1058064UL) // 0x102510
#define REG_TOUCH_SETTLE        (1058044UL) // 0x1024FC
#define REG_TOUCH_TAG           (1058072UL) // 0x102518
#define REG_TOUCH_TAG_XY        (1058068UL) // 0x102514
#define REG_TOUCH_TRANSFORM_A   (1058076UL) // 0x10251C
#define REG_TOUCH_TRANSFORM_B   (1058080UL) // 0x102520
#define REG_TOUCH_TRANSFORM_C   (1058084UL) // 0x102524
#define REG_TOUCH_TRANSFORM_D   (1058088UL) // 0x102528
#define REG_TOUCH_TRANSFORM_E   (1058092UL) // 0x10252C
#define REG_TOUCH_TRANSFORM_F   (1058096UL) // 0x102530
#define REG_TRACKER             (1085440UL) // 0x109000
#define REG_TRIM                (1058156UL) // 0x10256C
#define REG_VCYCLE              (1057852UL) // 0x10243C
#define REG_VOFFSET             (1057856UL) // 0x102440
#define REG_VOL_PB              (1057916UL) // 0x10247C
#define REG_VOL_SOUND           (1057920UL) // 0x102480
#define REG_VSIZE               (1057860UL) // 0x102444
#define REG_VSYNC0              (1057864UL) // 0x102448
#define REG_VSYNC1              (1057868UL) // 0x10244C
/* FT801 Registers */
#define REG_CTOUCH_EXTENDED     (1058036UL) // 0x1024F4
#define REG_CTOUCH_GESTURE      (1058104UL) // 0x102538
#define REG_CTOUCH_IDS          (1058060UL) // 0x10250C
#define REG_CTOUCH_TOUCH0_XY    (1058064UL) // 0x102510
#define REG_CTOUCH_TOUCH1_XY    (1058056UL) // 0x102508
#define REG_CTOUCH_TOUCH2_XY    (1058164UL) // 0x102574
#define REG_CTOUCH_TOUCH3_XY    (1058168UL) // 0x102578
#define REG_CTOUCH_TOUCH4_X     (1058104UL) // 0x102538
#define REG_CTOUCH_TOUCH4_Y     (1058060UL) // 0x10250C

#define REPEAT                       ( 1UL) // 0x000001
#define REPLACE                      ( 2UL) // 0x000002
#define RGB332                       ( 4UL) // 0x000004
#define RGB565                       ( 7UL) // 0x000007
#define SRC_ALPHA                    ( 2UL) // 0x000002
#define TEXT8X8                      ( 9UL) // 0x000009
#define TEXTVGA                      (10UL) // 0x00000A
#define TOUCHMODE_CONTINUOUS         ( 3UL) // 0x000003
#define TOUCHMODE_FRAME              ( 2UL) // 0x000002
#define TOUCHMODE_OFF                ( 0UL) // 0x000000
#define TOUCHMODE_ONESHOT            ( 1UL) // 0x000001
#define ULAW_SAMPLES                 ( 1UL) // 0x000001

#define VERTEX2F(x,y) ((1UL<<30)|(((x)&32767UL)<<15)|(((y)&32767UL)<<0))
#define VERTEX2II(x,y,handle,cell) ((2UL<<30)|(((x)&511UL)<<21)|(((y)&511UL)<<12)|(((handle)&31UL)<<7)|(((cell)&127UL)<<0))
#define BITMAP_SOURCE(addr) ((1UL<<24)|(((addr)&1048575UL)<<0))
#define CLEAR_COLOR_RGB(red,green,blue) ((2UL<<24)|(((red)&255UL)<<16)|(((green)&255UL)<<8)|(((blue)&255UL)<<0))
#define TAG(s) ((3UL<<24)|(((s)&255UL)<<0))
#define COLOR_RGB(red,green,blue) ((4UL<<24)|(((red)&255UL)<<16)|(((green)&255UL)<<8)|(((blue)&255UL)<<0))
#define BITMAP_HANDLE(handle) ((5UL<<24)|(((handle)&31UL)<<0))
#define CELL(cell) ((6UL<<24)|(((cell)&127UL)<<0))
#define BITMAP_LAYOUT(format,linestride,height) ((7UL<<24)|(((format)&31UL)<<19)|(((linestride)&1023UL)<<9)|(((height)&511UL)<<0))
#define BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((8UL<<24)|(((filter)&1UL)<<20)|(((wrapx)&1UL)<<19)|(((wrapy)&1UL)<<18)|(((width)&511UL)<<9)|(((height)&511UL)<<0))
#define ALPHA_FUNC(func,ref) ((9UL<<24)|(((func)&7UL)<<8)|(((ref)&255UL)<<0))
#define STENCIL_FUNC(func,ref,mask) ((10UL<<24)|(((func)&7UL)<<16)|(((ref)&255UL)<<8)|(((mask)&255UL)<<0))
#define BLEND_FUNC(src,dst) ((11UL<<24)|(((src)&7UL)<<3)|(((dst)&7UL)<<0))
#define STENCIL_OP(sfail,spass) ((12UL<<24)|(((sfail)&7UL)<<3)|(((spass)&7UL)<<0))
#define POINT_SIZE(size) ((13UL<<24)|(((size)&8191UL)<<0))
#define LINE_WIDTH(width) ((14UL<<24)|(((width)&4095UL)<<0))
#define CLEAR_COLOR_A(alpha) ((15UL<<24)|(((alpha)&255UL)<<0))
#define COLOR_A(alpha) ((16UL<<24)|(((alpha)&255UL)<<0))
#define CLEAR_STENCIL(s) ((17UL<<24)|(((s)&255UL)<<0))
#define CLEAR_TAG(s) ((18UL<<24)|(((s)&255UL)<<0))
#define STENCIL_MASK(mask) ((19UL<<24)|(((mask)&255UL)<<0))
#define TAG_MASK(mask) ((20UL<<24)|(((mask)&1UL)<<0))
#define BITMAP_TRANSFORM_A(a) ((21UL<<24)|(((a)&131071UL)<<0))
#define BITMAP_TRANSFORM_B(b) ((22UL<<24)|(((b)&131071UL)<<0))
#define BITMAP_TRANSFORM_C(c) ((23UL<<24)|(((c)&16777215UL)<<0))
#define BITMAP_TRANSFORM_D(d) ((24UL<<24)|(((d)&131071UL)<<0))
#define BITMAP_TRANSFORM_E(e) ((25UL<<24)|(((e)&131071UL)<<0))
#define BITMAP_TRANSFORM_F(f) ((26UL<<24)|(((f)&16777215UL)<<0))
#define SCISSOR_XY(x,y) ((27UL<<24)|(((x)&511UL)<<9)|(((y)&511UL)<<0))
#define SCISSOR_SIZE(width,height) ((28UL<<24)|(((width)&1023UL)<<10)|(((height)&1023UL)<<0))
#define CALL(dest) ((29UL<<24)|(((dest)&65535UL)<<0))
#define JUMP(dest) ((30UL<<24)|(((dest)&65535UL)<<0))
#define BEGIN(prim) ((31UL<<24)|(((prim)&15UL)<<0))
#define COLOR_MASK(r,g,b,a) ((32UL<<24)|(((r)&1UL)<<3)|(((g)&1UL)<<2)|(((b)&1UL)<<1)|(((a)&1UL)<<0))
#define CLEAR(c,s,t) ((38UL<<24)|(((c)&1UL)<<2)|(((s)&1UL)<<1)|(((t)&1UL)<<0))
#define END() ((33UL<<24))
#define SAVE_CONTEXT() ((34UL<<24))
#define RESTORE_CONTEXT() ((35UL<<24))
#define RETURN() ((36UL<<24))
#define MACRO(m) ((37UL<<24)|(((m)&1UL)<<0))
#define DISPLAY() ((0UL<<24))

#else   //of #ifndef FT_81X_ENABLE
// This is FT81x

#define LOW_FREQ_BOUND  58800000L //98% of 60Mhz

#define RAM_G_SIZE           (1024UL*1024UL)
#define FT81X_VERSION        "1.0.4"

#define ADC_DIFFERENTIAL     1UL
#define ADC_SINGLE_ENDED     0UL
#define ADPCM_SAMPLES        2UL
#define ALWAYS               7UL
#define ARGB1555             0UL
#define ARGB2                5UL
#define ARGB4                6UL
#define BARGRAPH             11UL
#define BILINEAR             1UL
#define BITMAPS              1UL
#define BORDER               0UL
#define CMDBUF_SIZE          (      4096UL) // 0x00001000
#define CMD_APPEND           (4294967070UL) // 0xFFFFFF1E
#define CMD_BGCOLOR          (4294967049UL) // 0xFFFFFF09
#define CMD_BITMAP_TRANSFORM (4294967073UL) // 0xFFFFFF21
#define CMD_BUTTON           (4294967053UL) // 0xFFFFFF0D
#define CMD_CALIBRATE        (4294967061UL) // 0xFFFFFF15
#define CMD_CLOCK            (4294967060UL) // 0xFFFFFF14
#define CMD_COLDSTART        (4294967090UL) // 0xFFFFFF32
#define CMD_CRC              (4294967043UL) // 0xFFFFFF03
#define CMD_CSKETCH          (4294967093UL) // 0xFFFFFF35
#define CMD_DIAL             (4294967085UL) // 0xFFFFFF2D
#define CMD_DLSTART          (4294967040UL) // 0xFFFFFF00
#define CMD_EXECUTE          (4294967047UL) // 0xFFFFFF07
#define CMD_FGCOLOR          (4294967050UL) // 0xFFFFFF0A
#define CMD_GAUGE            (4294967059UL) // 0xFFFFFF13
#define CMD_GETMATRIX        (4294967091UL) // 0xFFFFFF33
#define CMD_GETPOINT         (4294967048UL) // 0xFFFFFF08
#define CMD_GETPROPS         (4294967077UL) // 0xFFFFFF25
#define CMD_GETPTR           (4294967075UL) // 0xFFFFFF23
#define CMD_GRADCOLOR        (4294967092UL) // 0xFFFFFF34
#define CMD_GRADIENT         (4294967051UL) // 0xFFFFFF0B
#define CMD_HAMMERAUX        (4294967044UL) // 0xFFFFFF04
#define CMD_IDCT_DELETED     (4294967046UL) // 0xFFFFFF06
#define CMD_INFLATE          (4294967074UL) // 0xFFFFFF22
#define CMD_INTERRUPT        (4294967042UL) // 0xFFFFFF02
#define CMD_INT_RAMSHARED    (4294967101UL) // 0xFFFFFF3D
#define CMD_INT_SWLOADIMAGE  (4294967102UL) // 0xFFFFFF3E
#define CMD_KEYS             (4294967054UL) // 0xFFFFFF0E
#define CMD_LOADIDENTITY     (4294967078UL) // 0xFFFFFF26
#define CMD_LOADIMAGE        (4294967076UL) // 0xFFFFFF24
#define CMD_LOGO             (4294967089UL) // 0xFFFFFF31
#define CMD_MARCH            (4294967045UL) // 0xFFFFFF05
#define CMD_MEDIAFIFO        (4294967097UL) // 0xFFFFFF39
#define CMD_MEMCPY           (4294967069UL) // 0xFFFFFF1D
#define CMD_MEMCRC           (4294967064UL) // 0xFFFFFF18
#define CMD_MEMSET           (4294967067UL) // 0xFFFFFF1B
#define CMD_MEMWRITE         (4294967066UL) // 0xFFFFFF1A
#define CMD_MEMZERO          (4294967068UL) // 0xFFFFFF1C
#define CMD_NUMBER           (4294967086UL) // 0xFFFFFF2E
#define CMD_PLAYVIDEO        (4294967098UL) // 0xFFFFFF3A
#define CMD_PROGRESS         (4294967055UL) // 0xFFFFFF0F
#define CMD_REGREAD          (4294967065UL) // 0xFFFFFF19
#define CMD_ROMFONT          (4294967103UL) // 0xFFFFFF3F
#define CMD_ROTATE           (4294967081UL) // 0xFFFFFF29
#define CMD_SCALE            (4294967080UL) // 0xFFFFFF28
#define CMD_SCREENSAVER      (4294967087UL) // 0xFFFFFF2F
#define CMD_SCROLLBAR        (4294967057UL) // 0xFFFFFF11
#define CMD_SETBASE          (4294967096UL) // 0xFFFFFF38
#define CMD_SETBITMAP        (4294967107UL) // 0xFFFFFF43
#define CMD_SETFONT          (4294967083UL) // 0xFFFFFF2B
#define CMD_SETFONT2         (4294967099UL) // 0xFFFFFF3B
#define CMD_SETMATRIX        (4294967082UL) // 0xFFFFFF2A
#define CMD_SETROTATE        (4294967094UL) // 0xFFFFFF36
#define CMD_SETSCRATCH       (4294967100UL) // 0xFFFFFF3C
#define CMD_SKETCH           (4294967088UL) // 0xFFFFFF30
#define CMD_SLIDER           (4294967056UL) // 0xFFFFFF10
#define CMD_SNAPSHOT         (4294967071UL) // 0xFFFFFF1F
#define CMD_SNAPSHOT2        (4294967095UL) // 0xFFFFFF37
#define CMD_SPINNER          (4294967062UL) // 0xFFFFFF16
#define CMD_STOP             (4294967063UL) // 0xFFFFFF17
#define CMD_SWAP             (4294967041UL) // 0xFFFFFF01
#define CMD_SYNC             (4294967106UL) // 0xFFFFFF42
#define CMD_TEXT             (4294967052UL) // 0xFFFFFF0C
#define CMD_TOGGLE           (4294967058UL) // 0xFFFFFF12
#define CMD_TOUCH_TRANSFORM  (4294967072UL) // 0xFFFFFF20
#define CMD_TRACK            (4294967084UL) // 0xFFFFFF2C
#define CMD_TRANSLATE        (4294967079UL) // 0xFFFFFF27
#define CMD_VIDEOFRAME       (4294967105UL) // 0xFFFFFF41
#define CMD_VIDEOSTART       (4294967104UL) // 0xFFFFFF40
#define DECR                    (      4UL) //   0x000004
#define DLSWAP_DONE             (      0UL) //   0x000000
#define DLSWAP_FRAME            (      2UL) //   0x000002
#define DLSWAP_LINE             (      1UL) //   0x000001
#define DST_ALPHA               (      3UL) //   0x000003
#define EDGE_STRIP_A            (      7UL) //   0x000007
#define EDGE_STRIP_B            (      8UL) //   0x000008
#define EDGE_STRIP_L            (      6UL) //   0x000006
#define EDGE_STRIP_R            (      5UL) //   0x000005
#define EQUAL                   (      5UL) //   0x000005
#define GEQUAL                  (      4UL) //   0x000004
#define GREATER                 (      3UL) //   0x000003
#define INCR                    (      3UL) //   0x000003
#define INT_CMDEMPTY            (     32UL) //   0x000020
#define INT_CMDFLAG             (     64UL) //   0x000040
#define INT_CONVCOMPLETE        (    128UL) //   0x000080
#define INT_G8                  (     18UL) //   0x000012
#define INT_L8C                 (     12UL) //   0x00000C
#define INT_PLAYBACK            (     16UL) //   0x000010
#define INT_SOUND               (      8UL) //   0x000008
#define INT_SWAP                (      1UL) //   0x000001
#define INT_TAG                 (      4UL) //   0x000004
#define INT_TOUCH               (      2UL) //   0x000002
#define INT_VGA                 (     13UL) //   0x00000D
#define INVERT                  (      5UL) //   0x000005
#define KEEP                    (      1UL) //   0x000001
#define L1                      (      1UL) //   0x000001
#define L2                      (     17UL) //   0x000011
#define L4                      (      2UL) //   0x000002
#define L8                      (      3UL) //   0x000003
#define LEQUAL                  (      2UL) //   0x000002
#define LESS                    (      1UL) //   0x000001
#define LINEAR_SAMPLES          (      0UL) //   0x000000
#define LINES                   (      3UL) //   0x000003
#define LINE_STRIP              (      4UL) //   0x000004
#define NEAREST                 (      0UL) //   0x000000
#define NEVER                   (      0UL) //   0x000000
#define NOTEQUAL                (      6UL) //   0x000006
#define ONE                     (      1UL) //   0x000001
#define ONE_MINUS_DST_ALPHA     (      5UL) //   0x000005
#define ONE_MINUS_SRC_ALPHA     (      4UL) //   0x000004
#define OPT_CENTER              (   1536UL) //   0x000600
#define OPT_CENTERX             (    512UL) //   0x000200
#define OPT_CENTERY             (   1024UL) //   0x000400
#define OPT_FLAT                (    256UL) //   0x000100
#define OPT_FULLSCREEN          (      8UL) //   0x000008
#define OPT_MEDIAFIFO           (     16UL) //   0x000010
#define OPT_MONO                (      1UL) //   0x000001
#define OPT_NOBACK              (   4096UL) //   0x001000
#define OPT_NODL                (      2UL) //   0x000002
#define OPT_RGB565              (      0UL) //   0x000000
#define OPT_NOHANDS             (  49152UL) //   0x00C000
#define OPT_NOHM                (  16384UL) //   0x004000
#define OPT_NOPOINTER           (  16384UL) //   0x004000
#define OPT_NOSECS              (  32768UL) //   0x008000
#define OPT_NOTEAR              (      4UL) //   0x000004
#define OPT_NOTICKS             (   8192UL) //   0x002000
#define OPT_RIGHTX              (   2048UL) //   0x000800
#define OPT_SIGNED              (    256UL) //   0x000100
#define OPT_SOUND               (     32UL) //   0x000020
#define PALETTED                (      8UL) //   0x000008
#define PALETTED4444            (     15UL) //   0x00000F
#define PALETTED565             (     14UL) //   0x00000E
#define PALETTED8               (     16UL) //   0x000010
#define FTPOINTS                (      2UL) //   0x000002
#define RAM_CMD                 (3178496UL) //   0x308000
#define RAM_DL                  (3145728UL) //   0x300000
#define RAM_G                   (      0UL) //   0x000000
#define RAM_REG                 (3153920UL) //   0x302000
#define RAM_ROMSUB              (3186688UL) //   0x30A000
#define RECTS                   (      9UL) //   0x000009

#define ROMFONT_TABLEADDRESS    (3145724UL) //   0x2FFFFC

#define REG_ANALOG              (3154284UL) //   0x30216C
#define REG_ANA_COMP            (3154308UL) //   0x302184
#define REG_BIST_EN             (3154292UL) //   0x302174
#define REG_BUSYBITS            (3154152UL) //   0x3020E8
#define REG_CLOCK               (3153928UL) //   0x302008
#define REG_CMDB_SPACE          (3155316UL) //   0x302574
#define REG_CMDB_WRITE          (3155320UL) //   0x302578
#define REG_CMD_DL              (3154176UL) //   0x302100
#define REG_CMD_READ            (3154168UL) //   0x3020F8
#define REG_CMD_WRITE           (3154172UL) //   0x3020FC
#define REG_CPURESET            (3153952UL) //   0x302020
#define REG_CRC                 (3154296UL) //   0x302178
#define REG_CSPREAD             (3154024UL) //   0x302068
//Capacitive Touch
#define REG_CTOUCH_MODE         (3154180UL) //   0x302104
#define   CTOUCH_MODE_CONTINUOUS     ( 3UL) // 0x000003
#define   CTOUCH_MODE_ONESHOT        ( 1UL) // 0x000001
#define REG_CTOUCH_EXTEND       (3154184UL) //   0x302108
#define   CTOUCH_EXTEND_COMPATIBILITY (1UL) // 0x000001
#define   CTOUCH_EXTEND_EXTENDED      (0UL) // 0x000000
#define REG_CTOUCH_TOUCH0_XY    (3154212UL) //   0x302124
#define REG_CTOUCH_TOUCH1_XY    (3154204UL) //   0x30211C
#define REG_CTOUCH_TOUCH2_XY    (3154316UL) //   0x30218C
#define REG_CTOUCH_TOUCH3_XY    (3154320UL) //   0x302190
#define REG_CTOUCH_TOUCH4_X     (3154284UL) //   0x30216C
#define REG_CTOUCH_TOUCH4_Y     (3154208UL) //   0x302120



#define REG_CYA_TOUCH           (3154280UL) //   0x302168
#define REG_DATESTAMP           (3155300UL) //   0x302564
#define REG_DITHER              (3154016UL) //   0x302060
#define REG_DLSWAP              (3154004UL) //   0x302054
#define REG_FRAMES              (3153924UL) //   0x302004
#define REG_FREQUENCY           (3153932UL) //   0x30200C
#define REG_GPIO                (3154068UL) //   0x302094
#define REG_GPIOX               (3154076UL) //   0x30209C
#define BITS_GPIOX_LCD_DRIVE       (4096UL) //   0x00001000
#define REG_GPIOX_DIR           (3154072UL) //   0x302098
#define REG_GPIO_DIR            (3154064UL) //   0x302090
#define REG_HCYCLE              (3153964UL) //   0x30202C
#define REG_HOFFSET             (3153968UL) //   0x302030
#define REG_HSIZE               (3153972UL) //   0x302034
#define REG_HSYNC0              (3153976UL) //   0x302038
#define REG_HSYNC1              (3153980UL) //   0x30203C
#define REG_ID                  (3153920UL) //   0x302000
#define REG_INT_EN              (3154092UL) //   0x3020AC
#define REG_INT_FLAGS           (3154088UL) //   0x3020A8
#define REG_INT_MASK            (3154096UL) //   0x3020B0
#define REG_MACRO_0             (3154136UL) //   0x3020D8
#define REG_MACRO_1             (3154140UL) //   0x3020DC
#define REG_MEDIAFIFO_READ      (3182612UL) //   0x309014
#define REG_MEDIAFIFO_WRITE     (3182616UL) //   0x309018
#define REG_OUTBITS             (3154012UL) //   0x30205C
#define REG_PATCHED_ANALOG      (3154288UL) //   0x302170
#define REG_PATCHED_TOUCH_FAULT (3154284UL) //   0x30216C
#define REG_PCLK                (3154032UL) //   0x302070
#define REG_PCLK_POL            (3154028UL) //   0x30206C
#define REG_PLAY                (3154060UL) //   0x30208C
#define REG_PLAYBACK_FORMAT     (3154116UL) //   0x3020C4
#define REG_PLAYBACK_FREQ       (3154112UL) //   0x3020C0
#define REG_PLAYBACK_LENGTH     (3154104UL) //   0x3020B8
#define REG_PLAYBACK_LOOP       (3154120UL) //   0x3020C8
#define REG_PLAYBACK_PLAY       (3154124UL) //   0x3020CC
#define REG_PLAYBACK_READPTR    (3154108UL) //   0x3020BC
#define REG_PLAYBACK_START      (3154100UL) //   0x3020B4
#define REG_PWM_DUTY            (3154132UL) //   0x3020D4
#define REG_PWM_HZ              (3154128UL) //   0x3020D0
#define REG_RENDERMODE          (3153936UL) //   0x302010
#define REG_ROMSUB_SEL          (3154160UL) //   0x3020F0
#define REG_ROTATE              (3154008UL) //   0x302058
#define REG_SNAPFORMAT          (3153948UL) //   0x30201C
#define REG_SNAPSHOT            (3153944UL) //   0x302018
#define REG_SNAPY               (3153940UL) //   0x302014
#define REG_SOUND               (3154056UL) //   0x302088
#define REG_SPI_EARLY_TX        (3154300UL) //   0x30217C
#define REG_SPI_WIDTH           (3154312UL) //   0x302188
#define REG_SWIZZLE             (3154020UL) //   0x302064
#define REG_TAG                 (3154044UL) //   0x30207C
#define REG_TAG_X               (3154036UL) //   0x302074
#define REG_TAG_Y               (3154040UL) //   0x302078
#define REG_TAP_CRC             (3153956UL) //   0x302024
#define REG_TAP_MASK            (3153960UL) //   0x302028
#define REG_TOUCH_ADC_MODE      (3154184UL) //   0x302108
#define REG_TOUCH_CHARGE        (3154188UL) //   0x30210C
#define REG_TOUCH_DIRECT_XY     (3154316UL) //   0x30218C
#define REG_TOUCH_DIRECT_Z1Z2   (3154320UL) //   0x302190
#define REG_TOUCH_FAULT         (3154288UL) //   0x302170
#define REG_TOUCH_MODE          (3154180UL) //   0x302104
#define   TOUCH_MODE_CONTINUOUS      ( 3UL) // 0x000003
#define   TOUCH_MODE_FRAME           ( 2UL) // 0x000002
#define   TOUCH_MODE_OFF             ( 0UL) // 0x000000
#define   TOUCHMODE_ONESHOT          ( 1UL) // 0x000001
#define REG_TOUCH_OVERSAMPLE    (3154196UL) //   0x302114
#define REG_TOUCH_RAW_XY        (3154204UL) //   0x30211C
#define REG_TOUCH_RZ            (3154208UL) //   0x302120
#define REG_TOUCH_RZTHRESH      (3154200UL) //   0x302118
#define REG_TOUCH_SCREEN_XY     (3154212UL) //   0x302124
#define REG_TOUCH_SETTLE        (3154192UL) //   0x302110
#define REG_TOUCH_TAG           (3154220UL) //   0x30212C
#define REG_TOUCH_TAG1          (3154228UL) //   0x302134
#define REG_TOUCH_TAG1_XY       (3154224UL) //   0x302130
#define REG_TOUCH_TAG2          (3154236UL) //   0x30213C
#define REG_TOUCH_TAG2_XY       (3154232UL) //   0x302138
#define REG_TOUCH_TAG3          (3154244UL) //   0x302144
#define REG_TOUCH_TAG3_XY       (3154240UL) //   0x302140
#define REG_TOUCH_TAG4          (3154252UL) //   0x30214C
#define REG_TOUCH_TAG4_XY       (3154248UL) //   0x302148
#define REG_TOUCH_TAG_XY        (3154216UL) //   0x302128
#define REG_TOUCH_TRANSFORM_A   (3154256UL) //   0x302150
#define REG_TOUCH_TRANSFORM_B   (3154260UL) //   0x302154
#define REG_TOUCH_TRANSFORM_C   (3154264UL) //   0x302158
#define REG_TOUCH_TRANSFORM_D   (3154268UL) //   0x30215C
#define REG_TOUCH_TRANSFORM_E   (3154272UL) //   0x302160
#define REG_TOUCH_TRANSFORM_F   (3154276UL) //   0x302164

#define REG_TOUCH_CONFIG        (3154280UL) //   0x302168

#define REG_TRACKER             (3182592UL) //   0x309000
#define REG_TRACKER_1           (3182596UL) //   0x309004
#define REG_TRACKER_2           (3182600UL) //   0x309008
#define REG_TRACKER_3           (3182604UL) //   0x30900C
#define REG_TRACKER_4           (3182608UL) //   0x309010
#define REG_TRIM                (3154304UL) //   0x302180
#define REG_VCYCLE              (3153984UL) //   0x302040
#define REG_VOFFSET             (3153988UL) //   0x302044
#define REG_VOL_PB              (3154048UL) //   0x302080
#define REG_VOL_SOUND           (3154052UL) //   0x302084
#define REG_VSIZE               (3153992UL) //   0x302048
#define REG_VSYNC0              (3153996UL) //   0x30204C
#define REG_VSYNC1              (3154000UL) //   0x302050
#define REPEAT                  (      1UL) //   0x000001
#define REPLACE                 (      2UL) //   0x000002
#define RGB332                  (      4UL) //   0x000004
#define RGB565                  (      7UL) //   0x000007
#define SRC_ALPHA               (      2UL) //   0x000002
#define TEXT8X8                 (      9UL) //   0x000009
#define TEXTVGA                 (     10UL) //   0x00000A
#define TOUCHMODE_CONTINUOUS    (      3UL) //   0x000003
#define TOUCHMODE_FRAME         (      2UL) //   0x000002
#define TOUCHMODE_OFF           (      0UL) //   0x000000
#define TOUCHMODE_ONESHOT       (      1UL) //   0x000001
#define ULAW_SAMPLES            (      1UL) //   0x000001
#define VERTEX2F(x,y) ((1UL<<30)|(((x)&32767UL)<<15)|(((y)&32767UL)<<0))
#define VERTEX2II(x,y,handle,cell) ((2UL<<30)|(((x)&511UL)<<21)|(((y)&511UL)<<12)|(((handle)&31UL)<<7)|(((cell)&127UL)<<0))
#define BITMAP_SOURCE(addr) ((1UL<<24)|(((addr)&4194303UL)<<0))
#define CLEAR_COLOR_RGB(red,green,blue) ((2UL<<24)|(((red)&255UL)<<16)|(((green)&255UL)<<8)|(((blue)&255UL)<<0))
#define TAG(s) ((3UL<<24)|(((s)&255UL)<<0))
#define COLOR_RGB(red,green,blue) ((4UL<<24)|(((red)&255UL)<<16)|(((green)&255UL)<<8)|(((blue)&255UL)<<0))
#define BITMAP_HANDLE(handle) ((5UL<<24)|(((handle)&31UL)<<0))
#define CELL(cell) ((6UL<<24)|(((cell)&127UL)<<0))
#define BITMAP_LAYOUT(format,linestride,height) ((7UL<<24)|(((format)&31UL)<<19)|(((linestride)&1023UL)<<9)|(((height)&511UL)<<0))
#define BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((8UL<<24)|(((filter)&1UL)<<20)|(((wrapx)&1UL)<<19)|(((wrapy)&1UL)<<18)|(((width)&511UL)<<9)|(((height)&511UL)<<0))
#define ALPHA_FUNC(func,ref) ((9UL<<24)|(((func)&7UL)<<8)|(((ref)&255UL)<<0))
#define STENCIL_FUNC(func,ref,mask) ((10UL<<24)|(((func)&7UL)<<16)|(((ref)&255UL)<<8)|(((mask)&255UL)<<0))
#define BLEND_FUNC(src,dst) ((11UL<<24)|(((src)&7UL)<<3)|(((dst)&7UL)<<0))
#define STENCIL_OP(sfail,spass) ((12UL<<24)|(((sfail)&7UL)<<3)|(((spass)&7UL)<<0))
#define POINT_SIZE(size) ((13UL<<24)|(((size)&8191UL)<<0))
#define LINE_WIDTH(width) ((14UL<<24)|(((width)&4095UL)<<0))
#define CLEAR_COLOR_A(alpha) ((15UL<<24)|(((alpha)&255UL)<<0))
#define COLOR_A(alpha) ((16UL<<24)|(((alpha)&255UL)<<0))
#define CLEAR_STENCIL(s) ((17UL<<24)|(((s)&255UL)<<0))
#define CLEAR_TAG(s) ((18UL<<24)|(((s)&255UL)<<0))
#define STENCIL_MASK(mask) ((19UL<<24)|(((mask)&255UL)<<0))
#define TAG_MASK(mask) ((20UL<<24)|(((mask)&1UL)<<0))
#define BITMAP_TRANSFORM_A(a) ((21UL<<24)|(((a)&131071UL)<<0))
#define BITMAP_TRANSFORM_B(b) ((22UL<<24)|(((b)&131071UL)<<0))
#define BITMAP_TRANSFORM_C(c) ((23UL<<24)|(((c)&16777215UL)<<0))
#define BITMAP_TRANSFORM_D(d) ((24UL<<24)|(((d)&131071UL)<<0))
#define BITMAP_TRANSFORM_E(e) ((25UL<<24)|(((e)&131071UL)<<0))
#define BITMAP_TRANSFORM_F(f) ((26UL<<24)|(((f)&16777215UL)<<0))
#define SCISSOR_XY(x,y) ((27UL<<24)|(((x)&2047UL)<<11)|(((y)&2047UL)<<0))
#define SCISSOR_SIZE(width,height) ((28UL<<24)|(((width)&4095UL)<<12)|(((height)&4095UL)<<0))
#define CALL(dest) ((29UL<<24)|(((dest)&65535UL)<<0))
#define JUMP(dest) ((30UL<<24)|(((dest)&65535UL)<<0))
#define BEGIN(prim) ((31UL<<24)|(((prim)&15UL)<<0))
#define COLOR_MASK(r,g,b,a) ((32UL<<24)|(((r)&1UL)<<3)|(((g)&1UL)<<2)|(((b)&1UL)<<1)|(((a)&1UL)<<0))
#define CLEAR(c,s,t) ((38UL<<24)|(((c)&1UL)<<2)|(((s)&1UL)<<1)|(((t)&1UL)<<0))
#define VERTEX_FORMAT(frac) ((39UL<<24)|(((frac)&7UL)<<0))
#define BITMAP_LAYOUT_H(linestride,height) ((40UL<<24)|(((linestride)&3UL)<<2)|(((height)&3UL)<<0))
#define BITMAP_SIZE_H(width,height) ((41UL<<24)|(((width)&3UL)<<2)|(((height)&3UL)<<0))
#define PALETTE_SOURCE(addr) ((42UL<<24)|(((addr)&4194303UL)<<0))
#define VERTEX_TRANSLATE_X(x) ((43UL<<24)|(((x)&131071UL)<<0))
#define VERTEX_TRANSLATE_Y(y) ((44UL<<24)|(((y)&131071UL)<<0))
#define NOP() ((45UL<<24))
#define END() ((33UL<<24))
#define SAVE_CONTEXT() ((34UL<<24))
#define RESTORE_CONTEXT() ((35UL<<24))
#define RETURN() ((36UL<<24))
#define MACRO(m) ((37UL<<24)|(((m)&1UL)<<0))
#define DISPLAY() ((0UL<<24))

#endif  // of else of #ifndef FT_81X_ENABLE

#define FT_GPU_NUMCHAR_PERFONT (128)
#define FT_GPU_FONT_TABLE_SIZE (148)

///* FT81x and FT80x font table structure */
///* Font table address in ROM can be found by reading the address from 0xFFFFC location. */
///* 16 font tables are present at the address read from location 0xFFFFC */
//typedef struct FT_Gpu_Fonts
//{
//  /* All the values are in bytes */
//  /* Width of each character font from 0 to 127 */
//  ft_uint8_t  FontWidth[FT_GPU_NUMCHAR_PERFONT];
//  /* Bitmap format of font wrt bitmap formats supported by FT800 - L1, L4, L8 */
//  ft_uint32_t  FontBitmapFormat;
//  /* Font line stride in FT800 ROM */
//  ft_uint32_t  FontLineStride;
//  /* Font width in pixels */
//  ft_uint32_t  FontWidthInPixels;
//  /* Font height in pixels */
//  ft_uint32_t  FontHeightInPixels;
//  /* Pointer to font graphics raw data */
//  ft_uint32_t  PointerToFontGraphicsData;
//}FT_Gpu_Fonts_t;

//#ifdef  __cplusplus
//}
//#endif

#endif  /* __FT8XX_DEFINES_H__ */
