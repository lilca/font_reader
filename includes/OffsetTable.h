#ifndef OFFSET_TABLE_H
#define OFFSET_TABLE_H

#include <FontTTF.h>
#include <TTF_Types.h>

class OffsetTable
{
    const static int LENGTH = 12;

    public:
    unsigned short majorVersion;
    unsigned short minorVersion;
    unsigned short numberOfTables;
    unsigned short searchRange;
    unsigned short entrySelector;
    unsigned short rangeShift;

    void set(unsigned char* pos);
    unsigned char* seekPointer(unsigned char* pos);
    void print();
};

#endif