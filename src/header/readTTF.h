#ifndef READ_TTF_H
#define READ_TTF_H

#include <stdio.h>

#include "font_ttf.h"
#include "OffsetTable.h"
#include "DirectoryTable.h"

void printHex(unsigned char* pos, int len);
void printChar(unsigned char* pos, int len);
int processing();
FILE* openFile(const char* filename);

int fileSize;
unsigned char* fileBuffer;

OffsetTable offsetTable;
DirectoryTable directoryTable;
DirectoryTable* dTables;

#endif