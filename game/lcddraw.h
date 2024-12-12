#ifndef LCDDRAW_H
#define LCDDRAW_H

#include "lcdutils.h"

void drawPixel(unsigned char col, unsigned char row, unsigned int colorBGR);
void drawChar5x7(unsigned char col, unsigned char row, char c, 
                 unsigned int fgColorBGR, unsigned int bgColorBGR);
void drawString5x7(unsigned char col, unsigned char row, const char *string, 
                   unsigned int fgColorBGR, unsigned int bgColorBGR);
void fillRectangle(unsigned char colMin, unsigned char rowMin, 
                   unsigned char width, unsigned char height, unsigned int colorBGR);
void drawRectOutline(unsigned char colMin, unsigned char rowMin, 
                     unsigned char width, unsigned char height, unsigned int colorBGR);

#endif // LCDDRAW_H
