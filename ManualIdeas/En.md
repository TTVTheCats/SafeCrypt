### Introduction
Text to encrypt: Ciao Bro

### Variables 
- Q = Encrypted letter
- Y = Key
- X = Real letter (Not encrypted)
***
The key can be generated randomly or chosen by the user (It must contain alphanumeric characters and be at least 7 characters long).

Alphabet (NOT USED TO COMPLICATE, used to make usage smoother for the user)
(The values of the letters will be much longer, for example, C = 347593297659)
- C = 43654
- i = 35639
- a = 43280
- o = 13737
- B = 15839
- r = 20573
- o = 28500
- \<Space\> = 10001

User 1 = `82390483094820934820948`  
User 2 = `13Cia76` -> `1343654356394328076` (The password `13Cia76` is used for user simplicity, but they could also use `1343654356394328076`)
***
## Encryption
1. `Q = X * Y` (X is an array of chars, Q can be a float/double but will never have a decimal point)

### Practical Calculation
- Q1 = `43654` * `1343654356394328076` = `58655887274037997829704`
- Q2 = `35639` * `1343654356394328076` = `47886497607537458300564`
- Q3 = `43280` * `1343654356394328076` = `58153360544746519129280`
- Q4 = `13737` * `1343654356394328076` = `18457779893788884780012`
- Q5 = `10001` * `1343654356394328076` = `13437887218299675088076`
- Q6 = `15839` * `1343654356394328076` = `21282141350929762395764`
- Q7 = `20573` * `1343654356394328076` = `27643001074100511507548`
- Q8 = `28500` * `1343654356394328076` = `38294149157238350166000`
***
### Write to file

- Option 1 = `Q1$Q2$Q3$...`   (Best)
- Option 2 = `$Q1$$Q2$$Q3$...`
- Option 3 = `$Q1$Q2$Q3$...`

### Practical Example
- Final Message/File  
`58655887274037997829704$47886497607537458300564$58153360544746519129280$18457779893788884780012$13437887218299675088076$21282141350929762395764$27643001074100511507548$38294149157238350166000`
***
## Decryption

Variable [5,8,6,5,8,7,2,7,4,0,3,7,9,9,7,8,2,9,7,0,4] merges the content and places it in another variable that will contain
`58655887274037997829704`, which can then be divided by Y to obtain X and thus retrieve the letter.

## GPT Code Idea
[Code](https://chatgpt.com/share/f12a4795-33f5-4b05-a10c-a3062da08262)  (It does what is written in ### Decryption)
