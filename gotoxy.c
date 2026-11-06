/*  AUTOR.....: Matheus Henrique Lopes da Silva
    DATA......: 31/10/2026

    GRUPO.....: Matheus Henrique RA: 439746-2026
                John Bryan RA: 437929-2026

    OBJETIVO..: Posicionar o cursor em uma coordenada especifica do console para organizar a interface do sistema
*/


#include <windows.h>

void gotoxy(int x, int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), pos
    );
}
