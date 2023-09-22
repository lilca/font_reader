
#include "header/OffsetTable.h"

    void OffsetTable::set(unsigned char* pos)
    {
        majorVersion = FontTTF::getFixedMajor(pos);
        minorVersion = FontTTF::getFixedMinor(pos);
        numberOfTables = FontTTF::getU2BE(pos+4);
        searchRange = FontTTF::getU2BE(pos+6);
        entrySelector = FontTTF::getU2BE(pos+8);
        rangeShift = FontTTF::getU2BE(pos+10);
    }

    unsigned char* OffsetTable::seekPointer(unsigned char* pos)
    {
        return pos + OffsetTable::LENGTH;
    }

    void OffsetTable::print()
    {
        printf("--- Offset Table ---\n");
        printf("|%s|%u.%u|%s|\n", "sfnt version", majorVersion, minorVersion, "sfntバージョン");
        printf("|%s|%u|%s|\n", "num tables", numberOfTables, "テーブル数");
        printf("|%s|%u|%s|\n", "search range", searchRange, "検索範囲");
        printf("|%s|%u|%s|\n", "entry selector", entrySelector, "エントリーセレクタ？");
        printf("|%s|%u|%s|\n", "range shift", rangeShift, "シフトレンジ？");
    }

