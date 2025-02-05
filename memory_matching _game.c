#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include <string.h>

#define LEVEL1_LENGTH 5
#define LEVEL2_LENGTH 7
#define LEVEL3_LENGTH 9
#define ROUNDS 5  
#define SYMBOLS "!@#$%^&*?{}[]" 
int i;
int round;


char generate_random_char() {
    if (rand() % 2 == 0) {
        return '0' + (rand() % 10);  
    } else {
        return SYMBOLS[rand() % (sizeof(SYMBOLS) - 1)];  
    }
}


void generate_sequence(char *seq, int length) {
    for ( i = 0; i < length; i++) {
        seq[i] = generate_random_char();
    }
    seq[length] = '\0';  
}


void display_sequence(char *seq, int length) {
    printf("Memorize this sequence:\n");
    for ( i = 0; i < length; i++) {
        printf("%c ", seq[i]);
    }
    fflush(stdout);  
    sleep(5);  
}


void clear_screen() {
    printf("\nTime's up! Clearing the screen...\n");
    sleep(2);  
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

int main() {
    srand(time(0));  
    int score = 0;
    int length;

    for ( round = 1; round <= ROUNDS; round++) {
        
        if (round <= 2) {
            length = LEVEL1_LENGTH; 
        } else if (round <= 4) {
            length = LEVEL2_LENGTH; 
        } else {
            length = LEVEL3_LENGTH; 
        }

        char sequence[length + 1];  
        char user_input[length + 1];

        generate_sequence(sequence, length);

        
        printf("\n--- Round %d ---\n", round);
        display_sequence(sequence, length);

        clear_screen();

        printf("Enter the sequence from memory: ");
        scanf("%s", user_input);

        
        if (strcmp(user_input, sequence) == 0) {
            printf("?? Correct!\n");
            score++;
        } else {
            printf("? Incorrect. The correct sequence was: %s\n", sequence);
        }
    }

    
    printf("\nGame Over! Your final score: %d/%d\n", score, ROUNDS);
    return 0;
}
