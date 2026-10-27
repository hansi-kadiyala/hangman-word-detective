
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void showTitle() {
    printf("\n");
    printf("========================================\n");
    printf("          HANGMAN: WORD DETECTIVE       \n");
    printf("========================================\n");
    printf("        EVERY LETTER IS A CLUE!\n");
    printf("----------------------------------------\n");
    printf("       Think smart. Solve the case.\n");
    printf("========================================\n\n");
}



#include <stdio.h>

void drawHangman(int lives) {
    printf("\n +---+\n");
    printf(" |   |\n");

    // Line 1: Head (lives <= 5)
    if (lives <= 5)
        printf(" O   |\n");
    else
        printf("     |\n");

    // Line 2: Torso (lives <= 4)
    if (lives <= 4)
        printf(" |   |\n");
    else
        printf("     |\n");

    // Line 3: Arms (Left arm at <= 3, Both arms at <= 2)
    if (lives <= 2)
        printf("/|\\  |\n");
    else if (lives <= 3)
        printf("/|   |\n");
    else
        printf("     |\n");

    // Line 4: Legs (Left leg at <= 1, Both legs at <= 0)
    if (lives <= 0)
        printf("/ \\  |\n");
    else if (lives <= 1)
        printf("/    |\n");
    else
        printf("     |\n");

    printf("=======\n");
}


int main() {
    srand(time(NULL));
    int randomIndex;
    
    showTitle();
    
    char word[50];
    char hiddenWord[50];

    
    int correct=0;
    int incorrect=0;
    int found=0;
    int lives = 6;
    
    printf("Lives remaining: %d\n",lives);
    int guessCount=0;
    char guessedLetters[26];
    char guess;
    int repeated=0;


    printf("Correct: 0 , Incorrect:0 \n ");

    int category;
    printf("Select the category \n");
    printf("1:Science & Technology \n");
    printf("2: Animals\n");
    printf("3: Food\n");
    printf("4: Random\n");
    printf("Enter your choice: \n");
    scanf("%d", &category);

    char science[10][20]={
        "ATOM","PLANETS","GRAVITY", "LASER", "PROTEIN","ROBOT", "COMPUTER", "CODING", "MOBILE", "INTERNET"
    };

    char animals[10][20]={
        "MONKEY","GIRAFEE","DONKEY","PANDA","TIGER","LION","ELEPHANT","KANGAROO","HORSE","ZEBRA"
    };

    char food[10][20]={
        "CHICKEN","PIZZA","PASTA","BURGER","SAMOSA","MILKSHAKE","NOODLES","DONUT","WAFFLE","SANDWICH"
    };

    char random[15][20]={
        "PLANT","BOTTLE","BREATHE","SUNSCREEN","BOOKS","EDUCATION","FLOWERS","CRICKET","ALMOND","PICTURE","SHADOW","IMPOSTER","LAUNDRY","UMBRELLA","CUPBOARD"
    };

    switch(category){
        case 1:
            printf("You choose science \n");
            randomIndex = rand() % 10;
            strcpy(word, science[randomIndex]);
            break;
        case 2:
            printf("You choose Animals\n");
            randomIndex = rand() % 10;
            strcpy(word, animals[randomIndex]);
            break;
        case 3:
            printf("You choose Food\n");
            randomIndex = rand() % 10;
            strcpy(word, food[randomIndex]);
            break;
        case 4:
            printf("You choose Random\n");
            randomIndex = rand() % 15;
            strcpy(word, random[randomIndex]);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        hiddenWord[i] = '_';
    }
    hiddenWord[len] = '\0';

    printf("Word: %s\n", hiddenWord);
    
    while(lives>0 && strcmp(hiddenWord,word)!=0){
        found=0;
        repeated=0;
        guess='\0';

        printf("Enter the letter you want to guess: \n");
        scanf(" %c", &guess);

        

        for(int j=0;j<guessCount;j++){
            if(guess==guessedLetters[j]){
                repeated=1;
            }
        }

        if(repeated==1){
            printf("Already guessed!");
        }
        else{
            guessedLetters[guessCount]=guess;
            guessCount++;

            for(int i=0;i<strlen(word);i++){
            
                if (word[i]==guess){
                    found =1;
                    hiddenWord[i]=guess;
                }
                
            }
            if(found==1){
                printf("You guessed right ! \n");
                printf("%.49s \n ",hiddenWord);
                correct++;
                printf("Correct: %d ,",correct);
                printf("InCorrect: %d\n",incorrect);
                printf("Lives remaining : %d\n",lives);
                
            }
            else if(found==0){
                printf("You guessed it WRONG ! \n");
                printf("%.49s",hiddenWord);
                incorrect++;
                printf("InCorrect: %d \n",incorrect); 
                printf("Correct: %d\n",correct);
                lives--;
                printf("Lives remaining: %d\n",lives);
                drawHangman(lives);
            }
            
            
        }
    
    }

    if (strcmp(hiddenWord, word) == 0) {
        printf("YOU WON!\n");
    }
    else {
        printf("YOU LOSE!\n");
        printf("The word was: %s\n", word);
    }
    

    

   
    
    return 0;
}

