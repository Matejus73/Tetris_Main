#include <iostream>
#include <conio.h>
#include <windows.h>
//Ahoj kamoš!!
using namespace std;



bool gameIsRunning = true;

int inputValue = 0;
int tenFrame = 10;

int row = 0, column = 4;
int tetrominoType = 7;


int height = 21, wight = 10;
int pole[21][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
    };

int metrix[21][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
    };

//------------------------------PRESETS------------------------

void SetColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,
                            (bgColor << 4) | textColor);
}

void block(int renderBlockType)
{

    switch(renderBlockType) {
        case 0:
            SetColor(8, 0);
            cout << "███";
            break;
        case 1:
            SetColor(9, 0);
            cout << "███";
            break;
        case 2:
            SetColor(1, 0);
            cout << "███";
            break;
        case 3:
            SetColor(6, 0);
            cout << "███";
            break;
        case 4:
            SetColor(14, 0);
            cout << "███";
            break;
        case 5:
            SetColor(2, 0);
            cout << "███";
            break;
        case 6:
            SetColor(4, 0);
            cout << "███";
            break;
        case 7:
            SetColor(5, 0);
            cout << "███";
            break;
        case 8:
            SetColor(7, 0);
            cout << "███";
            break;
    }
}

//-----------RENDERING------------------------------
int rendering() {
    system("cls");
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < wight; i++) {
            if (pole[j][i] == 1) {
                block(1);
            }
            else if (pole[j][i] == 2) {
                block(2);
            }
            else if (pole[j][i] == 3) {
                block(3);
            }
            else if (pole[j][i] == 4) {
                block(4);
            }
            else if (pole[j][i] == 5) {
                block(5);
            }
            else if (pole[j][i] == 6) {
                block(6);
            }
            else if (pole[j][i] == 7) {
                block(7);
            }
            else if (pole[j][i] == 8) {
                block(8);
            }
            else {
                block(0);
            }
        }
        cout << endl;
    }
    return 0;
}

void preframe() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < wight; i++) {
            pole[j][i] = metrix[j][i];
        }
    }
}

//Tetrominos

void tetromino(int tetrominoType) {

    switch(tetrominoType) {
        case 1:
            pole[row][column - 1] = 1;
            pole[row][column] = 1;
            pole[row][column + 1] = 1;
            pole[row][column + 2] = 1;

            break;
        case 11:
            pole[row - 2][column + 1] = 1;
            pole[row - 1][column + 1] = 1;
            pole[row][column + 1] = 1;
            pole[row + 1][column + 1] = 1;

            break;
        case 2:
            pole[row][column - 1] = 2;
            pole[row + 1][column - 1] = 2;
            pole[row + 1][column] = 2;
            pole[row + 1][column + 1] = 2;
            break;
        case 12:
            pole[row][column] = 2;
            pole[row][column + 1] = 2;
            pole[row + 1][column] = 2;
            pole[row + 2][column] = 2;
            break;
        case 22:
            pole[row][column] = 2;
            pole[row][column - 1] = 2;
            pole[row][column + 1] = 2;
            pole[row + 1][column + 1] = 2;
            break;
        case 32:
            pole[row - 1][column] = 2;
            pole[row][column] = 2;
            pole[row + 1][column] = 2;
            pole[row + 1][column - 1] = 2;
            break;
        case 3:
            pole[row][column + 1] = 3;
            pole[row + 1][column - 1] = 3;
            pole[row + 1][column] = 3;
            pole[row + 1][column + 1] = 3;
            break;
        case 13:
            pole[row][column] = 3;
            pole[row + 1][column] = 3;
            pole[row + 2][column] = 3;
            pole[row + 2][column + 1] = 3;
            break;
        case 23:
            pole[row][column - 1] = 3;
            pole[row][column] = 3;
            pole[row + 1][column - 1] = 3;
            pole[row][column + 1] = 3;
            break;
        case 33:
            pole[row - 1][column - 1] = 3;
            pole[row - 1][column] = 3;
            pole[row][column] = 3;
            pole[row + 1][column] = 3;
            break;
        case 4:
            pole[row][column] = 4;
            pole[row][column - 1] = 4;
            pole[row + 1][column] = 4;
            pole[row + 1][column - 1] = 4;
            break;
        case 5:
            pole[row][column] = 5;
            pole[row][column + 1] = 5;
            pole[row + 1][column] = 5;
            pole[row + 1][column - 1] = 5;
            break;
        case 15:
            pole[row][column] = 5;
            pole[row - 1][column] = 5;
            pole[row][column + 1] = 5;
            pole[row + 1][column + 1] = 5;
            break;
        case 6:
            pole[row][column] = 6;
            pole[row][column - 1] = 6;
            pole[row + 1][column] = 6;
            pole[row + 1][column + 1] = 6;
            break;
        case 16:
            pole[row][column] = 6;
            pole[row - 1][column + 1] = 6;
            pole[row][column + 1] = 6;
            pole[row + 1][column] = 6;
            break;
        case 7:
            pole[row][column] = 7;
            pole[row + 1][column] = 7;
            pole[row + 1][column + 1] = 7;
            pole[row + 1][column - 1] = 7;
            break;
        case 17:
            pole[row][column] = 7;
            pole[row + 1][column] = 7;
            pole[row + 2][column] = 7;
            pole[row + 1][column + 1] = 7;
            break;
        case 27:
            pole[row + 2][column] = 7;
            pole[row + 1][column] = 7;
            pole[row + 1][column + 1] = 7;
            pole[row + 1][column - 1] = 7;
            break;
        case 37:
            pole[row][column] = 7;
            pole[row + 1][column] = 7;
            pole[row + 2][column] = 7;
            pole[row + 1][column - 1] = 7;
            break;
    }
}

void makeSolid() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < wight; i++) {
            metrix[j][i] = pole[j][i];
        }
    }

    int x = rand() % 7 + 1;

    if (x == tetrominoType) {
        tetrominoType = x + 1;
    }
    else {
        tetrominoType = x;
    }


    row = 0;
    column = 4;
}

void floorCheck(int tetrominoType) {

    switch (tetrominoType) {
        case 1:
            if (pole[row + 1][column - 2] || pole[row + 1][column - 1] ||
                pole[row + 1][column] || pole[row + 1][column + 1] != 0) {
                makeSolid();
            }
            break;
        case 2:
            if (pole[row + 2][column - 1] ||
                pole[row + 2][column] || pole[row + 2][column + 1] != 0) {
                makeSolid();
                }
            break;
        case 3:
            if (pole[row + 2][column - 1] ||
                pole[row + 2][column] || pole[row + 2][column + 1] != 0) {
                makeSolid();
                }
            break;
        case 4:
            if (pole[row + 2][column - 1] ||
                pole[row + 2][column] != 0) {
                makeSolid();
                }
            break;
        case 5:
            if (pole[row + 2][column - 1] || pole[row + 2][column] || pole[row + 1][column + 1] != 0) {
                makeSolid();
                }
            break;
        case 6:
            if (pole[row + 1][column - 1] || pole[row + 2][column] || pole[row + 2][column + 1] != 0) {
                makeSolid();
            }
            break;
        case 7:
            if (pole[row + 2][column - 1] ||
                pole[row + 2][column] || pole[row + 2][column + 1] != 0) {
                makeSolid();
                }
            break;
    }

}

void renderBlockType() {
    tetromino(tetrominoType);
}

//Tetrominos

//-------GAMEPLAY------------------

int update() {
    preframe();
    renderBlockType();
    rendering();
    return 0;
}

int rotate() {

    if (tetrominoType % 10 == 1 || tetrominoType % 10 == 5|| tetrominoType % 10 == 6) {
            tetrominoType = tetrominoType + 10;

        if (tetrominoType > 16) {
            tetrominoType = tetrominoType - 20;
        }
    }
    else if (tetrominoType % 10 == 2 || tetrominoType % 10 == 3|| tetrominoType % 10 == 7) {
            tetrominoType = tetrominoType + 10;

        if (tetrominoType > 37) {
            tetrominoType = tetrominoType - 40;
        }
    }
    return 0;
}

int run(int inputValue) {

    switch(inputValue) {
        case 1:
            column++;
            update();

            break;
        case 2:
            column--;
            update();
            break;
        case -1:
            floorCheck(tetrominoType);
            row++;
            update();
            break;
        case 3:
            rotate();
            update();
            break;
    }
    return 0;
}

int input() {
    if (GetAsyncKeyState('S') & 0x8000) {
        inputValue = -1;
        run(inputValue);
    }
    else if (GetAsyncKeyState('D') & 0x8000 && !(GetAsyncKeyState('A') & 0x8000)) {
        inputValue = 1;
        run(inputValue);
    }
    else if (GetAsyncKeyState('A') & 0x8000 && !(GetAsyncKeyState('D') & 0x8000)) {
        inputValue = 2;
        run(inputValue);
    }
    else if (GetAsyncKeyState(0x20) & 0x8000) {
        inputValue = 3;
        run(inputValue);
    }
    else {
        return 0;
    }


    return inputValue;
}

void fall() {
    if (tenFrame == 10) {
        floorCheck(tetrominoType);
        row++;
        update();
    }
}


int main() {
    srand(time(NULL));
    //tetrominoType = rand() % 7 + 1;

    SetConsoleOutputCP(CP_UTF8);
    while (true) {
        input();
        fall();
        cout<<tetrominoType;
        if (tenFrame == 10) {
            tenFrame = 0;
        }

        _sleep(100);
        tenFrame++;
    }

    return 0;
}

