#include <iostream>
#include <cstdlib> 
#include <ctime> 

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#define MaxAlfabet 255 // Number of alphabet character supported
#define keyLenghtMAX 21 // Max key lenght supported

using namespace std;

void AlfabetGeneration(int Alfabet[]); // Function to generate the alpabet (BETA)
void KeyGenerator(char []); // Function to generate the key or make it choose at the u
void caricaStringa(char [], int); // Text like function to write in array of char
bool keyValidyCheck(char []); // Check 

int main() {

    srand(time(NULL));

    // Variabili Temp
    char key[keyLenghtMAX];

    // Alfabeto
    int Alfabet[MaxAlfabet];

    AlfabetGeneration(Alfabet);

    /*
    // Print the array
    for(int i = 1; i <= MaxAlfabet; i++) {
        cout << Alfabet[i] << " ";
    }
    */ 
    
    cout << "Key randomica? [y/n]" <<endl;
    KeyGenerator(key);

    cout << "\nChiave generata: " << key << endl;

    return 0;
}

// Text loading

// Windows
#ifdef _WIN32
void caricaStringa(char str[], int max){
    int i = 0;
    char car;
    while (i < max - 1 && (car = getche()) != '\r')
    {
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

    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Set new terminal attributes

    ch = getchar(); // Read a character

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old terminal attributes
    return ch;
}

// Function to get a line of input from the user with backspace handling
void caricaStringa(char str[], int max) {
    int i = 0;
    char car;

    while (i < max - 1) {
        car = getch(); // Get a single character

        if (car == '\n' || car == '\r') {
            // End of input (Enter key)
            break;
        } else if (car == 127 || car == '\b') {
            // Handle backspace
            if (i > 0) {
                i--;
                cout << "\b \b"; // Move cursor back, overwrite with space, and move cursor back again
            }
        } else {
            // Normal character input
            str[i] = car;
            i++;
            cout << car; // Echo the character
        }
    }
    str[i] = '\0'; // Null-terminate the string
    cout << endl; // Print a newline character
}
#endif
// End Text loading

void KeyGenerator(char key[]){
    
    char scelta;
    int randomValue;
    
    do{
        cin >> scelta;
        if (scelta !='y' && scelta != 'n'){ //Validation of y/n
            cout << "Error: invalid input" <<endl;
        }

    }while(scelta !='y' && scelta != 'n'); 

    if (scelta == 'y'){        
        for (int i = 0; i < keyLenghtMAX; i++) {
            do{
                randomValue = rand() % (122 - 33 + 1) + 33; // Random value between 33 and 122
            }while (randomValue == 34 || randomValue == 39 || randomValue == 40 || randomValue == 41 || randomValue == 44 || randomValue == 45 || randomValue == 58 || randomValue == 59 || randomValue == 96 );
            key[i] = char(randomValue); // Convert int to char
        }
            
        key[keyLenghtMAX] = '\0';
        }
    else{ //If not random
          do{
            cin.ignore(); // Clean the residue in the buffer
            cout << "Inserisci la chiave: " << endl;
            caricaStringa(key, keyLenghtMAX); // Manual loading of the key by user
            //Messagio Errore
             if (!keyValidyCheck(key)) {
                cout << "\nError: Key must be at least 10 characters long, containing at least 5 letters/symbols and 5 numbers.\n";
            }

        }while(keyValidyCheck(key) == false);
    }
}

bool keyValidyCheck(char keyimport[]) {
    int length = 0;
    int numCount = 0;
    int letterOrSymbolCount = 0;

    for(int i = 0; i < keyLenghtMAX - 1 && keyimport[i] != '\0'; i++) {
        char c = keyimport[i];

        // check invalid characters
        if (c <= 32 || c == 34 || c == 39 || c == 40 || c == 41 || 
            c == 44 || c == 45 || c == 58 || c == 59 || c == 96 || c >= 123) {
            return false;
        }

         // Count numbers
        if (c >= '0' && c <= '9') {
            numCount++;
        } else { // Count letters and symbols
            letterOrSymbolCount++;
        }

        length++;
    }

    // Key validit ycheck
    if (length >= 10 && numCount >= 5 && letterOrSymbolCount >= 5) {
        return true;
    } else {
        return false;
    }
}

// Alpabet

void AlfabetGeneration(int Alfabet[]) {
    for(int i = 1; i <= MaxAlfabet; i++) {
        Alfabet[i] = i;
    }
}