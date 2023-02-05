#include <iostream>
using namespace std;

void drawSquare(int);
void drawTriangle(int);
void drawDiamond(int);

int main() {
    bool loopRunning = true;

    cout << "Good day! What shape would you like to create?" << endl;

    while (loopRunning) {
        int inputNumber;
        int size = 0;

        cout << "1. Square" << endl;
        cout << "2. Triangle" << endl;
        cout << "3. Diamond" << endl;
        cout << "4. Exit" << endl;

        cin >> inputNumber;

        if (inputNumber > 0 && inputNumber < 4) {
            cout << "What should the size of the shape be?" << endl;
            cin >> size;
        }

        switch (inputNumber) {
        case 1:
            cout << "You have chosen to create a square." << endl;
            drawSquare(size);
            break;
        case 2:
            cout << "You have chosen to create a triangle." << endl;
            drawTriangle(size);
            break;
        case 3:
            cout << "You have chosen to create a diamond." << endl;
            drawDiamond(size);
            break;
        case 4:
            cout << "You have chosen to exit the program." << endl;
            loopRunning = false;
            continue;
        default:
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        cout << "Would you like to draw again? (y / n)   ";
        char retry;
        bool retryLoop = true;
        
        while (retryLoop) {
            cin >> retry;
            cout << endl;

            if (retry == 'y' || retry == 'Y') {
                loopRunning = true;
                break;
            }
            else if(retry == 'n' || retry == 'N') {
                loopRunning = false;
                break;
            }
            else {
                cout << "Invalid input. Please try again." << endl;
            }
        }
        

    }
    return 0;
}

void drawSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void drawTriangle(int size) {
    int spacing = size;
    for (int i = 0; i <= size; i++) {
        for (int k = 0; k < spacing; k++) {
            cout << " ";
        }

        for (int j = 0; j < i; j++) {
            cout << "*";
            cout << " ";
        }
        spacing--;
        cout << endl;
    }
}

void drawDiamond(int size) {
   drawTriangle(size);

   for (int i = size - 1; i > 0; i--) {
       for (int j = 0; j < size - i; j++) {
           cout << " ";
       }
       for (int k = 0; k < i; k++) {
           cout << "*";
           cout << " ";
       }
       cout << endl;
   } 
}