#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int SIZE = 15;
string commond;
bool x[SIZE];
bool y[SIZE];
bool xy[SIZE][SIZE];
int point1 = 0;
int point2 = 0;
int choice = 1;
int exist = 0;
void print();

int main() {
    for (int i = 0; i < SIZE; i++) {
        x[i] = false;
        y[i] = false;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            xy[i][j] = false;
        }
    }
    print();
    while (1) {
        for (int i = 0; i < SIZE; i++) {
            x[i] = false;
            y[i] = false;
        }
        cin >> commond;
        switch (commond[0]) {
        case '1':x[0] = true; break;
        case '2':x[1] = true; break;
        case '3':x[2] = true; break;
        case '4':x[3] = true; break;
        case '5':x[4] = true; break;
        case '6':x[5] = true; break;
        case '7':x[6] = true; break;
        case '8':x[7] = true; break;
        case '9':x[8] = true; break;
        case 'A':x[9] = true; break;
        case 'B':x[10] = true; break;
        case 'C':x[11] = true; break;
        case 'D':x[12] = true; break;
        case 'E':x[13] = true; break;
        case 'F':x[14] = true; break;
        }
        switch (commond[1]) {
        case '1':y[0] = true; break;
        case '2':y[1] = true; break;
        case '3':y[2] = true; break;
        case '4':y[3] = true; break;
        case '5':y[4] = true; break;
        case '6':y[5] = true; break;
        case '7':y[6] = true; break;
        case '8':y[7] = true; break;
        case '9':y[8] = true; break;
        case 'A':y[9] = true; break;
        case 'B':y[10] = true; break;
        case 'C':y[11] = true; break;
        case 'D':y[12] = true; break;
        case 'E':y[13] = true; break;
        case 'F':y[14] = true; break;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (x[i] && y[j]) xy[i][j] = true;
            }
        }
        if (choice == 1) {
            cout << "\n1的回合\n";
        }
        else {
            cout << "\n2的回合\n";
        }
        print();

        cout << "\npoint1:" << point1 << " point2:" << point2 << ' ';
    }
}
void print() {
    exist = 0;
    for (int i = 0; i < SIZE; i++) {
        if (i < 9) cout << i + 1 << ' ';
        else {
            switch (i) {
            case 9:cout << "A "; break;
            case 10:cout << "B "; break;
            case 11:cout << "C "; break;
            case 12:cout << "D "; break;
            case 13:cout << "E "; break;
            case 14:cout << "F "; break;
            }
        }
    }
    cout << endl;
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (j % 2 == 0) {
                if (i % 2 == 0) {
                    cout << "。";
                }
                else {
                    if (xy[i][j]) {
                        cout << "一";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
            }
            else {
                if (i % 2 == 0) {
                    if (xy[i][j]) {
                        cout << "|";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else {
                    if (xy[i + 1][j] && xy[i - 1][j] && xy[i][j + 1] && xy[i][j - 1]) {
                        if (choice == 1) {
                            cout << " @ ";
                            choice = 1;
                        }
                        else {
                            cout << " # ";
                            choice = 2;
                        }
                        exist++;
                    }
                    else {
                        if (choice == 1) {
                            cout << "   ";
                            choice = 2;
                        }
                        else {
                            cout << "   ";
                            choice = 1;
                        }
                    }
                }
            }
        }
        if (j < 9)
            if (j % 2 == 0) cout << j + 1 << endl;
            else cout << ' ' << j + 1 << endl;
        else {
            switch (j) {
            case 9:cout << " A \n"; break;
            case 10:cout << "B \n"; break;
            case 11:cout << " C \n"; break;
            case 12:cout << "D \n"; break;
            case 13:cout << " E \n"; break;
            case 14:cout << "F \n"; break;
            }
        }
        if (exist > (point1 + point2)) {
            if (choice == 1) {
                point1++;
            }
            else {
                point2++;
            }
        }
    }
}