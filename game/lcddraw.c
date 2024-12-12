void drawString5x7(unsigned char col, unsigned char row, const char *string, 
                   unsigned int fgColorBGR, unsigned int bgColorBGR) {
    while (*string) {
        drawChar5x7(col, row, *string++, fgColorBGR, bgColorBGR);
        col += 6; // Move to the next character position
    }
}
