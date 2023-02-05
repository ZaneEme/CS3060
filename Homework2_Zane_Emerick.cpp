#include <iostream>
#include <cmath>
using namespace std;

void assignInts(int (&arr)[2]);
void squareAdd(int *One, int *Two);
void printResults(int *One, int *Two, double *sqareRoot);

int main() {
    int arr[2];

    cout << "Please enter two integers seperated by spaces: ";

    while(!(cin>>arr[0]>>arr[1])) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please try again: ";
    }

    assignInts(arr);
}


void assignInts(int (&arr)[2]) {
    int One = arr[0];
    int Two = arr[1];

    squareAdd(&One, &Two);
}

void squareAdd(int *One, int *Two) {
    int OneSquared = *One * *One;
    int TwoSquared = *Two * *Two;
    int sumNums = OneSquared + TwoSquared;
    double sqareRoot = sqrt(sumNums);
    
    printResults(One, Two, &sqareRoot);
}

void printResults(int *One, int *Two, double *sqareRoot) {
    cout << "The square root of " << *One << " squared plus " << *Two << " squared is " << *sqareRoot << endl;
}