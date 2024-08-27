### Introduzione
Testo da criptare : Ciao Bro
### Variabili
- Q = Lettera criptata
- Y = Key
- X = Lettera reale (Non criptata)
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
