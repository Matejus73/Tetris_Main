#include <iostream>
#include <conio.h>
#include <windows.h>
#include <algorithm>
//Ahoj kamoš!!
using namespace std;



bool gameIsRunning = true;

int inputValue = 0;
int tenFrame = 10;

int randomBag[7] = {1, 2, 3, 4, 5, 6, 7};
int bagNum = 0;

int row = 0, column = 4;
int tetrominoType;
int tetrominoBlock1[2], tetrominoBlock2[2], tetrominoBlock3[2], tetrominoBlock4[2];

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
        case 9:
            SetColor(14, 0);
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
            else if (pole[j][i] == 9) {
                block(9);
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
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = -1;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 0;
            tetrominoBlock4[1] = 2;

            break;
        case 11:
            tetrominoBlock1[0] = -2;
            tetrominoBlock1[1] = 1;
            tetrominoBlock2[0] = -1;
            tetrominoBlock2[1] = 1;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 2:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = -1;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = -1;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 12:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = 1;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 2;
            tetrominoBlock4[1] = 0;

            break;
        case 22:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = -1;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 32:
            tetrominoBlock1[0] = -1;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = -1;

            break;
        case 3:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 1;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = -1;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 13:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 2;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 2;
            tetrominoBlock4[1] = 1;

            break;
        case 23:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = -1;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = -1;
            tetrominoBlock4[0] = 0;
            tetrominoBlock4[1] = 1;

            break;
        case 33:
            tetrominoBlock1[0] = -1;
            tetrominoBlock1[1] = -1;
            tetrominoBlock2[0] = -1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 0;

            break;
        case 4:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = -1;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = -1;

            break;
        case 5:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = 1;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = -1;

            break;
        case 15:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = -1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 6:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = -1;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 16:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = -1;
            tetrominoBlock2[1] = 1;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 0;

            break;
        case 7:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = -1;

            break;
        case 17:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 2;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = 1;

            break;
        case 27:
            tetrominoBlock1[0] = 2;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 1;
            tetrominoBlock3[1] = 1;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = -1;

            break;
        case 37:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 1;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 2;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 1;
            tetrominoBlock4[1] = -1;

            break;
    }



    pole[row + tetrominoBlock1[0]][column + tetrominoBlock1[1]] = tetrominoType%10;
    pole[row + tetrominoBlock2[0]][column + tetrominoBlock2[1]] = tetrominoType%10;
    pole[row + tetrominoBlock3[0]][column + tetrominoBlock3[1]] = tetrominoType%10;
    pole[row + tetrominoBlock4[0]][column + tetrominoBlock4[1]] = tetrominoType%10;
}

void makeSolid() {
    bagNum++;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < wight; i++) {
            metrix[j][i] = pole[j][i];
        }
    }

    if (bagNum > 6) {
        random_shuffle(begin(randomBag), end(randomBag));
        bagNum = 0;
    }
    tetrominoType = randomBag[bagNum];





    row = 0;
    column = 4;
}

void floorCheck() {

    if (pole[row + tetrominoBlock1[0]+1][column + tetrominoBlock1[1]] != 0) {
        if (pole[row + tetrominoBlock1[0]+1][column + tetrominoBlock1[1]] != tetrominoType%10) {
            makeSolid();
        }
        else if (pole[row + tetrominoBlock1[0]+1][column + tetrominoBlock1[1]] == tetrominoType%10 && pole[row + tetrominoBlock1[0]+1][column + tetrominoBlock1[1]] == metrix[row + tetrominoBlock1[0]+1][column + tetrominoBlock1[1]]) {
            makeSolid();
        }
    }
    if (pole[row + tetrominoBlock2[0]+1][column + tetrominoBlock2[1]] != 0) {
        if (pole[row + tetrominoBlock2[0]+1][column + tetrominoBlock2[1]] != tetrominoType%10) {
            makeSolid();
        }
        else if (pole[row + tetrominoBlock2[0]+1][column + tetrominoBlock2[1]] == tetrominoType%10 && pole[row + tetrominoBlock2[0]+1][column + tetrominoBlock2[1]] == metrix[row + tetrominoBlock2[0]+1][column + tetrominoBlock2[1]]) {
            makeSolid();
        }
    }
    if (pole[row + tetrominoBlock3[0]+1][column + tetrominoBlock3[1]] != 0) {
        if (pole[row + tetrominoBlock3[0]+1][column + tetrominoBlock3[1]] != tetrominoType%10) {
            makeSolid();
        }
        else if (pole[row + tetrominoBlock3[0]+1][column + tetrominoBlock3[1]] == tetrominoType%10 && pole[row + tetrominoBlock3[0]+1][column + tetrominoBlock3[1]] == metrix[row + tetrominoBlock3[0]+1][column + tetrominoBlock3[1]]) {
            makeSolid();
        }

    }
    if (pole[row + tetrominoBlock4[0]+1][column + tetrominoBlock4[1]] != 0) {
        if (pole[row + tetrominoBlock4[0]+1][column + tetrominoBlock4[1]] != tetrominoType%10) {
            makeSolid();
        }
        else if (pole[row + tetrominoBlock4[0]+1][column + tetrominoBlock4[1]] == tetrominoType%10 && pole[row + tetrominoBlock4[0]+1][column + tetrominoBlock4[1]] == metrix[row + tetrominoBlock4[0]+1][column + tetrominoBlock4[1]]) {
            makeSolid();
        }
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
            floorCheck();
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
        floorCheck();
        row++;
        update();
    }
}


int main() {
    srand(time(NULL));
    random_shuffle(begin(randomBag), end(randomBag));
    tetrominoType = randomBag[bagNum];
    SetConsoleOutputCP(CP_UTF8);
    while (true) {
        input();
        fall();
        cout<<randomBag[0]<<randomBag[1]<<randomBag[2]<<randomBag[3]<<randomBag[4]<<randomBag[5]<<randomBag[6]<<endl;
        if (tenFrame == 10) {
            tenFrame = 0;
        }

        _sleep(100);
        tenFrame++;
    }

    return 0;
}

