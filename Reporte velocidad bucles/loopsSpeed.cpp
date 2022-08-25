// loopsSpeed.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <fstream>
#include <iostream>
#include <chrono>
#include <random>
#include <string>

const unsigned int MAXI = 20000;

using namespace std;
string d1, d2;
void test() {
    
    srand(time(NULL));

    double** A = new double*[MAXI];
    for (long int i = 0; i < MAXI; i++) {
        A[i] = new double[MAXI];
    }

    double* x= new double[MAXI];
    double* y= new double[MAXI];

    for (long int j = 0; j < MAXI; j++) {
        y[j] = 0;
    }

    for (long int j = 0; j < MAXI; j++) {

        x[j] = double(rand()) * MAXI;
    }

    for (double** i = A; i <A+MAXI; i++) {
        double* aux = *i;
        for (double* j = aux; j < aux+MAXI; j++) {
               *j = double(rand()) * MAXI;
        }
    }
    cout << "first bucle \n" << endl;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end, start1, end1;
    start = std::chrono::high_resolution_clock::now();


    end = std::chrono::high_resolution_clock::now();
    int64_t duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    for (long int i = 0; i < MAXI; i++) {
        for (long int j = 0; j < MAXI; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    

    for (long int j = 0; j < MAXI; j++) {
        y[j] = 0;
    }

    cout << "segundo bloque" << endl;
    
    start1 = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < MAXI; j++) {
        for (int i = 0; i < MAXI; i++) {
            y[i] += A[i][j]* x[j];
        }
    }
    end1 = std::chrono::high_resolution_clock::now();
    int64_t duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();

    cout <<"primer bucle" << "\t\t" << "segundo bucle" << endl;
    d1 = to_string(duration);
    d2 = to_string(duration1);
}

int main()
{ 
    test();
    ofstream of;
    of.open("data.csv",ios_base::app);
    of << MAXI <<";";
    of << d1<<";";
    of << d2 <<"\n";

    of.close();
   
    return 0;
}
