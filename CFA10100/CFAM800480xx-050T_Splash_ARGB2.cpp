#include <Arduino.h>
#include <stdarg.h>
#include "CFA10100_defines.h"
#include "CFAM800480xx-050T_Splash_ARGB2.h"

#if 1==LOGO_DEMO
#if 1==LOGO_PNG_0_ARGB2_1

const uint8_t CFAM800480xx050T_ARGB2_LOGO[LOGO_SIZE_ARGB2] PROGMEM =
  {
  0x78, 0x9c, 0xed, 0x9d, 0x6d, 0x7a, 0xec, 0x2a, 0x0e, 0x84, 0x97, 0xe6, 0xad, 0xfb, 0x79, 0x7a,
  0x43, 0xbd, 0x84, 0x99, 0x73, 0x93, 0x4e, 0x1b, 0x51, 0x25, 0x84, 0x11, 0x60, 0x6c, 0xd5, 0x8f,
  0x9b, 0x18, 0x84, 0x28, 0xbd, 0x2d, 0x7f, 0xc4, 0xc9, 0x9c, 0xd9, 0xb6, 0x50, 0x28, 0x14, 0x0a,
  0x85, 0x42, 0x65, 0xed, 0xc3, 0x17, 0xde, 0x5e, 0xfb, 0x59, 0x34, 0xfb, 0xaf, 0x5c, 0xdd, 0xdc,
  0x42, 0xe7, 0xa1, 0x04, 0x53, 0xa2, 0xf3, 0x50, 0xf6, 0x60, 0x8a, 0xd5, 0x00, 0x25, 0x90, 0x62,
  0xb5, 0x50, 0x09, 0xa6, 0x50, 0x2d, 0x54, 0x28, 0xd2, 0x87, 0xb3, 0xee, 0xc1, 0x74, 0xff, 0xaa,
  0xd9, 0xdf, 0x8a, 0xd2, 0x6a, 0x2f, 0xb1, 0x21, 0x93, 0x7b, 0x22, 0x67, 0xbf, 0x2b, 0xe8, 0xaf,
  0xf2, 0xac, 0xfc, 0xbd, 0xc4, 0xc6, 0x84, 0xf4, 0x89, 0x54, 0x59, 0xf1, 0x19, 0x19, 0xeb, 0x55,
  0x33, 0x90, 0x32, 0xa6, 0x39, 0x52, 0xde, 0x8f, 0x3c, 0xe1, 0x03, 0x99, 0xf2, 0xea, 0x11, 0x52,
  0x06, 0x8f, 0xe5, 0x6c, 0x7a, 0xf2, 0x5d, 0x56, 0x94, 0xd9, 0x9e, 0x91, 0xa9, 0x67, 0xfa, 0x7b,
  0xd4, 0xbb, 0x86, 0xab, 0xa9, 0xc8, 0x14, 0x1f, 0x92, 0x41, 0xad, 0xa7, 0x9f, 0x23, 0x06, 0x81,
  0xe1, 0x82, 0x8b, 0x71, 0xb6, 0x60, 0x4a, 0xce, 0x60, 0x19, 0x08, 0xd7, 0xa2, 0x64, 0xcf, 0x45,
  0xaa, 0x30, 0xc5, 0x81, 0x68, 0x2d, 0x4c, 0xf6, 0x10, 0xaa, 0xac, 0x54, 0x2f, 0xa6, 0x12, 0xe9,
  0xed, 0xb1, 0x2a, 0x85, 0x96, 0xeb, 0x87, 0x4b, 0xd1, 0xb2, 0x27, 0x31, 0x55, 0x2b, 0x55, 0xea,
  0xd7, 0x18, 0xc1, 0x65, 0x8f, 0x41, 0x5a, 0x38, 0x25, 0x0b, 0xed, 0x5b, 0xc3, 0x34, 0x90, 0x8a,
  0xf9, 0xc2, 0xa2, 0xaa, 0x36, 0xbd, 0xf9, 0x0f, 0x50, 0x05, 0xa2, 0xc6, 0x0b, 0x63, 0x5d, 0x9b,
  0x76, 0x2a, 0xe5, 0x2a, 0x4a, 0xeb, 0x44, 0xf5, 0x2a, 0xc0, 0x3e, 0x13, 0x79, 0x08, 0xc4, 0xf7,
  0x30, 0xa6, 0xe5, 0x08, 0xf8, 0xfe, 0xa4, 0x18, 0x82, 0x12, 0x05, 0x52, 0x0b, 0xb0, 0x76, 0xa6,
  0x77, 0x62, 0x6d, 0x68, 0x1c, 0x0a, 0xac, 0x3c, 0x60, 0x44, 0xba, 0x1f, 0x74, 0xae, 0x8c, 0x2b,
  0xc9, 0x52, 0x48, 0xb9, 0x2b, 0xeb, 0xda, 0x94, 0xe5, 0x5f, 0x9a, 0xaa, 0xd6, 0x60, 0x28, 0xdc,
  0x87, 0x29, 0x61, 0x26, 0x89, 0xae, 0x09, 0xb5, 0xfc, 0xb6, 0xde, 0xf8, 0xca, 0x2e, 0x4b, 0xc2,
  0x97, 0x90, 0x31, 0xdb, 0xaf, 0x0b, 0xae, 0x2f, 0xd8, 0x4f, 0x5a, 0x55, 0x94, 0xd8, 0x2e, 0x73,
  0xf0, 0x25, 0xac, 0x4d, 0x0d, 0xdb, 0x5f, 0x5f, 0xb4, 0x54, 0x5e, 0x15, 0x1f, 0x61, 0x6b, 0x94,
  0x24, 0x36, 0xa4, 0x4b, 0x41, 0xe5, 0xed, 0x53, 0x66, 0xba, 0xff, 0xb5, 0xb8, 0x95, 0x29, 0xda,
  0x27, 0x77, 0x73, 0x1c, 0x5f, 0x90, 0x69, 0xa1, 0x2e, 0x0c, 0x35, 0x1f, 0xad, 0x67, 0x8a, 0x59,
  0x81, 0xcd, 0x6c, 0x6f, 0x6b, 0xaf, 0x24, 0xad, 0x81, 0x2a, 0x98, 0xca, 0x9f, 0x4d, 0xc5, 0x12,
  0x6d, 0x17, 0xe4, 0x06, 0x8e, 0x7a, 0x96, 0xdd, 0x57, 0x7a, 0xb7, 0x60, 0xa6, 0xe8, 0x91, 0x5c,
  0x0c, 0x95, 0x98, 0x42, 0x78, 0x85, 0x51, 0x9f, 0x82, 0x07, 0x88, 0xf8, 0xdd, 0x41, 0x5b, 0x66,
  0x8b, 0xd2, 0xd1, 0x64, 0xa0, 0xf4, 0xf3, 0x92, 0xd6, 0x90, 0xec, 0xc5, 0x6c, 0x7d, 0x71, 0x93,
  0x64, 0xf1, 0x9b, 0xc7, 0xc0, 0xee, 0xad, 0x48, 0x50, 0xd7, 0x90, 0xcf, 0x60, 0x7a, 0xea, 0x7c,
  0x2c, 0xdd, 0x77, 0xe8, 0xc7, 0xf4, 0x10, 0xa6, 0x2e, 0x9b, 0x5a, 0xaf, 0x9b, 0x8b, 0x32, 0x35,
  0xbc, 0x2e, 0xed, 0xb0, 0xad, 0xcd, 0xca, 0x99, 0x73, 0x62, 0xae, 0x58, 0x21, 0x32, 0xc0, 0xbd,
  0xa4, 0x5b, 0x31, 0x35, 0x3c, 0xfd, 0x7d, 0x47, 0xe8, 0x45, 0xae, 0x87, 0x2f, 0xb8, 0xd3, 0x40,
  0x07, 0xa7, 0x25, 0xec, 0x01, 0xc3, 0x3b, 0xd0, 0x20, 0x63, 0xfc, 0x8a, 0x70, 0x61, 0xa4, 0x99,
  0xc1, 0xdc, 0xf1, 0x24, 0xa4, 0x85, 0x87, 0x81, 0xeb, 0x32, 0xcd, 0x1d, 0x32, 0xc8, 0xc3, 0x91,
  0x16, 0x4e, 0x19, 0x10, 0x3e, 0xc6, 0x55, 0x49, 0x00, 0x93, 0xa1, 0x4f, 0x47, 0xbb, 0x53, 0xfd,
  0x26, 0x73, 0xa3, 0x9c, 0xa9, 0x32, 0x41, 0x45, 0x2f, 0x49, 0xc6, 0xba, 0xcb, 0x6d, 0x90, 0xd0,
  0x81, 0xe6, 0xb8, 0x72, 0x9b, 0xc8, 0xdd, 0x14, 0xa2, 0x35, 0x6f, 0xa4, 0xe7, 0xf8, 0x63, 0xca,
  0x8c, 0x5e, 0xd4, 0x9c, 0x86, 0x74, 0xd2, 0x69, 0x24, 0x05, 0x5f, 0x7f, 0x1e, 0x0f, 0x67, 0x19,
  0x4b, 0x55, 0x8d, 0x74, 0xa2, 0xef, 0x1d, 0x5f, 0xf9, 0x0f, 0x47, 0xb3, 0x9c, 0x49, 0x2d, 0xd4,
  0xa5, 0x45, 0xa8, 0xb3, 0xac, 0x65, 0x2a, 0x20, 0xd5, 0x79, 0x8f, 0x53, 0xb6, 0x7d, 0xe2, 0xe9,
  0x62, 0x4c, 0xf5, 0x73, 0x1b, 0xb4, 0xf1, 0x1c, 0xeb, 0xf9, 0xd6, 0x47, 0x43, 0xb3, 0x3f, 0x71,
  0x24, 0xe2, 0x09, 0x11, 0x9d, 0xe4, 0x1d, 0xec, 0x7c, 0xf0, 0x73, 0x45, 0xa6, 0x58, 0x0c, 0xe9,
  0x04, 0xf7, 0x70, 0xdf, 0x0c, 0xea, 0x68, 0x57, 0xd5, 0x82, 0x14, 0x67, 0x41, 0xc5, 0xbb, 0xce,
  0xfe, 0xa4, 0x6b, 0xc5, 0xdc, 0x4e, 0xf0, 0xbf, 0xd3, 0x9b, 0xd0, 0x52, 0x4c, 0x15, 0xaf, 0x13,
  0x98, 0xf2, 0xff, 0x49, 0xc7, 0x42, 0x4c, 0x35, 0xa7, 0xc3, 0x0b, 0xd8, 0x3f, 0x77, 0x76, 0x36,
  0xbb, 0x02, 0x53, 0xfd, 0xc3, 0x1f, 0x5d, 0xc0, 0xcf, 0x66, 0x7c, 0xc7, 0x25, 0xa0, 0x16, 0x4e,
  0xa7, 0xc1, 0xfe, 0xcb, 0xc4, 0x56, 0x60, 0xaa, 0x9b, 0x1c, 0xec, 0xdf, 0xd2, 0x85, 0x2b, 0x30,
  0xd5, 0x5a, 0x71, 0xb4, 0x7f, 0xd3, 0x99, 0xbd, 0x02, 0x53, 0xfa, 0x08, 0x3d, 0xe1, 0xda, 0x65,
  0xda, 0x71, 0x05, 0xa6, 0xe4, 0x96, 0x30, 0x01, 0x69, 0x1d, 0xd4, 0x61, 0xa6, 0x4e, 0xa9, 0xf4,
  0x30, 0x38, 0xd2, 0xca, 0x5d, 0x98, 0xe6, 0xda, 0x27, 0x21, 0x35, 0x35, 0xea, 0x9a, 0x4c, 0xa7,
  0x21, 0x35, 0x35, 0xea, 0x12, 0x17, 0x54, 0xa1, 0x7d, 0x22, 0x52, 0x0b, 0xd4, 0x05, 0x99, 0x4e,
  0x25, 0xba, 0x19, 0xa0, 0x2e, 0x87, 0x74, 0x6e, 0x93, 0xa6, 0x16, 0xf4, 0xf9, 0xa1, 0x9e, 0x5a,
  0x34, 0x9f, 0x68, 0xb1, 0x51, 0x17, 0x3b, 0xf5, 0xcb, 0x4d, 0xea, 0x59, 0x09, 0xdf, 0x44, 0xb3,
  0x30, 0xfb, 0x13, 0xaf, 0x54, 0x99, 0xa8, 0x5f, 0x29, 0xea, 0x4e, 0x7c, 0x6e, 0xfa, 0x49, 0x54,
  0x2d, 0x4b, 0xa1, 0x9b, 0xd2, 0x60, 0x67, 0x36, 0xd2, 0x3b, 0x95, 0xce, 0x34, 0x6d, 0x3f, 0x54,
  0xa6, 0x0b, 0x59, 0x7b, 0x59, 0xa6, 0x13, 0x42, 0x6d, 0xd4, 0xf3, 0x7b, 0x8f, 0x97, 0xea, 0x58,
  0x42, 0x3d, 0x5b, 0x99, 0x21, 0x49, 0x01, 0xea, 0xc9, 0x8d, 0x27, 0x49, 0x33, 0x9c, 0x31, 0x3d,
  0x57, 0x9c, 0x29, 0x03, 0x0d, 0x58, 0x8e, 0xe8, 0xa6, 0xdc, 0xd9, 0x01, 0x51, 0x07, 0xa4, 0xe5,
  0xed, 0xce, 0xec, 0xb1, 0x86, 0xbc, 0x88, 0x9a, 0x7f, 0xa5, 0xdc, 0xb8, 0xcd, 0xe5, 0xe5, 0x06,
  0x74, 0x93, 0xac, 0x0c, 0xef, 0x9e, 0x6f, 0xc9, 0xd4, 0x93, 0x68, 0x0d, 0xa9, 0xfb, 0x22, 0x45,
  0x44, 0x1d, 0x98, 0xb2, 0xd9, 0x2c, 0xf6, 0xf4, 0x4e, 0x57, 0x15, 0x06, 0xda, 0x50, 0x6a, 0x61,
  0xf9, 0x9e, 0x41, 0x3d, 0xb9, 0xcf, 0x65, 0x05, 0x59, 0xf6, 0x64, 0x2a, 0x67, 0x9e, 0x80, 0xf4,
  0x38, 0xdc, 0x94, 0x53, 0x9b, 0x3c, 0xe9, 0x76, 0x09, 0xd1, 0xd3, 0xbd, 0xa5, 0x70, 0x03, 0xd3,
  0x3b, 0x43, 0xa5, 0x17, 0xd0, 0x5e, 0x77, 0xa8, 0xc6, 0x4b, 0xf5, 0x02, 0x22, 0x40, 0x7d, 0x92,
  0xea, 0x1b, 0x7a, 0xed, 0x76, 0x39, 0x75, 0x20, 0x6a, 0x7d, 0xef, 0xe5, 0xb7, 0xdf, 0xc5, 0xd4,
  0xa5, 0x42, 0x3d, 0xe7, 0x00, 0xa6, 0xef, 0xb7, 0x7f, 0x64, 0x85, 0x7a, 0x14, 0x58, 0xa0, 0xd6,
  0x1d, 0xea, 0xfb, 0x6d, 0x45, 0x65, 0x8f, 0xac, 0xd1, 0x0d, 0x99, 0xbe, 0xdf, 0x56, 0x54, 0xf6,
  0xc8, 0x3a, 0x95, 0x0a, 0x3c, 0x53, 0xfb, 0x54, 0xa6, 0xef, 0x8f, 0x1c, 0x23, 0x2b, 0x65, 0xb8,
  0x49, 0xbb, 0xe6, 0x6c, 0x48, 0x6b, 0xd2, 0xfb, 0x6d, 0x44, 0xf5, 0x36, 0x47, 0xd6, 0x4b, 0x01,
  0xb0, 0x1e, 0xd3, 0xf7, 0xdb, 0x8a, 0xca, 0x1e, 0x79, 0x46, 0xfe, 0xd5, 0x17, 0x9e, 0x26, 0xfa,
  0x31, 0x7d, 0xbf, 0xad, 0xa8, 0xec, 0x91, 0xe7, 0xe4, 0xff, 0x07, 0x8b, 0x3a, 0xd4, 0x6e, 0x4c,
  0x25, 0x28, 0xce, 0xca, 0x1e, 0xe9, 0xaf, 0x56, 0xa6, 0xae, 0x97, 0xe9, 0x92, 0x00, 0x28, 0x82,
  0xca, 0x1e, 0xd9, 0x22, 0x52, 0x66, 0x73, 0xa3, 0x7a, 0x5e, 0xa6, 0x75, 0x25, 0x78, 0x54, 0x54,
  0xf6, 0xc8, 0x26, 0x51, 0x06, 0xcd, 0x4c, 0x47, 0xfd, 0x91, 0x89, 0xe8, 0x38, 0xa5, 0x01, 0xc5,
  0x4c, 0x37, 0xa8, 0xfb, 0x4e, 0x28, 0xb4, 0x37, 0xea, 0x98, 0x3f, 0x32, 0xc9, 0xc8, 0x50, 0xa8,
  0xf6, 0xc8, 0x56, 0xed, 0x3b, 0xc6, 0xea, 0xc0, 0x74, 0xc7, 0x33, 0xad, 0x8e, 0x13, 0x21, 0x2c,
  0x18, 0x15, 0x18, 0xed, 0x05, 0x75, 0xcf, 0x94, 0x4e, 0xb4, 0x25, 0x44, 0xe3, 0x2e, 0xb6, 0x7f,
  0x44, 0xa0, 0xe8, 0x9c, 0x0b, 0xa0, 0x1d, 0x94, 0x33, 0xfd, 0x2d, 0xfb, 0x34, 0x01, 0xdc, 0xf8,
  0x03, 0x91, 0x7e, 0x27, 0x50, 0x24, 0x4d, 0xe1, 0x68, 0x0c, 0x42, 0xfd, 0x57, 0xfa, 0x69, 0x04,
  0x24, 0xa3, 0x3b, 0x53, 0x85, 0x87, 0x15, 0x69, 0xa7, 0xf3, 0x5f, 0x27, 0xe0, 0x0e, 0xd5, 0xcd,
  0x77, 0xa1, 0xc5, 0x8c, 0x48, 0xe7, 0x40, 0xf5, 0x4d, 0xe9, 0xe6, 0xba, 0x78, 0xd6, 0xda, 0xef,
  0x44, 0x1d, 0xa0, 0x7e, 0xab, 0x75, 0xc4, 0xd0, 0x9b, 0xa9, 0xbd, 0xbb, 0x0c, 0x81, 0x5d, 0xa1,
  0xba, 0xfd, 0x11, 0xaa, 0xfb, 0x1f, 0x0d, 0x09, 0xd9, 0x29, 0x98, 0x22, 0xfd, 0xcf, 0x7f, 0x51,
  0xaf, 0x17, 0x88, 0x8e, 0x27, 0xbe, 0x33, 0xd2, 0x7e, 0x50, 0xb3, 0x81, 0x66, 0x14, 0x03, 0x90,
  0xea, 0x04, 0xde, 0xd6, 0x48, 0x73, 0xa0, 0x59, 0xa8, 0x66, 0x27, 0x18, 0x9d, 0x89, 0x7a, 0xbd,
  0x7e, 0x7e, 0xdb, 0x43, 0x8d, 0x62, 0x55, 0xbb, 0xe3, 0xf0, 0x90, 0xbd, 0xfc, 0x0a, 0x50, 0xef,
  0x8a, 0x58, 0xa3, 0x38, 0xbb, 0x8b, 0x01, 0xed, 0xf5, 0x46, 0x5f, 0xc6, 0x3a, 0x40, 0xbd, 0x62,
  0x3f, 0x62, 0x99, 0x8b, 0xcf, 0x02, 0xeb, 0x98, 0x3e, 0x07, 0x6a, 0x5e, 0xba, 0xd3, 0xef, 0x48,
  0x40, 0x78, 0x33, 0xd5, 0x35, 0x98, 0xda, 0x2b, 0xaf, 0x65, 0x84, 0xe2, 0x1f, 0x01, 0xd5, 0x5e,
  0x78, 0x35, 0x22, 0xb8, 0xa0, 0x15, 0x6a, 0x30, 0xed, 0xc5, 0xb4, 0x31, 0x49, 0x67, 0xad, 0xc6,
  0x74, 0x05, 0x05, 0x53, 0x7f, 0x05, 0x53, 0x7f, 0x05, 0x53, 0x7f, 0x05, 0x53, 0x7f, 0x05, 0x53,
  0x7f, 0x05, 0x53, 0x7f, 0x05, 0xd3, 0x99, 0x0a, 0x42, 0xfe, 0x0a, 0xa6, 0xfe, 0x0a, 0xa6, 0xfe,
  0x0a, 0xa6, 0xfe, 0x0a, 0xa6, 0x58, 0xf8, 0x56, 0x5c, 0x92, 0xb2, 0xb6, 0x25, 0x6d, 0x9a, 0x63,
  0x59, 0xb5, 0x14, 0x5d, 0x3b, 0x55, 0x99, 0x7e, 0x59, 0xb5, 0x14, 0x5d, 0x3b, 0x55, 0x99, 0x7e,
  0x59, 0xb5, 0x14, 0x5d, 0x3b, 0x55, 0x99, 0x7e, 0x59, 0xb5, 0x14, 0x5d, 0x3b, 0x55, 0x99, 0x7e,
  0x59, 0xb5, 0x14, 0x5d, 0x3b, 0x55, 0x99, 0x7e, 0x59, 0xb5, 0x14, 0x5d, 0x3b, 0x55, 0x99, 0x7e,
  0x59, 0xb5, 0x14, 0x7d, 0x47, 0x1e, 0x1e, 0x0a, 0xa6, 0xfe, 0x0a, 0xa6, 0xfe, 0x0a, 0xa6, 0xfe,
  0x0a, 0xa6, 0xfe, 0x0a, 0xa6, 0xff, 0xd7, 0x2b, 0x55, 0x29, 0x10, 0x8f, 0x7c, 0xbf, 0xeb, 0xc4,
  0xf4, 0x5c, 0xda, 0x34, 0xc7, 0x8b, 0x88, 0xcf, 0x95, 0x56, 0x35, 0x32, 0x45, 0x11, 0xc1, 0xd4,
  0x84, 0x94, 0x85, 0xc2, 0x90, 0x60, 0xda, 0xc2, 0x14, 0xc7, 0x04, 0xd3, 0x06, 0xa6, 0x24, 0x28,
  0x98, 0x36, 0x33, 0x4d, 0xbf, 0x5b, 0x8f, 0x29, 0x28, 0x47, 0x1b, 0xe2, 0x10, 0x0a, 0x2a, 0x43,
  0x17, 0xd9, 0x44, 0x7c, 0x02, 0xf8, 0xdf, 0x97, 0x96, 0xa2, 0x2d, 0x3c, 0x3c, 0x34, 0x84, 0x69,
  0x45, 0x50, 0x30, 0x3d, 0x93, 0x5e, 0x0f, 0x4a, 0x17, 0xa4, 0xe3, 0xff, 0xbe, 0x06, 0xd3, 0x0a,
  0xa6, 0xec, 0x40, 0x7c, 0x17, 0x4c, 0x3f, 0x97, 0x53, 0x35, 0x3c, 0x6f, 0xcd, 0xdf, 0x23, 0xf4,
  0x5d, 0x30, 0x7d, 0xa5, 0xb2, 0x24, 0xfb, 0x1e, 0x21, 0xa4, 0xc1, 0xb4, 0xf6, 0x49, 0x4a, 0x1c,
  0xe5, 0x67, 0x7e, 0x3c, 0x4b, 0x81, 0x07, 0xda, 0x4a, 0xa6, 0xdf, 0xc1, 0xcf, 0x77, 0x2d, 0x45,
  0xd7, 0x4e, 0x55, 0xa6, 0xd7, 0xe8, 0x64, 0x20, 0x72, 0x16, 0x46, 0xa6, 0xe5, 0x44, 0x2a, 0x53,
  0xa4, 0x96, 0xa2, 0x6b, 0xa7, 0x2a, 0xd3, 0x8f, 0x65, 0x7a, 0xf8, 0x3e, 0x98, 0x36, 0x32, 0x4d,
  0xee, 0xf7, 0xc1, 0xd4, 0x87, 0x29, 0x48, 0xcb, 0x26, 0x8c, 0xa9, 0x5b, 0x8a, 0xae, 0x9d, 0xaa,
  0x4c, 0xaf, 0xd1, 0xe9, 0xc4, 0x94, 0x2e, 0x7a, 0x0e, 0xd3, 0x53, 0x78, 0x4e, 0x2d, 0xba, 0x02,
  0x53, 0x57, 0x05, 0x53, 0x7f, 0x05, 0x53, 0x7f, 0xf5, 0x65, 0x9a, 0x44, 0x55, 0x30, 0xe5, 0x19,
  0x9f, 0xce, 0x54, 0x44, 0xd1, 0x45, 0xc7, 0x89, 0x52, 0xe6, 0x60, 0x7a, 0x0c, 0xe3, 0x6b, 0x82,
  0xa9, 0x31, 0x24, 0x0b, 0xbb, 0x34, 0xd3, 0x73, 0x69, 0xd3, 0x1c, 0x1a, 0x1d, 0x6f, 0xa6, 0xff,
  0x05, 0x1e, 0xbe, 0xcd, 0x13, 0x7c, 0x8f, 0x8a, 0x89, 0x5b, 0x8a, 0xae, 0x9d, 0xaa, 0x4c, 0xaf,
  0xd1, 0xf1, 0x63, 0xca, 0xdf, 0x4b, 0xa1, 0xa3, 0x3c, 0x2a, 0x98, 0x1a, 0x98, 0xb2, 0x04, 0x66,
  0xa4, 0xc1, 0x94, 0xc3, 0xc2, 0xc7, 0x86, 0xb4, 0x2d, 0x45, 0xd7, 0x4e, 0x55, 0xa6, 0xd7, 0xe8,
  0x78, 0x32, 0x4d, 0x68, 0x69, 0x09, 0x8c, 0x48, 0x83, 0x69, 0x82, 0xcb, 0x61, 0xdb, 0x2d, 0x9e,
  0xa5, 0x7a, 0x68, 0x05, 0xa6, 0xab, 0x29, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b,
  0x98, 0xfa, 0xab, 0x13, 0xd3, 0x73, 0x69, 0xd3, 0x1c, 0xcb, 0xaa, 0xa5, 0xe8, 0xda, 0xa9, 0xca,
  0xf4, 0xcb, 0xaa, 0xa5, 0xe8, 0xda, 0xa9, 0xca, 0xf4, 0xcb, 0xaa, 0xa5, 0xe8, 0xda, 0xa9, 0xca,
  0xf4, 0xcb, 0xaa, 0xa5, 0xe8, 0xda, 0xa9, 0xca, 0xf4, 0xcb, 0xaa, 0xa5, 0xe8, 0xda, 0xa9, 0xca,
  0xf4, 0xcb, 0xaa, 0xa5, 0xe8, 0xda, 0xa9, 0xca, 0xf4, 0x8f, 0x54, 0xf0, 0xf0, 0x57, 0x30, 0xf5,
  0x57, 0x30, 0xf5, 0x57, 0x30, 0xf5, 0x57, 0x30, 0xb5, 0xca, 0x4e, 0xaa, 0x9a, 0x29, 0x5c, 0xf0,
  0x84, 0x4f, 0x21, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98,
  0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98, 0xfa, 0x2b, 0x98, 0x76, 0x90, 0xbd, 0x6e,
  0x17, 0xa6, 0x3d, 0x4a, 0xb8, 0x9e, 0xec, 0x85, 0x3b, 0x30, 0xed, 0xe0, 0xff, 0x9a, 0x32, 0x57,
  0xde, 0xca, 0xd4, 0xdf, 0xfa, 0x75, 0x65, 0xaf, 0xbd, 0x89, 0xa9, 0xb7, 0xed, 0x6b, 0xcb, 0x5e,
  0x7c, 0x03, 0x53, 0x67, 0xcf, 0x97, 0xd7, 0x59, 0x52, 0xf6, 0xc8, 0xc7, 0x21, 0xdd, 0x52, 0x02,
  0xe6, 0x40, 0x3b, 0x53, 0x57, 0xaf, 0xcb, 0xc8, 0x0e, 0xe0, 0x04, 0x53, 0x47, 0x9f, 0x4b, 0xc9,
  0x19, 0x6a, 0x20, 0xfd, 0x27, 0x3b, 0x05, 0x43, 0x60, 0x10, 0xfd, 0x55, 0x09, 0xc4, 0x1b, 0x04,
  0x16, 0x7f, 0x92, 0xed, 0x63, 0x75, 0x1d, 0xe9, 0x28, 0x8e, 0xa3, 0x6a, 0x64, 0x9c, 0xf7, 0x47,
  0x29, 0x30, 0xc4, 0x68, 0x31, 0x32, 0x90, 0x7e, 0x44, 0x79, 0x64, 0x83, 0x14, 0x5c, 0x10, 0x95,
  0x22, 0x50, 0xc1, 0x60, 0x31, 0x32, 0x90, 0xfe, 0x09, 0x41, 0x31, 0xe3, 0x8b, 0xf3, 0x1e, 0x2b,
  0xc3, 0x52, 0xbc, 0x20, 0x94, 0x23, 0x1f, 0x2f, 0x41, 0x46, 0x01, 0x25, 0x66, 0x82, 0x28, 0x57,
  0x42, 0x51, 0x05, 0x65, 0x8f, 0x0c, 0xbd, 0x91, 0x1a, 0x23, 0x1f, 0x2f, 0x3b, 0xa8, 0x40, 0x6a,
  0x96, 0x9d, 0x53, 0x10, 0x35, 0xcb, 0x0e, 0x2a, 0x90, 0xda, 0x65, 0x06, 0x15, 0x48, 0xed, 0xb2,
  0x83, 0x0a, 0xa4, 0x66, 0xd9, 0x39, 0x05, 0x51, 0xb3, 0xec, 0xa0, 0x02, 0xa9, 0x59, 0x76, 0x50,
  0x81, 0x34, 0xf4, 0x60, 0xed, 0xfb, 0x6c, 0x07, 0xff, 0xe9, 0xef, 0x1f, 0x05, 0x4b, 0xfe, 0xd1,
  0xb9, 0xef, 0xbf, 0x92, 0x9a, 0x7c, 0x4d, 0xfe, 0x05, 0x31, 0x7e, 0xf0, 0x73, 0x6c, 0x09, 0xb3,
  0x18, 0xcb, 0xfe, 0xd5, 0xbc, 0xcc, 0xf2, 0x67, 0xc9, 0x7e, 0x0d, 0xa6, 0x47, 0x8c, 0x90, 0xe9,
  0x2b, 0xfd, 0x92, 0x17, 0x9a, 0x1d, 0x7c, 0x06, 0xe4, 0x06, 0x20, 0xac, 0xe8, 0x4b, 0x38, 0x7b,
  0xa5, 0x33, 0x22, 0xdd, 0xbe, 0x5f, 0x02, 0xea, 0x9f, 0xcd, 0x2f, 0xc6, 0xdf, 0xe1, 0xd7, 0x61,
  0xfe, 0x18, 0xf6, 0x1d, 0xda, 0xbe, 0x5f, 0x92, 0x83, 0x4d, 0xf4, 0x18, 0x59, 0x53, 0x32, 0xf6,
  0xfd, 0x92, 0xc6, 0xa7, 0x49, 0x0e, 0x73, 0xfb, 0x7e, 0x0d, 0xa8, 0x07, 0x67, 0x8c, 0xe9, 0xeb,
  0xef, 0x10, 0xd5, 0x99, 0x7c, 0x1c, 0x47, 0x90, 0xa0, 0x74, 0xb9, 0xe6, 0x37, 0xea, 0xfb, 0x5d,
  0xe6, 0x2b, 0xff, 0xb4, 0xf3, 0x33, 0xe8, 0x33, 0xb1, 0x8f, 0x67, 0x0a, 0x77, 0x4b, 0x39, 0x1e,
  0xbf, 0x37, 0x32, 0x7d, 0x1d, 0x8b, 0x7e, 0x1d, 0xbb, 0x9a, 0x33, 0x7d, 0xd9, 0x99, 0xbe, 0x28,
  0xd3, 0x17, 0x65, 0x3a, 0x0c, 0x2a, 0xd9, 0x8f, 0x30, 0xfd, 0x16, 0xf2, 0xfa, 0xf9, 0xbf, 0xf8,
  0xfb, 0x30, 0x39, 0xfe, 0xf7, 0x6f, 0x5a, 0x1c, 0x6c, 0xe2, 0x03, 0x20, 0x6b, 0x36, 0x79, 0x35,
  0x06, 0xc6, 0xfe, 0xd2, 0x27, 0x97, 0xee, 0x63, 0x12, 0xc4, 0x74, 0x38, 0xd4, 0x74, 0x43, 0xd9,
  0x9b, 0x87, 0x86, 0x04, 0x4c, 0x37, 0x59, 0xda, 0x27, 0x4e, 0x1c, 0x24, 0xc5, 0xb2, 0x35, 0xf2,
  0x3e, 0x96, 0xda, 0x4d, 0x43, 0x5f, 0xc2, 0x5b, 0x6a, 0x30, 0x2b, 0x71, 0x14, 0x54, 0xbc, 0xa1,
  0x85, 0x29, 0x2f, 0x8d, 0x73, 0xdd, 0x0e, 0x5f, 0xe8, 0x9a, 0xfc, 0xee, 0x7d, 0xfc, 0x4e, 0x5c,
  0x83, 0x7f, 0x73, 0x65, 0x33, 0xc7, 0xf9, 0x79, 0x8d, 0x7a, 0xdc, 0x11, 0x9f, 0xfb, 0xa4, 0x13,
  0x93, 0x5b, 0x79, 0x72, 0xf2, 0x89, 0x83, 0x57, 0x42, 0x89, 0xac, 0x41, 0x7d, 0x9a, 0x30, 0xcd,
  0x99, 0xe5, 0x7b, 0x89, 0xf9, 0xfe, 0x50, 0xd3, 0x0d, 0x76, 0x04, 0x95, 0x31, 0x4d, 0xcf, 0xb4,
  0x2d, 0x69, 0xc0, 0x2f, 0x39, 0x7e, 0x90, 0xf4, 0x1b, 0x0e, 0x2b, 0x5d, 0x4f, 0xd3, 0x76, 0x67,
  0x49, 0x08, 0xd3, 0x5e, 0x50, 0xe5, 0x06, 0x1a, 0xd4, 0xa4, 0x7c, 0x2b, 0x53, 0x72, 0x90, 0x64,
  0xd6, 0xd6, 0x7c, 0x5a, 0xee, 0x05, 0xef, 0xfb, 0xa6, 0x8d, 0x05, 0xd3, 0xce, 0x8d, 0xba, 0x27,
  0x92, 0xa3, 0xc2, 0x7b, 0xde, 0x52, 0xb2, 0x9c, 0xec, 0x3c, 0x4e, 0x2f, 0x9b, 0xa0, 0xa9, 0xfe,
  0x5a, 0x90, 0xac, 0xd1, 0x99, 0x8a, 0x50, 0xba, 0xb1, 0x5c, 0xd6, 0x15, 0xea, 0xae, 0x42, 0x3d,
  0x7a, 0x97, 0x2d, 0x49, 0x99, 0x7e, 0xcf, 0xea, 0x4d, 0x3d, 0x48, 0xb2, 0x94, 0xc2, 0x98, 0xac,
  0x7b, 0x31, 0xa6, 0x1d, 0xa0, 0xee, 0x52, 0x62, 0x42, 0x98, 0x4f, 0xdc, 0x51, 0xa6, 0x5b, 0x4a,
  0x24, 0xa1, 0x93, 0xa1, 0x3a, 0xde, 0x7f, 0xc8, 0x1a, 0x5d, 0xd9, 0x32, 0x98, 0x44, 0x66, 0xeb,
  0x08, 0x35, 0x63, 0x2a, 0xa0, 0xba, 0x6f, 0x78, 0x19, 0x75, 0x63, 0x7a, 0x44, 0x59, 0x6a, 0xd4,
  0xbb, 0xa9, 0x17, 0xd4, 0x24, 0x6d, 0xba, 0xc5, 0x73, 0x98, 0x3a, 0xd7, 0xa8, 0x9c, 0xef, 0x37,
  0x66, 0xca, 0x2e, 0x77, 0xae, 0xd9, 0xc5, 0xf1, 0x71, 0x5f, 0xdf, 0xfd, 0x2e, 0x21, 0x7e, 0x0f,
  0xf1, 0x4c, 0x2f, 0x07, 0x26, 0xbc, 0xbb, 0x19, 0xa7, 0x1c, 0xe9, 0x18, 0xa8, 0x37, 0x66, 0x8a,
  0x90, 0xfa, 0x96, 0x99, 0xe7, 0x7c, 0x24, 0xd2, 0x2e, 0x8d, 0x2a, 0xee, 0xf6, 0xb7, 0x65, 0x9a,
  0xd6, 0xd5, 0x1b, 0xea, 0xde, 0xfd, 0xe2, 0x7d, 0x05, 0xc9, 0xba, 0x7a, 0x43, 0x7d, 0x20, 0xd2,
  0xfe, 0x4f, 0xfe, 0x77, 0x27, 0x0a, 0x1f, 0xba, 0xfb, 0x95, 0xfb, 0x08, 0xa2, 0x3a, 0xd3, 0x8e,
  0x3f, 0xf8, 0x93, 0x5d, 0xbd, 0x37, 0x9c, 0x23, 0x44, 0xaf, 0x17, 0xd4, 0x02, 0xd0, 0xdb, 0xb4,
  0x2e, 0x2c, 0x64, 0x00, 0x53, 0x36, 0x7e, 0x07, 0xaa, 0x3a, 0xd3, 0x5e, 0x50, 0xf1, 0x66, 0x77,
  0x81, 0x5a, 0x60, 0xda, 0x05, 0x2a, 0xdb, 0xeb, 0x2e, 0x50, 0x71, 0x15, 0x5d, 0x99, 0x92, 0x9d,
  0xee, 0x07, 0x15, 0x0e, 0xfa, 0x17, 0x67, 0x44, 0xba, 0x38, 0x54, 0x58, 0x44, 0xbf, 0xd2, 0x14,
  0xa4, 0x8a, 0x9f, 0xc5, 0x04, 0xf1, 0x0d, 0x2a, 0x0c, 0x36, 0xe6, 0x9a, 0x50, 0x53, 0xd3, 0xa0,
  0x86, 0xf1, 0x48, 0xb9, 0xbd, 0x25, 0x24, 0x2b, 0x01, 0x75, 0xfd, 0x1c, 0x76, 0xaf, 0x8a, 0x5d,
  0x3d, 0x57, 0x63, 0xba, 0xa7, 0x4a, 0x86, 0xd2, 0x98, 0x81, 0x56, 0xf0, 0x44, 0x77, 0x03, 0x4e,
  0xda, 0xa5, 0x36, 0xd6, 0xb8, 0x03, 0xbd, 0x90, 0x89, 0xfe, 0x0e, 0x4e, 0x89, 0x74, 0x00, 0x87,
  0x4a, 0x7b, 0xa7, 0x87, 0x39, 0xb6, 0xd3, 0x52, 0x4c, 0x19, 0xbb, 0xa9, 0x4c, 0xd9, 0xf8, 0x45,
  0x99, 0xee, 0xf8, 0x09, 0x29, 0xed, 0xcd, 0x8d, 0xb5, 0xef, 0x00, 0x77, 0xeb, 0x31, 0x95, 0xc6,
  0x52, 0xaf, 0x3a, 0xd4, 0x41, 0xf6, 0xe0, 0x4e, 0x17, 0x46, 0x2a, 0x99, 0xca, 0x1a, 0x12, 0x7c,
  0xe3, 0x91, 0x6a, 0x97, 0xcd, 0xcb, 0x32, 0x95, 0x8e, 0x65, 0x09, 0x29, 0xc0, 0xe1, 0x48, 0xd5,
  0x5b, 0x51, 0xea, 0x73, 0x88, 0x1d, 0x8b, 0x48, 0x5b, 0x66, 0x01, 0xf9, 0xaf, 0xa1, 0x67, 0x39,
  0x4c, 0xe6, 0x84, 0xa7, 0x6b, 0x80, 0x2d, 0x31, 0x05, 0x5e, 0x07, 0x7b, 0x97, 0x27, 0x0a, 0x9d,
  0xbf, 0x0a, 0xd5, 0x83, 0x91, 0xe4, 0x81, 0x49, 0x4c, 0x4f, 0x35, 0xaa, 0x43, 0x93, 0xb3, 0x17,
  0xa0, 0xfa, 0xb1, 0xf1, 0xf1, 0x02, 0x4f, 0xf4, 0x99, 0x06, 0x37, 0x15, 0x2a, 0x20, 0x7a, 0x31,
  0xbf, 0x5b, 0xca, 0x54, 0x58, 0x9c, 0x66, 0x95, 0x23, 0xc3, 0x48, 0x67, 0x43, 0xe5, 0x4c, 0x85,
  0xc1, 0xa9, 0x4e, 0x09, 0x32, 0x86, 0x74, 0x32, 0x54, 0xca, 0x34, 0x23, 0x3a, 0xd5, 0x28, 0x44,
  0xa6, 0x0c, 0xcd, 0x73, 0x0a, 0x6c, 0xc1, 0x0f, 0xfc, 0x02, 0x46, 0xd1, 0x03, 0x13, 0xea, 0xcb,
  0xe9, 0x50, 0x4b, 0x9f, 0xbd, 0x30, 0x3f, 0xcd, 0xe7, 0xd1, 0x86, 0x38, 0xcc, 0x9c, 0xd5, 0x7a,
  0xf5, 0x2e, 0x4c, 0xff, 0xec, 0xb3, 0xeb, 0x96, 0xe7, 0xd6, 0x0e, 0x42, 0x44, 0xab, 0xbd, 0xe2,
  0x24, 0x1e, 0xae, 0x72, 0x7e, 0xe8, 0x84, 0xf2, 0xda, 0xd6, 0x47, 0x84, 0x46, 0x25, 0x23, 0x6f,
  0xa4, 0x10, 0x20, 0x3f, 0x9f, 0xfc, 0xb6, 0x75, 0x91, 0x9d, 0xa9, 0xe2, 0xdd, 0xa5, 0x4d, 0xd3,
  0x1c, 0xa0, 0x51, 0xc1, 0x2e, 0x2b, 0xb5, 0x69, 0xf6, 0x50, 0x8d, 0xce, 0x3b, 0x1a, 0xdd, 0xe2,
  0xe3, 0x93, 0x26, 0x7f, 0x68, 0x42, 0x66, 0x2f, 0xcd, 0x94, 0x4c, 0xa4, 0x41, 0x85, 0xe0, 0xf3,
  0xb5, 0x91, 0x0d, 0x28, 0x53, 0xfc, 0xd3, 0xd4, 0x55, 0x54, 0x68, 0xbe, 0x24, 0x86, 0x42, 0xe5,
  0xb0, 0xeb, 0x4c, 0xd4, 0x40, 0xd5, 0x3e, 0xe2, 0xc9, 0x52, 0x6d, 0xb1, 0xdf, 0xf5, 0x34, 0xde,
  0xd0, 0x88, 0x07, 0x03, 0x53, 0x8b, 0x99, 0xf9, 0x2a, 0xda, 0xc2, 0xad, 0xb1, 0xc3, 0x90, 0xfa,
  0xad, 0xd9, 0x0e, 0x22, 0xb3, 0x6a, 0xa7, 0x6e, 0xd7, 0x01, 0x2a, 0xf9, 0x92, 0xe6, 0x51, 0x25,
  0xa7, 0x8a, 0xfb, 0x5b, 0xa3, 0xa5, 0x57, 0x36, 0xbb, 0x2c, 0xd1, 0x1a, 0xa6, 0x7c, 0x45, 0x55,
  0x79, 0x29, 0x3c, 0xfa, 0x80, 0xc1, 0x53, 0x5f, 0x1e, 0x29, 0xb8, 0x62, 0xc1, 0x69, 0xed, 0x55,
  0x00, 0x2a, 0x0f, 0x57, 0xfc, 0x1d, 0xfd, 0xae, 0xc1, 0x9f, 0x98, 0xc2, 0x14, 0x9a, 0xba, 0x96,
  0x52, 0x7b, 0x84, 0x8d, 0xfa, 0x2a, 0x80, 0x42, 0xe6, 0xa4, 0x0f, 0xb3, 0x64, 0x31, 0xcb, 0x7d,
  0x18, 0x3f, 0x5d, 0x72, 0x77, 0xed, 0xb9, 0xc0, 0x24, 0x58, 0xc1, 0x62, 0xca, 0xe9, 0x00, 0xd2,
  0x5a, 0xa6, 0x17, 0x17, 0x80, 0x0a, 0x9e, 0x07, 0xf3, 0x05, 0x32, 0x86, 0xa7, 0xcb, 0x56, 0x4a,
  0xa6, 0xc0, 0x0c, 0xc9, 0xbe, 0x8a, 0x38, 0x54, 0x15, 0xb4, 0x5c, 0xcd, 0x93, 0x91, 0x47, 0xf6,
  0xff, 0xae, 0xdd, 0xf8, 0x4a, 0x43, 0x98, 0x2e, 0x44, 0xd6, 0xc8, 0xf4, 0xaf, 0x32, 0xc8, 0x94,
  0xa6, 0x22, 0x4c, 0x0b, 0x36, 0xe4, 0xe0, 0xa6, 0xbe, 0xc3, 0xb9, 0xa2, 0x0c, 0x0c, 0xbe, 0x73,
  0x0a, 0x53, 0xf6, 0x99, 0x64, 0xf9, 0x4a, 0x0e, 0xc8, 0xa5, 0xa4, 0x53, 0xf9, 0x9d, 0x04, 0x8d,
  0x7f, 0x06, 0x10, 0x5b, 0xf4, 0x54, 0x4e, 0x3f, 0x94, 0x6c, 0x13, 0xbe, 0x3b, 0x4b, 0xb1, 0x20,
  0xd3, 0x2d, 0xbb, 0x5d, 0xa4, 0x44, 0xaa, 0x98, 0x66, 0x29, 0x44, 0x42, 0x05, 0x69, 0xe1, 0xb5,
  0x89, 0x73, 0xc9, 0xe3, 0x45, 0xbb, 0x2c, 0x47, 0xca, 0x7e, 0x6e, 0x85, 0xc8, 0xc9, 0x1b, 0x98,
  0x5d, 0xfc, 0x34, 0xc0, 0x77, 0x5d, 0x58, 0x59, 0x21, 0x9c, 0x29, 0x8e, 0xdf, 0xd2, 0x46, 0xc5,
  0x64, 0x44, 0x4a, 0xc3, 0xa6, 0x4b, 0x8b, 0x33, 0x82, 0x37, 0xa1, 0x36, 0xa6, 0xf8, 0x70, 0xcb,
  0xa0, 0x2f, 0x2e, 0x5c, 0x4a, 0x4d, 0x9b, 0x42, 0xa6, 0x28, 0x40, 0x7b, 0xc8, 0xbf, 0x11, 0x51,
  0xa5, 0x18, 0xfd, 0x41, 0x0a, 0x28, 0x8f, 0x66, 0x7b, 0xdc, 0xa9, 0x27, 0xa1, 0xb2, 0x82, 0xe1,
  0x74, 0x17, 0xa6, 0xb7, 0x85, 0x2a, 0xea, 0x93, 0xa5, 0xa6, 0xd3, 0x2e, 0x4c, 0xc5, 0x92, 0x3b,
  0x8a, 0xf2, 0x49, 0x26, 0x79, 0x2c, 0x0c, 0x40, 0x3b, 0xe4, 0xfb, 0x0d, 0xa8, 0x6e, 0x92, 0x34,
  0xa8, 0xe2, 0xf8, 0x7b, 0x74, 0x82, 0x29, 0xb8, 0x7c, 0x8c, 0x28, 0x6f, 0x8e, 0xce, 0x30, 0xd5,
  0x53, 0x15, 0xf2, 0xdf, 0xff, 0x2e, 0xc5, 0xdf, 0x6e, 0xb0, 0xa7, 0xa0, 0x62, 0xa6, 0x52, 0xfa,
  0xdb, 0x13, 0xfd, 0x27, 0x72, 0x46, 0x96, 0x18, 0xb3, 0x3c, 0x5a, 0xf6, 0xdf, 0x4b, 0x87, 0x73,
  0x01, 0x97, 0x14, 0x20, 0x5a, 0x7c, 0x09, 0xf5, 0x33, 0x04, 0x16, 0xb0, 0xdc, 0x4f, 0x68, 0xcf,
  0x82, 0x68, 0xe3, 0xb2, 0x10, 0x86, 0x2d, 0x90, 0x7e, 0x54, 0x7f, 0x31, 0xa0, 0xdc, 0x02, 0xe9,
  0xaf, 0x10, 0x86, 0x84, 0x4d, 0x46, 0x4a, 0x03, 0x17, 0x40, 0xff, 0x49, 0x65, 0x0a, 0x2f, 0x91,
  0xd1, 0x8c, 0x25, 0x41, 0x40, 0x1a, 0xd2, 0x60, 0x6a, 0x93, 0xe1, 0x17, 0x4b, 0xf9, 0xdc, 0x50,
  0x87, 0xb7, 0x10, 0x23, 0x1a, 0x4c, 0x5b, 0x84, 0x89, 0x3e, 0xe5, 0x51, 0x3e, 0x14, 0xea, 0xa8,
  0xff, 0x01, 0xee, 0x68, 0x6f, 0xd1
  };

#endif // 1==LOGO_PNG_0_ARGB2_1
#endif // 1==LOGO_DEMO
