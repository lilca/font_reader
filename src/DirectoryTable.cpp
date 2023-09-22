
#include "header/DirectoryTable.h"

    void DirectoryTable::set(unsigned char* pos)
    {
        tag[0] = pos[0];
        tag[1] = pos[1];
        tag[2] = pos[2];
        tag[3] = pos[3];
        cheksum = FontTTF::getU4BE(pos+4);
        offset = FontTTF::getU4BE(pos+8);
        length = FontTTF::getU4BE(pos+12);
    }

    unsigned char* DirectoryTable::seekPointer(unsigned char* pos)
    {
        return pos + DirectoryTable::LENGTH;
    }

    void DirectoryTable::print()
    {
        printf("--- Directory Table ---\n");
        printf("|%s|%c%c%c%c|%s|\n", "tag", tag[0], tag[1], tag[2], tag[3], "タグ");
        printf("|%s|%08X|%s|\n", "check sum", cheksum, "チェックサム");
        printf("|%s|%u|%s|\n", "offset", offset, "オフセット");
        printf("|%s|%u|%s|\n", "length", length, "長さ");
    }
