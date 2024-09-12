# About this Project
C++のgetline関数likeな関数を作成しています。
渡されたファイルディスクリプタから文字列を改行が現れるまで読み取り、1行の内容をリターンします。  

# Examples
<img width="884" alt="Screenshot 2024-09-12 at 12 33 46" src="https://github.com/user-attachments/assets/4ce6e46a-2b02-41b8-9f78-4c007e130894">

a.outの出力結果は、get_next_line()を利用して、ファイルの終端まで1行ごとに読み取りprintf()で出力したものです。

# 機能
- ファイルディスクリプタから一度に読み取り可能なバッファーサイズを指定し、効率的な読み取りが行えます
- 複数のファイルディスクリプタを同時に扱うことができます
- STDINもファイルディスクリプタとして利用できます
- 返された文字列はfree()で解放する必要があります

# Build
あなたのプロジェクトでヘッダーファイルをインクルードし、ソースファイルをコンパイルに含めてください。
```
#include "includes/get_next_line.h"

int main(void)
{....}
```
```
cc main.c get_next_line.c get_next_line_utils.c
```
  
挙動を簡単に試したい場合は、以下のコマンドで実行ファイルを作成できます。そして実行ファイルを実行してください。
```
make
```
main.cファイルで、ファイルディスクリプタ（参照するファイル）を変更することもできます。
その場合は、``make re``を行って再度コンパイルしてください。  

# Usage
以下のように関数を利用してください
```
    int fd;
    char* line;

    fd = open("path/to/file", O_RDONLY);
    if (fd == -1)
        return (printf("Error\n"), 1);
    while(1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s\n", line);
        free(line);
    }
```
**ポイント**は
- リターンされたchar*はfree()でメモリ解放が必要
- ファイルの終端に達した場合はNULLがリターンされる
- コンパイルのフラグに``-D BUFFER_SIZE=decimal``を加えることで、一度にread()可能なサイズを変更することができる
ということです。

# Learning
効率的なファイルディスクリプタからの読み取りや、メモリの管理、エラー処理を学びました。
- スタティック変数の機能
- defineの書き換え
- read(), write()
