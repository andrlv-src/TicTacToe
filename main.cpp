//
//  main.cpp
//  CvZ
//
//  Created by andrey on 22.10.15.
//  Copyright © 2015 Maria Efimova. All rights reserved.
//

#include <iostream>
using namespace std;

int go;
bool POneX = false;
bool PTwo0 = false;
char field[3][3] = {{49, 50, 51},
    {52, 53, 54},
    {55, 56, 57}};

char choice_of_player;

void moves(); // ходы
void transfer_of_going(); // передача хода
void input_field(); // вывод поля
void PlayerX(); // ход для игрока Х
void Player0(); // ход для игрока 0

int main() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << field[i][j] <<" ";
        }
        
        cout << "\n";
    }
    
    cout << "\n";
    cout << "Choose the first player. Enter X or 0:";
    cin >> choice_of_player;
    
    if(choice_of_player == 48) {
        POneX = false;
        PTwo0 = true;
    } else if (choice_of_player == 88) {
        POneX = true;
        PTwo0 = false;
    }
    
    moves();
    moves();
    moves();
    moves();
    moves();
    moves();
    moves();
    moves();
    moves();
    
    //проверка на выигрыш
    if ((field[0][0] == 48 && field[0][1] == 48 && field[0][2] == 48)
        ||(field[0][0] == 48 && field[1][0] == 48 && field[2][0] == 48)
        ||(field[0][0] == 48 && field[1][1] == 48 && field[2][2] == 48)
        ||(field[0][2] == 48 && field[1][1] == 48 && field[2][0] == 48)
        ||(field[0][1] == 48 && field[1][1] == 48 && field[2][1] == 48)
        ||(field[0][2] == 48 && field[1][2] == 48 && field[2][2] == 48)
        ||(field[1][0] == 48 && field[1][1] == 48 && field[1][2] == 48)
        ||(field[2][0] == 48 && field[2][1] == 48 && field[2][2] == 48)) {
        cout << "Player 0 win!\n";
    } else if ((field[0][0] == 88 && field[0][1] == 48 && field[0][2] == 88)
               ||(field[0][0] == 88 && field[1][0] == 88 && field[2][0] == 88)
               ||(field[0][0] == 88 && field[1][1] == 88 && field[2][2] == 88)
               ||(field[0][2] == 88 && field[1][1] == 88 && field[2][0] == 88)
               ||(field[0][1] == 88 && field[1][1] == 88 && field[2][1] == 88)
               ||(field[0][2] == 88 && field[1][2] == 88 && field[2][2] == 88)
               ||(field[1][0] == 88 && field[1][1] == 88 && field[1][2] == 88)
               ||(field[2][0] == 88 && field[2][1] == 88 && field[2][2] == 88)) {
        cout << "Player X win!\n";
    } else {
        cout << "Nichja, yopta! :D\n";
    }}

void moves() {
    transfer_of_going();
    input_field();
    
    if(PTwo0 == true && POneX == false) {
        PTwo0 = false;
        POneX = true;
        
    } else if (PTwo0 == false && POneX == true) {
        PTwo0 = true;
        POneX = false;
    }
}

void transfer_of_going() {
    if(PTwo0 == true && POneX == false) {
        Player0();
    } else if (PTwo0 == false && POneX == true) {
        PlayerX();
    }
}

void PlayerX() {
    cout << "Player X enter field number: ";
    cin >> go;
    
    //проверяем,не занято ли поле
    while((go == 1 && (field[0][0] == 88 || field[0][0] == 48))
          || (go == 2 && (field[0][1] == 88 || field[0][1] == 48))
          || (go == 3 && (field[0][2] == 88 || field[0][2] == 48))
          || (go == 4 && (field[1][0] == 88 || field[1][0] == 48))
          || (go == 5 && (field[1][1] == 88 || field[1][1] == 48))
          || (go == 6 && (field[1][2] == 88 || field[1][2] == 48))
          || (go == 7 && (field[2][0] == 88 || field[2][0] == 48))
          || (go == 8 && (field[2][1] == 88 || field[2][1] == 48))
          || (go == 9 && (field[2][2] == 88 || field[2][2] == 48))) {
        cout << "Employed number! Try again: ";
        cin >> go;
    } do {
        switch (go) {
            case 1:
                field [0][0] = 88;
                break;
            case 2:
                field [0][1] = 88;
                break;
            case 3:
                field [0][2] = 88;
                break;
            case 4:
                field [1][0] = 88;
                break;
            case 5:
                field [1][1] = 88;
                break;
            case 6:
                field [1][2] = 88;
                break;
            case 7:
                field [2][0] = 88;
                break;
            case 8:
                field [2][1] = 88;
                break;
            case 9:
                field [2][2] = 88;
                break;
            default:
                cout << "Wrong number! Try again: ";
                break;
                
        }
        
        if (go < 1 || go > 9) {
            cin >> go;
        }
        
    } while (go < 1 || go > 9);
}

void Player0() {
    cout << "Player 0 enter field number: ";
    cin >> go;
    
    //проверяем,не занято ли поле
    while((go == 1 && (field[0][0] == 88 || field[0][0] == 48))
          || (go == 2 && (field[0][1] == 88 || field[0][1] == 48))
          || (go == 3 && (field[0][2] == 88 || field[0][2] == 48))
          || (go == 4 && (field[1][0] == 88 || field[1][0] == 48))
          || (go == 5 && (field[1][1] == 88 || field[1][1] == 48))
          || (go == 6 && (field[1][2] == 88 || field[1][2] == 48))
          || (go == 7 && (field[2][0] == 88 || field[2][0] == 48))
          || (go == 8 && (field[2][1] == 88 || field[2][1] == 48))
          || (go == 9 && (field[2][2] == 88 || field[2][2] == 48))) {
        cout << "Employed number! Try again: ";
        cin >> go;
    } do {
        switch (go) {
            case 1:
                field [0][0] = 48;
                break;
            case 2:
                field [0][1] = 48;
                break;
            case 3:
                field [0][2] = 48;
                break;
            case 4:
                field [1][0] = 48;
                break;
            case 5:
                field [1][1] = 48;
                break;
            case 6:
                field [1][2] = 48;
                break;
            case 7:
                field [2][0] = 48;
                break;
            case 8:
                field [2][1] = 48;
                break;
            case 9:
                field [2][2] = 48;
                break;
            default:
                cout << "Wrong number! Try again: ";
                break;
                
        }
        
        if (go < 1 || go > 9) {
            cin >> go;
        }
        
    } while (go < 1 || go > 9);
}

void input_field() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << field[i][j] << " ";
        }
        
        cout << "\n";
    }
}
