#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <ctime>
#include <random>
//Ahoj kamoš!!
using namespace std;

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

string dysplay;

bool gameOn = true;

int level = 1;
int bonus;
int score = 0;
string coutScore;

int inputValue = 0;
int tenFrame = 10;

int randomBag[7] = {1, 2, 3, 4, 5, 6, 7};
int bagNum = 0;

int row = 0, column = 5;
int tetrominoType;
int tetrominoBlock1[2], tetrominoBlock2[2], tetrominoBlock3[2], tetrominoBlock4[2];

int height = 21, width = 12;
int pole[21][12] = {
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
    };

int metrix[21][12] = {
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8}
    };

//------------------------------PRESETS------------------------



void SetColor(int r, int g, int b, int br = -1, int bg = -1, int bb = -1) {
    dysplay += "\033[38;2;" + to_string(r) += ";" + to_string(g) + ";" + to_string(b) + "m";

    if (br >= 0 && bg >= 0 && bb >= 0) {
        dysplay += "\033[48;2;" + to_string(br) + ";" + to_string(bg) + ";" + to_string(bb) + "m";
    }
}

void ResetColor() {
    dysplay += "\033[0m";
}

//-----------RENDERING------------------------------
void rendering() {
    system("cls");
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (metrix[1][i] != 8 && metrix[1][i] != 0) {
                gameOn = false;
            }

            if (pole[j][i] == 0) {
                SetColor(115, 115, 115);
                dysplay += "███";
            }
            else if (pole[j][i] == 1) {
                SetColor(149, 255, 255, 21, 197, 232);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 2) {
                SetColor(115, 119, 240, 56, 58, 181);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 3) {
                SetColor(255, 167, 0, 224, 97, 0);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 4) {
                SetColor(255, 229, 1, 207, 172, 0);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 5) {
                SetColor(111, 209, 88, 84, 125, 59);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 6) {
                SetColor(204, 47, 12, 140, 33, 8);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 7) {
                SetColor(128, 41, 190, 93, 30, 138);
                dysplay += "░▒█";
                ResetColor();
            }
            else if (pole[j][i] == 8) {
                SetColor(237, 237, 237);
                dysplay += "███";
                ResetColor();
            }
        }
        dysplay += "\n";
    }
    for (int i=0; i < 12 ;i++) {

    }
    cout<<dysplay;
}

void preframe() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
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
        default:
            tetrominoBlock1[0] = 0;
            tetrominoBlock1[1] = 0;
            tetrominoBlock2[0] = 0;
            tetrominoBlock2[1] = 0;
            tetrominoBlock3[0] = 0;
            tetrominoBlock3[1] = 0;
            tetrominoBlock4[0] = 0;
            tetrominoBlock4[1] = 0;;
    }



    pole[row + tetrominoBlock1[0]][column + tetrominoBlock1[1]] = tetrominoType%10;
    pole[row + tetrominoBlock2[0]][column + tetrominoBlock2[1]] = tetrominoType%10;
    pole[row + tetrominoBlock3[0]][column + tetrominoBlock3[1]] = tetrominoType%10;
    pole[row + tetrominoBlock4[0]][column + tetrominoBlock4[1]] = tetrominoType%10;
}

void destroy() {
    int x = 0;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (metrix[j][i] != 0 && metrix[j][i] != 8) {
                x++;
            }
        }
        if (x == 10) {

            int line = j, q = 0;

            for (int i = 0; i < width; i++) {
                metrix[line][i] = 0;
            }
            for (int k = line; k > 0; k--) {
                for (int i = 0; i < width; i++) {
                    metrix[line-q][i] = metrix[line - (q + 1)][i];
                }
                q++;
            }
            bonus++;
        }
        x = 0;
    }
    if (bonus == 1) {
        score = score + (level * 40);
    }
    else if (bonus == 2) {
        score = score + (level * 100);
    }
    else if (bonus == 3) {
        score = score + (level * 300);
    }
    else if (bonus == 4) {
        score = score + (level * 1200);
    }

}


void makeSolid() {
    bagNum++;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            metrix[j][i] = pole[j][i];
        }
    }

    if (bagNum > 6) {
        shuffle(begin(randomBag), end(randomBag), std::mt19937(std::random_device()()));
        bagNum = 0;
    }
    tetrominoType = randomBag[bagNum];

    destroy();



    row = 0;
    column = 4;
}


void floorCheck() {

    if (metrix[row + tetrominoBlock1[0]+1][column + tetrominoBlock1[1]] != 0 ||
        metrix[row + tetrominoBlock2[0]+1][column + tetrominoBlock2[1]] != 0 ||
        metrix[row + tetrominoBlock3[0]+1][column + tetrominoBlock3[1]] != 0 ||
        metrix[row + tetrominoBlock4[0]+1][column + tetrominoBlock4[1]] != 0 ) {
        makeSolid();
    }

}


void renderBlockType() {
    bonus = 0;
    tetromino(tetrominoType);
}

void Score() {
    coutScore = "";
    int tempScore = score;
    int count = 0;
    while (tempScore >= 10) {
        tempScore = tempScore / 10;
        count++;
    }
    count++;

    string scoreText = to_string(score);


    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < count; i++) {
            int scoreDigit = scoreText[i] - '0';
            switch (scoreDigit) {
                case 1:
                    if (j == 0) {
                        coutScore.append(" _   ");
                    }
                    else if (j == 1) {
                        coutScore.append("/ |  ");
                    }
                    else if (j == 2) {
                        coutScore.append("| |  ");
                    }
                    else if (j == 3) {
                        coutScore.append("| |  ");
                    }
                    else if (j == 4) {
                        coutScore.append("|_|  ");
                    }
                    break;
                case 2:
                    if (j == 0) {
                        coutScore.append(" ____   ");
                    }
                    else if (j == 1) {
                        coutScore.append("|___ \\  ");
                    }
                    else if (j == 2) {
                        coutScore.append("  __) | ");
                    }
                    else if (j == 3) {
                        coutScore.append(" / __/  ");
                    }
                    else if (j == 4) {
                        coutScore.append("|_____| ");
                    }
                    break;
                case 3:
                    if (j == 0) {
                        coutScore.append(" _____  ");
                    }
                    else if (j == 1) {
                        coutScore.append("|___ /  ");
                    }
                    else if (j == 2) {
                        coutScore.append("  |_ \\  ");
                    }
                    else if (j == 3) {
                        coutScore.append(" ___) | ");
                    }
                    else if (j == 4) {
                        coutScore.append("|____/ ");
                    }
                    break;
                case 4:
                    if (j == 0) {
                        coutScore.append(" _  _   ");
                    }
                    else if (j == 1) {
                        coutScore.append("| || |  ");
                    }
                    else if (j == 2) {
                        coutScore.append("| || |_ ");
                    }
                    else if (j == 3) {
                        coutScore.append("|__   _|");
                    }
                    else if (j == 4) {
                        coutScore.append("   |_|  ");
                    }
                    break;
                case 5:
                    if (j == 0) {
                        coutScore.append(" ____   ");
                    }
                    else if (j == 1) {
                        coutScore.append("| ___|  ");
                    }
                    else if (j == 2) {
                        coutScore.append("|___ \\  ");
                    }
                    else if (j == 3) {
                        coutScore.append(" ___) | ");
                    }
                    else if (j == 4) {
                        coutScore.append("|____/  ");
                    }
                    break;
                case 6:
                    if (j == 0) {
                        coutScore.append("  __    ");
                    }
                    else if (j == 1) {
                        coutScore.append(" / /_   ");
                    }
                    else if (j == 2) {
                        coutScore.append("| '_ \\  ");
                    }
                    else if (j == 3) {
                        coutScore.append("| (_) | ");
                    }
                    else if (j == 4) {
                        coutScore.append(" \\___/  ");
                    }
                    break;
                case 7:
                    if (j == 0) {
                        coutScore.append(" _____  ");
                    }
                    else if (j == 1) {
                        coutScore.append("|___  | ");
                    }
                    else if (j == 2) {
                        coutScore.append("   / /  ");
                    }
                    else if (j == 3) {
                        coutScore.append("  / /   ");
                    }
                    else if (j == 4) {
                        coutScore.append(" /_/    ");
                    }
                    break;
                case 8:
                    if (j == 0) {
                        coutScore.append("  ___   ");
                    }
                    else if (j == 1) {
                        coutScore.append(" ( _ )  ");
                    }
                    else if (j == 2) {
                        coutScore.append(" / _ \\  ");
                    }
                    else if (j == 3) {
                        coutScore.append("| (_) | ");
                    }
                    else if (j == 4) {
                        coutScore.append(" \\___/  ");
                    }
                    break;
                case 9:
                    if (j == 0) {
                        coutScore.append("  ___   ");
                    }
                    else if (j == 1) {
                        coutScore.append(" / _ \\  ");
                    }
                    else if (j == 2) {
                        coutScore.append("| (_) | ");
                    }
                    else if (j == 3) {
                        coutScore.append(" \\__, | ");
                    }
                    else if (j == 4) {
                        coutScore.append("   /_/  ");
                    }
                    break;
                case 0:
                    if (j == 0) {
                        coutScore.append("  ___   ");
                    }
                    else if (j == 1) {
                        coutScore.append(" / _ \\  ");
                    }
                    else if (j == 2) {
                        coutScore.append("| | | | ");
                    }
                    else if (j == 3) {
                        coutScore.append("| |_| | ");
                    }
                    else if (j == 4) {
                        coutScore.append(" \\___/  ");
                    }
                    break;
            }
        }
        coutScore.append(" \n");
    }
}

//Tetrominos

//-------GAMEPLAY------------------


void update() {
    dysplay = "";
    preframe();
    renderBlockType();
    Score();
    rendering();
    cout<<coutScore;
}

void rotate() {

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
}

void run(int inputValue) {

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
}

int input() {
    if (GetAsyncKeyState('S') & 0x8000) {
        inputValue = -1;
        //score++;
        run(inputValue);
    }
    else if (GetAsyncKeyState('D') & 0x8000 && !(GetAsyncKeyState('A') & 0x8000)) {
        inputValue = 1;
        if (metrix[row + tetrominoBlock1[0]][column + tetrominoBlock1[1]+1] == 0 &&
            metrix[row + tetrominoBlock2[0]][column + tetrominoBlock2[1]+1] == 0 &&
            metrix[row + tetrominoBlock3[0]][column + tetrominoBlock3[1]+1] == 0 &&
            metrix[row + tetrominoBlock4[0]][column + tetrominoBlock4[1]+1] == 0) {
            run(inputValue);
        }
        else {
            return 0;
        }

    }
    else if (GetAsyncKeyState('A') & 0x8000 && !(GetAsyncKeyState('D') & 0x8000)) {
        inputValue = 2;
        if (metrix[row + tetrominoBlock1[0]][column + tetrominoBlock1[1]-1] == 0 &&
            metrix[row + tetrominoBlock2[0]][column + tetrominoBlock2[1]-1] == 0 &&
            metrix[row + tetrominoBlock3[0]][column + tetrominoBlock3[1]-1] == 0 &&
            metrix[row + tetrominoBlock4[0]][column + tetrominoBlock4[1]-1] == 0) {
            run(inputValue);
        }
        else {
            return 0;
        }
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
    while (gameOn == true) {
        input();
        fall();
        if (tenFrame == 10) {
            tenFrame = 0;
        }
        _sleep(100);
        tenFrame++;
    }

    system("cls");
    cout << R"(
   ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗
  ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗
  ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝
  ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║ ██  ██╔╝██╔══╝  ██╔══██╗
  ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║
   ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝
    )";
    int x = 0;
    cout << "\n╔══════════════════╗\n";
    cout << "      SCORE: " << score << "      \n";
    cout << "╚══════════════════╝\n";
    cin>>x;
    return 0;
}

