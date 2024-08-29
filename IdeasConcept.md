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

ASCII Numbers
28467, 39213, 24987, 45531, 30874, 46729, 24156, 36518, 47211, 43429,
38845, 24390, 32761, 42655, 29087, 37842, 23419, 30176, 42103, 48296,
28314, 40812, 34028, 25896, 47403, 39877, 37596, 34618, 46952, 26178,
35941, 40087, 23016, 37093, 45214, 28571, 49731, 33450, 39582, 26704,
48823, 21439, 46815, 28904, 38175, 40963, 24982, 49617, 30586, 46938,
27540, 38729, 44452, 31796, 40218, 24371, 46023, 49865, 37321, 27380,
35274, 27654, 32781, 39821, 26309, 45392, 41067, 42208, 33715, 47483,
35561, 41908, 25132, 49256, 24106, 48734, 47829, 27042, 37298, 23977,
49362, 43217, 38945, 45109, 28932, 36571, 25740, 43709, 40236, 26185,
31947, 49792, 27638, 31680, 37406, 30467, 24510, 49021, 21953, 28437,

Character = 12

Criptated Character = 12 * 580 (Key)

Result = 6960

***
## Criptazione Fase 1 Rivisitata
Key: 13Cia76

Key converted: 13123098121928341029476 (si taglia a metà e si creano le due key)

Key1: 13123098121
Key2: 928341029476


Frase: Fabriso 
F -> Key1
a -> Key1
b -> Key1
r -> Key2
i -> Key2
s -> Key1
o -> Key1

Changing frequence based on the 2° number of the Key#


Alfabet Idea MrTheCats

key: 8132947298342938423 (si taglia a metà e si creano le due key)

Key Key1 = 813294729
Key Key2 = 8342938423

A = 65 * 834293842

F -> (65 * 834293842)*813294729 = 44104240968824323170 == (X * Y2) * Y1

- Q = Lettera criptata prima fase
- Y = Key
- X = Lettera reale (Non criptata)
- C = Lettera criptata doppia fase