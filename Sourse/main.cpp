#include <iostream>
#include "../Header/function.h"

using namespace std;

double t1 = 22.5, tStart = 10, tEnd = 35, a = 12, b= 12;
double U1 = 0, U2 = 100, Uin1 = 2, Uin2 = 10;
int N, choose;
double *t, *Uin, *Uout;

int main() {
        while (choose != 3) {
            cout << "Выберите действие:" << endl;
            cout << "1. Расчет времени, входного и выходного напряжения" << endl;
            cout << "2. Расчет параметра" << endl;
            cout << "3. Запись в файл" << endl;
            cin >> choose;

            switch (choose) {
                case 1: {
                    cout << "Введите кол-во точек: ";
                    cin >> N;
                    cin.ignore();
                    t = new double[N];
                    Uin = new double[N];
                    Uout = new double[N];
                    UinCalc(t, Uin, N, tStart, tEnd, t1, a, b);
                    UoutCalc(t, Uin, Uout, N, U1, U2, Uin1, Uin2);
                    Show(t, Uin, Uout, N);
                }
                    break;
                case 2: {

                }
                    break;
                case 3: {

                }
                    break;
                default: {

                }
            }
        }
    }


    /* 1. расчет входного U
     * 2. расчет выходного U
     * 3. вывод в консоль табло Uin Uout t
     * 4. запись в файл Uin
     * 5. запись в файл Uout
     * 6. запись в файл t
     * 7. расчет параметра*/
    return 0;
}


