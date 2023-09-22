#ifndef DIRECTORY_TABLE_H
#define DIRECTORY_TABLE_H

#include "font_ttf.h"
#include "TTF_Types.h"

class DirectoryTable
{
    const static int LENGTH = 16;

    public:
    char tag[4];
    unsigned int cheksum;
    unsigned int offset;
    unsigned int length;

    void set(unsigned char* pos);
    unsigned char* seekPointer(unsigned char* pos);
    void print();
};
#endif