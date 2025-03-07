#include <FontTTF.h>


    unsigned short FontTTF::getFixedMajor(unsigned char* pos)
    {
        return (unsigned short)pos[0] * 0x100 + (unsigned short)pos[1];
    }
    unsigned short FontTTF::getFixedMinor(unsigned char* pos)
    {
        return (unsigned short)pos[2] * 0x100 + (unsigned short)pos[3];
    }
    unsigned short FontTTF::getU2BE(unsigned char* pos)
    {
        return (unsigned short)pos[0] * 0x100 + (unsigned short)pos[1];
    }
    unsigned int FontTTF::getU4BE(unsigned char* pos)
    {
        return (unsigned int)pos[0] * 0x1000000 + (unsigned int)pos[1] * 0x10000 + (unsigned int)pos[2] * 0x100 + (unsigned int)pos[3];
    }


