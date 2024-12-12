#include "lcdutils.h"
#include "lcddraw.h"

void drawPixel(u_char col, u_char row, u_int color) {
    lcd_setArea(col, row, col, row);
    lcd_writeColor(color);
}

void drawChar5x7(u_char col, u_char row, char c, u_int fgColor, u_int bgColor) {
    u_char i, j;
    u_char bitmask;
    const u_char *charData = font_5x7[c - ' '];
    for (i = 0; i < 5; i++) {
        bitmask = 0x01;
        for (j = 0; j < 7; j++) {
            u_int color = (charData[i] & bitmask) ? fgColor : bgColor;
            drawPixel(col + i, row + j, color);
            bitmask <<= 1;
        }
    }
}

void clearScreen(u_int color) {
    lcd_setArea(0, 0, screenWidth - 1, screenHeight - 1);
    for (u_int i = 0; i < screenWidth * screenHeight; i++) {
        lcd_writeColor(color);
    }
}
