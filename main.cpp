#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>   // for FILE, fopen, fgets, fclose


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
#define MAXPATH 250

using namespace std;

// Function declarations
void AlfabetGeneration(int Alfabet[], int charToNum[]); // Generate alphabet values and mappings
void KeyGenerator(char key[]); // Function to generate or input the key
void caricaStringa(char str[], int max); // Function to load a string from the user
bool keyValidyCheck(char key[]); // Validate the key
void CreateNumericKey(const char key[], const int Alfabet[], int charToNum[], char numericKey[], int& numericKeyLen); // Convert key to numeric based on alphabet
void pathTaker(char []);
bool pathVerifier(char []);
int charTaker(char []);

void FirstCryptation();

int main() {
    srand(time(NULL));

    // Temp variables
    char key[keyLenghtMAX];
    int Alfabet[MaxAlfabet];
    int charToNum[128]; // Array to map ASCII values to their numeric equivalents
    char numericKey[keyLenghtMAX * 6]; // To store the numeric key, considering digits could be 5 or more digits
    int numericKeyLen = 0; // Length of the numeric key

    // NEW
    char filePath[MAXPATH];

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

    pathTaker(filePath);

    //  FirstCryptation();

    charTaker(filePath);

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

/*
    FILE *punt; //dichiarazione di una variabile che ci permetterà di gestire il file
    //filename è il path del percorso che voglio aprire, il file deve essere perforza nella cartella del programma.
    //r = solo leggere senza scrivere, se il file non esiste non viene creato - //w = solo scrivere e non leggere, se il file non esiste viene creato, se esiste il contenuto preesistente viene perso
    //r+ = leggere e scrivere - w+ = leggere e scrivere //Cambia il controllo se il file esiste o no e che se non esiste lo crea o non lo crea e che se esiste il contenuto preesistente viene perso
    //a = accodare
    punt = fopen("esempio.dat", ""); //APERTURA FILE
    if (punt != NULL) //per verificare che il file sia stato aperto con successo
    {
         //C'è tutta la logica di gestione del file...
         cout << "File aperto con successo" <<endl;
         fclose(punt); //CHIUSURA FILE - ricordare di metterlo sempre
    }
    else {
    cout << "Errore nell'apertura del file";
    }
    //se nel debugger con r viene fuori in punt 0x0 questo significa che non trova il file e che non viene creato, non dovrebbero esserci molti caratteri, questo perché r non crea file
    //anche w puo dare 0x0 nel caso che il file sia in sola lettura o cmq che non è riuscito ad aprire il file in scrittura
    return 0;

*/

void pathTaker(char path[]){

    cout << "Insert the file path: ";
    cin.ignore(); // Ignora eventuali caratteri lasciati in ingresso standard
    cin.getline(path, MAXPATH); // Acquisisce il percorso del file come input

    pathVerifier(path);

}
//1. Prende la lettera -> La mette in una variabile -> la trasforma -> cancella la lettera presa in precedenza -> rimpiazza con la versione criptatata ($)

bool pathVerifier(char path[]){
    FILE *punt = fopen(path, "r+");
    if(punt != NULL){
        cout << "Succesfully opened the file" <<endl;
        return true;
    }else{
        cout << "Error the file dosen't exist!" <<endl;
        return false;
    }
}


/*
1. Controlla prima tutte le lettere [ X ]
2. Fa la conversione su una copia prima se senza errori [ ]
*/

/* Al momento non funzionate

int charTaker(char path[]) {
    // Apri il file in modalità lettura
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        cout << "Errore nell'apertura del file!" << endl;
        return 1; // Restituisce un errore se il file non può essere aperto
    }

    char c;
    // Leggi ogni carattere fino alla fine del file
    while ((c = fgetc(file)) != EOF) {
        // Stampa il carattere letto (puoi modificarlo per memorizzarlo altrove)
         cout << (char)c;
    }

    fclose(file); // Chiudi il file dopo averlo letto
    return 0; // Successo
}

*/