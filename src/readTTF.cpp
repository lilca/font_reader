/**************************************************/
/* Title: readTTF                                 */
/* Author: lilca reload(Masayuki Ise)             */
/* Detail: Display contents of ttf file.          */
/**************************************************/
#include <stdio.h>
#include <stdlib.h>

#include <readTTF.h>

// readTTFのメイン関数
int main (int argc, char** argv)
{
    FILE* fp;

    // パラメータチェック
    // readTTF <Path of TTF File>
    // デバッグ用printf("%d,%s[%s]\n", argc, argv[0], argv[1]);
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

    // ファイル内容をバッファに保存
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

// 
int processing()
{
//    int pos = 0;
    // オフセットテーブルの情報を取得＆出力＆シーク
    unsigned char* pos = fileBuffer;
    offsetTable.set(pos);
    offsetTable.print();
    pos = offsetTable.seekPointer(pos);

    for(int idx=0; idx<offsetTable.numberOfTables; idx++)
    {
        // チャンクの情報を取得＆出力＆次チャンク位置を設定
        directoryTable.set(pos);
        directoryTable.print();
        pos = directoryTable.seekPointer(pos);
    }
    // 最後の16バイト HEXテキスト出力
    printHex(pos, 16);
    // 最後の16バイト テキスト出力
    printChar(pos, 16);
    return 0;
}

// ファイルを開く関数
FILE* openFile(const char* filename) 
{
    return fopen(filename, "r");
}

// 指定バイト HEXテキスト出力
void printHex(unsigned char* pos, int len)
{
    for (int idx=0; idx<len; idx++) 
    {
        printf("%02x ", pos[idx]);
    }
    printf("\n");
}

// 指定バイト テキスト出力
void printChar(unsigned char* pos, int len)
{
    for (int idx=0; idx<len; idx++)
    {
        // 制御文字は '.' に変換
        char tmp = pos[idx] >= '!' && pos[idx] <= '}' ? pos[idx] : '.';
        printf("%c ", tmp);
    }
    printf("\n");
}