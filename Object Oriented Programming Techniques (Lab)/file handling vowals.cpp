#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream myFile("desktop.txt");
    myFile << "file can be tricky, but it is fun enough!";
    myFile.close();
    ifstream MyReadFile("desktop.txt");
    char currentChar;
    int vowelCount = 0;
    while (MyReadFile.get(currentChar)) {
        char lowercaseChar = (currentChar >= 'A' && currentChar <= 'Z') ? (currentChar + 'a' - 'A') : currentChar;

        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u') {
            vowelCount++;
        }
    }

    cout << "Number of vowels in the file: " << vowelCount << endl;
    MyReadFile.close();

    return 0;
}
