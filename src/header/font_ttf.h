#include <stdio.h>

class FontTTF
{
    static void printShortFrac(void* pos);
    static void printFWord(void* pos);
    static void printUFWord(void* pos);
    static void printF2Dot14(void* pos);
    static void printLongDataTime(void* pos);

    public:
    static void printFixed(void* pos, char* name, char* detail)
    {
        printf("| %s | ", name);
        unsigned char* ptr = (unsigned char*)pos;
        unsigned int high = ptr[0] * 256 + ptr[1];
        unsigned int low = ptr[2] * 256 + ptr[3];
        double tmp = (double)high + (double)low / 65536;
        printf("%f", tmp);
        printf(" | %s |", detail);
    }
};