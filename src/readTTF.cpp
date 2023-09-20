#include <stdio.h>
#include <stdlib.h>

int processing();
FILE* openFile(const char* filename);
void printHex(unsigned char* pos, int len);
void printChar(unsigned char* pos, int len);

    int fileSize;
    unsigned char* fileBuffer;

int main (int argc, char** argv)
{
    FILE* fp;

    // パラメータチェック
    printf("%d,%s[%s]\n", argc, argv[0], argv[1]);
    if (argc < 2)
    {
        printf("Few parameters(%d)\n", argc);
        return -1;
    }

    // ファイルを開く
    fp = openFile(argv[1]);
    if (fp == NULL)
    {
        printf("Can't open file(%s)\n", argv[1]);
        return -1;
    }

    // ファイルサイズ取得
    fileSize = 0;
    while(fgetc(fp) != EOF)
    {
        fileSize++;
    }
    rewind(fp);
    printf("FileSize : %d\n", fileSize);

    // メモリ確保
    fileBuffer = (unsigned char*)malloc(fileSize);

    // ファイル内容保存
    fread(fileBuffer, fileSize, 1, fp);

    // 各種処理
    if (processing() != 0)
    {
        printf("Process error\n");
        free(fileBuffer);
        return -1;
    }

    // ファイルを閉じる
    int ret = fclose(fp);
    if (ret == EOF)
    {
        printf("Close error\n");
        free(fileBuffer);
        return -1;
    }

    // メモリ解放
    free(fileBuffer);

    // 正常終了
    return 0;
}

int processing()
{
//    int pos = 0;
    printHex(fileBuffer, 28);
    printChar(fileBuffer, 28);
    return 0;
}

FILE* openFile(const char* filename) 
{
    return fopen(filename, "r");
}

void printHex(unsigned char* pos, int len)
{
    for (int idx=0; idx<len; idx++) 
    {
        printf("%02x ", pos[idx]);
    }
    printf("\n");
}

void printChar(unsigned char* pos, int len)
{
    for (int idx=0; idx<len; idx++)
    {
        char tmp = pos[idx] >= '!' && pos[idx] <= '}' ? pos[idx] : '.';
        printf("%c ", tmp);
    }
    printf("\n");
}