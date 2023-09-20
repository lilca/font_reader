#include "header/font_ttf.h"

class FontTFF_OffsetTable
{
    const static int LENGTH = 12;
    private:

    static void* printOffsetTable(void* pos)
    {

        FontTTF::printFixed(pos);
        return pos + LENGTH;
    }
};