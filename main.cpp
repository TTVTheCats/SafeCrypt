#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <conio.h>

#define MaxAlfabet 255 // Number of alphabet character supported
#define keyLenghtMAX 21 // Max key lenght supported

using namespace std;

void AlfabetGeneration(int Alfabet[]); // Function to generate the alpabet (BETA)
void KeyGenerator(char []); // Function to generate the key or make it choose at the u
void caricaStringa(char [], int); // Text like function to write in array of char
bool keyValidyCheck(char []);

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

    cout << "Chiave generata: " << key << endl;

    return 0;
}

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

void AlfabetGeneration(int Alfabet[]) {
    for(int i = 1; i <= MaxAlfabet; i++) {
        Alfabet[i] = i;
    }
}

void KeyGenerator(char key[]){
    
    char scelta;
    int randomValue;
    
    do{
        cin >> scelta;
        if (scelta !='y' && scelta != 'n'){ //Validation of y/n
            cout << "Error";
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
            caricaStringa(key, keyLenghtMAX); // Manual loading of the key by user
            //Messagio Errore

        }while(keyValidyCheck(key) == false);
    }
}

bool keyValidyCheck(char keyimport[]){
    bool validity = false;
    for(int i = 0; i < keyLenghtMAX; i++){
        if (keyimport[i] <= 32 || keyimport[i] == 34 || keyimport[i] == 39 || keyimport[i] == 40 || keyimport[i] == 41 || keyimport[i] == 44 || keyimport[i] == 45 || keyimport[i] == 58 || keyimport[i] == 59 || keyimport[i] == 96 || keyimport[i] >= 123 ){
            
        }else{
            validity = false;
        }
    }
    return 0;
} 

//Aggiungere variabili per conto numeri e lettere in key 
//MIN MAX caracter control