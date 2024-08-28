### Introduzione
Testo da criptare : Ciao Bro
### Variabili 
- Q = Lettera criptata prima fase
- Y = Key
- X = Lettera reale (Non criptata)
- C = Lettera criptata doppia fase
***
La key può essere generata randomicamente o può essere scelta dall'utente (Deve contenere carattere alfa numeri ed essere almeno di 7 parole).

Alfabeto (NON USATO PER COMPLICARE utilizzato per rendere utilizo piu scorrevole per l'utente)
(I valori delle lettere saranno molto più lunghi, per esempio C = 347593297659)
- C = 43654
- i = 35639
- a = 43280
- o = 13737
- B = 15839
- r = 20573
- o = 28500
- \<Spazio\> = 10001

Utente 1 = `82390483094820934820948`
Utente 2 = `13Cia76` -> `1343654356394328076` (La password `13Cia76` viene utilizzata per semplicità dell'utente, potrebe utilizzare anche `1343654356394328076`)
***
## Criptazione
1. `Q = X * Y` (X array di char, la Q può essere float/double ma non sarà mai con la virgola)

### Calc Pratico
- Q1 = `43654` * `1343654356394328076` = `58655887274037997829704`
- Q2 = `35639` * `1343654356394328076` = `47886497607537458300564`
- Q3 = `43280` * `1343654356394328076` = `58153360544746519129280`
- Q4 = `13737` * `1343654356394328076` = `18457779893788884780012`
- Q5 = `10001` * `1343654356394328076` = `13437887218299675088076`
- Q6 = `15839` * `1343654356394328076` = `21282141350929762395764`
- Q7 = `20573` * `1343654356394328076` = `27643001074100511507548`
- Q8 = `28500` * `1343654356394328076` = `38294149157238350166000`
***
### Scrivi nel file

- Option 1 = `Q1$Q2$Q3$...`   (Migliore)
- Option 2 = `$Q1$$Q2$$Q3$...`
- Option 3 = `$Q1$Q2$Q3$...`

### Pratica
- Messaggio/File finale
`58655887274037997829704$47886497607537458300564$58153360544746519129280$18457779893788884780012$13437887218299675088076$21282141350929762395764$27643001074100511507548$38294149157238350166000`
***
## Decriptazione

Variabile[5,8,6,5,5,8,8,7,2,7,4,0,3,7,9,9,7,8,2,9,7,0,4] unisce il contenuto e lo mette in un'altra variabile che conterrà quindi
`58655887274037997829704` che poi può essere divisa con Y per ottenere la X e ottenere così la lettera 

## GPT Code Idea
[Code](https://chatgpt.com/share/f12a4795-33f5-4b05-a10c-a3062da08262)  (Fa ciò che è scritto in ###Decriptazione)
***

## Seconda criptazione

Prende il secondo numero a partire dall'inizio della chiave principale, otteniamo il valore che rispecchia la quantità di volte che il codice crifrato 
viene scritto nel file prima di essere aggiunto al Q successivo un valore, il valore aggiunto sarà la Y1 ovvero la seconda chiave generata in base alla
prima chiave, per determinare quante volte viene aggiunto il valore prima di tornare a stampare senza aggiungere, bisogna prelevare un'altro numero
per esempio il quarto a partire dalla fine della prima key, e quel valore determinerà per quante volte continuerà a sommare prima di tornare
come all'inizio (se il valore è 0 si scala al valore dopo).

Esempio:

Secondo numero a partire dall'inizio = 2.
Quarto numero a partire dalla fine = 5.

Stampo i primi due Q nel file 58655887274037997829704$47886497607537458300564$ A quello che dovebbe essere qui stampato normalmente ovvero: 58153360544746519129280
aggiungo il valore della key secondaria generata in base a quella primaria (Y1 = 34565234785) al valore della Q che doveva essere stampata:
quindi verrà 58153360544746519129280 + 34565234785 = 58153360544781084364065, e poi stamperà questo valore e continerà ad aggiungere Y1 per 5 volte
ovvero il quarto numero a partire dalla fine.

## Alfabeto Afanzato

Testo: Ciao Bro
Key: 13Cia76

Estrai, ad esempio, il 2°, 4° e 6° carattere del file: i - o - B

Fatto si trasformano i caratteri in valori ASCII quindi: i = 105 - o = 111 - B = 66

Combina questi valori con i primi tre valori numerici della chiave: 1 - 3 - 7

A = i + 1 = 105 + 1 = 106
B = o + 3 = 111 + 3 = 114
C = B + 4 = 66 + 7 = 73

C = 73
K = 3 (K è un valore costante)
M = 256 (M è il modulo, che rappresenta il valore massimo che può essere assegnato a una lettera)

Formula Generica: Lettera = (Valore Lettera Precedente × K) + (Posizione in Alfabeto × Elemento da Chiave) modM

D = (73 × 3) + (4 × 7) mod256 - D = (219 + 28) mod256 = 91
E = 

Questi risultati potrebbero poi essere moltiplicati o ulteriormente trasformati secondo un algoritmo specifico che scegli, rendendo i valori più unici.


