#ifndef FONT_TTF_H
#define FONT_TTF_H

#include <stdio.h>
#include "TTF_Types.h"

class FontTTF
{
    static void printShortFrac(unsigned char* pos);
    static void printF2Dot14(unsigned char* pos);
    static void printLongDataTime(unsigned char* pos);

    public:
    static void printField(unsigned char* pos, int ttf_type, const char* name, const char* detail);

    static void printFixed(unsigned char* pos);
    static void printU2BE(unsigned char* pos);
    static void printU4BE(unsigned char* pos);
    static void printTag(unsigned char* pos);

    static unsigned short getFixedMajor(unsigned char* pos);
    static unsigned short getFixedMinor(unsigned char* pos);
    static unsigned short getU2BE(unsigned char* pos);
    static unsigned int getU4BE(unsigned char* pos);
};

#endif