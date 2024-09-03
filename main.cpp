#include <iostream>
#include <cstdlib>
#include <ctime>


#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#define MaxAlfabet 95 // Number of characters in printable ASCII range
#define keyLenghtMAX 21 // Max key length supported
#define ALPHABET_START 20000
#define ALPHABET_END 50000

using namespace std;

// Function declarations
void AlfabetGeneration(int Alfabet[], int charToNum[]); // Generate alphabet values and mappings
void KeyGenerator(char key[]); // Function to generate or input the key
void caricaStringa(char str[], int max); // Function to load a string from the user
bool keyValidyCheck(char key[]); // Validate the key
void CreateNumericKey(const char key[], const int Alfabet[], int charToNum[], char numericKey[], int& numericKeyLen); // Convert key to numeric based on alphabet

void FirstCryptation();

int main() {
    srand(time(NULL));

    // Temp variables
    char key[keyLenghtMAX];
    int Alfabet[MaxAlfabet];
    int charToNum[128]; // Array to map ASCII values to their numeric equivalents
    char numericKey[keyLenghtMAX * 6]; // To store the numeric key, considering digits could be 5 or more digits
    int numericKeyLen = 0; // Length of the numeric key

    // Generate alphabet
    AlfabetGeneration(Alfabet, charToNum);

    cout << "Key randomica? [y/n]" <<endl;
    KeyGenerator(key);

    cout << "\nChiave generata: " << key << endl;

    // Convert the key to a numeric key based on the generated alphabet
    CreateNumericKey(key, Alfabet, charToNum, numericKey, numericKeyLen);

    cout << "Chiave numerica: ";
    for (int i = 0; i < numericKeyLen; i++) {
        cout << numericKey[i];
    }
    cout << endl;

//  FirstCryptation();

    return 0;
}

// Text loading

// Windows
#ifdef _WIN32
void caricaStringa(char str[], int max) {
    int i = 0;
    char car;
    while (i < max - 1 && (car = getche()) != '\r') {
        str[i] = car;
        i++;
    }
    str[i] = '\0';
}
#endif

#ifndef _WIN32
// Unix
char getch() {
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to get a line of input from the user with backspace handling
void caricaStringa(char str[], int max) {
    int i = 0;
    char car;

    while (i < max - 1) {
        car = getch();

        if (car == '\n' || car == '\r') {
            break;
        } else if (car == 127 || car == '\b') {
            if (i > 0) {
                i--;
                cout << "\b \b";
            }
        } else {
            str[i] = car;
            i++;
            cout << car;
        }
    }
    str[i] = '\0';
    cout << endl;
}
#endif
// End Text loading

void KeyGenerator(char key[]) {
    char scelta;
    int randomValue;

    do {
        cin >> scelta;
        if (scelta != 'y' && scelta != 'n') {
            cout << "Error: invalid input" << endl;
        }
    } while (scelta != 'y' && scelta != 'n');

    if (scelta == 'y') {
        for (int i = 0; i < keyLenghtMAX - 1; i++) {
            do {
                randomValue = rand() % (126 - 32 + 1) + 32; // Random value between 32 and 126
            } while (randomValue == 34 || randomValue == 39 || randomValue == 40 || randomValue == 41 || randomValue == 44 || randomValue == 45 || randomValue == 58 || randomValue == 59 || randomValue == 96);
            key[i] = char(randomValue); // Convert int to char
        }
        key[keyLenghtMAX - 1] = '\0';
    } else {
        cin.ignore(); // Clean the residue in the buffer
        cout << "Inserisci la chiave: " << endl;
        do {
            caricaStringa(key, keyLenghtMAX); // Manual loading of the key by user
            if (!keyValidyCheck(key)) {
                cout << "\nError: Key must be at least 10 characters long, containing at least 5 letters/symbols and 5 numbers.\n";
            }
        } while (!keyValidyCheck(key));
    }
}

bool keyValidyCheck(char key[]) {
    int length = 0;
    int numCount = 0;
    int letterOrSymbolCount = 0;

    for (int i = 0; i < keyLenghtMAX - 1 && key[i] != '\0'; i++) {
        char c = key[i];

        if (c <= 32 || c == 34 || c == 39 || c == 40 || c == 41 || 
            c == 44 || c == 45 || c == 58 || c == 59 || c == 96 || c >= 127) {
            return false;
        }

        if (c >= '0' && c <= '9') {
            numCount++;
        } else {
            letterOrSymbolCount++;
        }

        length++;
    }

    return length >= 10 && numCount >= 5 && letterOrSymbolCount >= 5;
}

void AlfabetGeneration(int Alfabet[], int charToNum[]) {
    int startValue = ALPHABET_START;
    int endValue = ALPHABET_END;
    int range = endValue - startValue;
    int baseValue = startValue;

    for (int i = 32; i <= 126; i++) { // Printable ASCII range
        if (i == 34 || i == 39 || i == 40 || i == 41 || i == 44 || i == 45 || i == 58 || i == 59 || i == 96) {
            continue; // Skip certain characters
        }

        int offset = (i - 32) * range / (126 - 32); // Offset calculation for uniform distribution
        Alfabet[i - 32] = baseValue + offset;
        charToNum[i] = Alfabet[i - 32]; // Map ASCII value to numeric value
    }
}

void CreateNumericKey(const char key[], const int Alfabet[], int charToNum[], char numericKey[], int& numericKeyLen) {
    numericKeyLen = 0;

    for (int i = 0; i < keyLenghtMAX - 1 && key[i] != '\0'; i++) {
        char c = key[i];
        if (c >= '0' && c <= '9') {
            numericKey[numericKeyLen++] = c; // Append numbers as is
        } else if (c >= 32 && c <= 126) {
            int index = c - 32;
            if (index >= 0 && index < MaxAlfabet) {
                int value = charToNum[c];
                // Convert value to string and append to numericKey
                char temp[6]; // Temporary buffer for digits (5 digits + null terminator)
                int pos = 0;

                // Convert integer value to characters
                if (value == 0) {
                    temp[pos++] = '0';
                } else {
                    while (value > 0) {
                        temp[pos++] = '0' + (value % 10);
                        value /= 10;
                    }
                    // Reverse the digits
                    for (int j = 0; j < pos / 2; j++) {
                        char t = temp[j];
                        temp[j] = temp[pos - 1 - j];
                        temp[pos - 1 - j] = t;
                    }
                }

                // Append the digits to numericKey
                for (int j = 0; j < pos; j++) {
                    numericKey[numericKeyLen++] = temp[j];
                }
            }
        }
    }
    numericKey[numericKeyLen] = '\0'; // Null-terminate the numeric key
}

//-----------------------------------------------------------------------------------------------------------------

