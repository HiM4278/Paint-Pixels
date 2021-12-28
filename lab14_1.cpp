#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double Mean = 0,Deviation = 0,Geometric = 0,Ge2,Harmonic = 0,Max = A[0],Min = A[0];
    for (int i = 0; i < N; i++) Mean += A[i];
    B[0] = Mean/N;    
    for (int i = 0; i < N; i++) Deviation += pow(A[i],2);
    B[1] = sqrt((Deviation/N)-pow(Mean/N,2));
    for (int i = 0; i < N; i++) Geometric += log10(A[i]);
    Ge2 = Geometric/N;
    B[2] = pow(10,Ge2);
    for (int i = 0; i < N; i++) Harmonic += 1/A[i];
    B[3] = N/Harmonic;
    for (int i = 0; i < N; i++) {
        if (A[i] > Max) Max = A[i];
        if (A[i] < Min) Min = A[i];
    } 
    B[4] = Max;
    B[5] = Min;
}
