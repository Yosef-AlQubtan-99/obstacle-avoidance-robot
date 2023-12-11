#ifndef CLCD_PRIVATE_H

#define CLCD_PRIVATE_H
#include "../03-CLCD/Clcd_config.h"
#define CLCD_CLEAR_DISPLAY                   0x01
#define CLCD_RETURN_HOME                     0x02
#define CLCD_ENTRY_MODE_SET                  0x03
#define CLCD_CURSOR_OFF_DISPLAY_ON           0x0C
#define CLCD_CURSOR_ON_DISPLAY_OFF           0x08
#define CLCD_CURSOR_ON_BLINK_ON              0x0F //AT DISPLAY ON
#define CLCD_CURSOR_ON_BLINK_OFF             0x0E //AT DISPLAY ON
#define CLCD_8BIT_MODE_2LINE                 0X38
#define CLCD_4BIT_MODE_2LINE                 0X28
#define CLCD_DISPLAY_SHIFT_RIGHT             0x1C
#define CLCD_DISPLAY_SHIFT_LEFT              0x18
#define CLCD_DISPLAY_SHIFT_OFF               0x00
#define CLCD_SET_CGRAM                       0x64
#define CLCD_16_40                           0xC0
#define CLCD_16_2                            0x80


#endif
