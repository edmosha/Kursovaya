#include "../Header/function.h"

void UinCalc(double time[], double U_in[], int n) {
    double t1 = 22.5, tStart = 10, tEnd = 35, a = 12, b= 12, dt;
    dt = (tEnd - tStart) / (n - 1);
    time[0] = tStart;

    for (int i = 1; i < n; i++) {
        time[i] = time[i - 1] + dt;
    }
    double j = tStart;

    for (int i = 0; i < n; i++) {
        if (j <= t1) {
            U_in[i] = a * (j - tStart);
        } else {
            U_in[i] = a * (t1 - tStart) - b * (j - t1);
        }
        j += dt;
    }
}

void UoutCalc(double time[], double U_in[], double U_out[], int n) {
    double U1 = 0, U2 = 100, Uin1 = 2, Uin2 = 10;
    for (int i = 0; i < n; i++) {
        if (U_in[i] <= Uin1) {
            U_out[i] = U1;
        } else if (U_in[i] < Uin2) {
            U_out[i] = (U_in[i]-Uin1) * (U2-U1) / (Uin2-Uin1) + U1;
        } else {
            U_out[i] = U2;
        }
    }
}

void Show (double  time[], double U_in[], double U_out[], int n) {
    cout << "|t| \t\t\t\t\t|Uin|\t\t\t\t\t|Uout|\n" << endl;

    for (int i = 0; i < n; i++) {
        printf ("%-8.4g\t\t\t\t%-8.4g\t\t\t\t%-8.4g\n", time[i], U_in[i], U_out[i]);
    }
    cout << endl;
}

double ParamCalc(double  time[], double U_in[], int n) {
    double maxTime, max = -999999;
    int numMax = -1;
    for(int i = 0; i < n; i++) {
        if (U_in[i] > max) {
            max = U_in[i];
            numMax = i;
        }
    }
    maxTime = time[numMax];
    return maxTime;
}

void SaveToFile(double  array[], int n, string fileName) {
    fileName = "..\\" + fileName +".txt";
    ofstream writer;
    writer.open(fileName);
    if (writer.is_open()) {
        for (int i=0; i<n; i++) {
            writer << array[i] << endl;
        }
    }
    writer.close();
}

void ReadIntro() {
    string line;
    cout << endl;

    ifstream in("..\\intro.txt");
    if(in.is_open()) {
        for (int i=0; i<3; i++) {
            while (getline(in , line)) {
                cout << line << endl;
            }
        }
        in.close();
    cout << endl;
    }
}