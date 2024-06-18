#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_LENGTH = 100;
    char inputString[MAX_LENGTH];

    cout << "Enter a string: ";
    cin.getline(inputString, MAX_LENGTH);

    int length = strlen(inputString);

    // Create a pointer to the last character of the string
    char* reversePointer = inputString + length - 1;

    cout << "Reversed string: ";
    while (reversePointer >= inputString) {
        cout << *reversePointer;
        reversePointer--;
    }

    cout << endl;

    return 0;
}

