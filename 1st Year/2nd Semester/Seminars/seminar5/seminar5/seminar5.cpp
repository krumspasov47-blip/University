#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    /* 1 Haralampi wants to organise his birthday party. He needs to buy inventory:
    Chair - 13.99, Table for 8 people - 42.00, set of 6 cups - 5.98, set of 6 dishes with cutlery - 21.02
    Read the number of guests from the keyboard. Then read lines of items he has already bought
    until the command PARTY! is entered. Calculate how much money he has spent and how many more
    items he still needs so every guest has a chair, a seat at a table and a cup and cutlery.

    int guests;
    printf("Guests: ");
    scanf("%d", &guests);

    FILE* fptr = fopen("items.txt", "w");
    if (fptr == NULL) {
        printf("Could not open file for writing.\n");
    }

    char text[100];
    while (1) {
        scanf("%s", text);
        if (strcmp(text, "PARTY!") == 0)
            break;
        fprintf(fptr, "%s\n", text);
    }
    fclose(fptr);

    fptr = fopen("items.txt", "r");
    if (fptr == NULL) {
        printf("Not able to open the file.\n");
    }

    char myString[100];
    int tables = 0, chairs = 0, cups = 0, dishes = 0;

    while (fgets(myString, 100, fptr)) {
        myString[strcspn(myString, "\n")] = 0;

        if (strcmp(myString, "Table") == 0)
            tables++;
        else if (strcmp(myString, "Chair") == 0)
            chairs++;
        else if (strcmp(myString, "Cups") == 0)
            cups++;
        else if (strcmp(myString, "Dishes") == 0)
            dishes++;
    }
    fclose(fptr);

    float price = 0;


    int tablesNeeded = (int)ceil((float)guests / 8) - tables;
    int chairsNeeded = guests - chairs;
    int cupsNeeded = (int)ceil((float)guests / 6) - cups;
    int dishesNeeded = (int)ceil((float)guests / 6) - dishes;

    if (tablesNeeded > 0)  price += tablesNeeded * 42.00f;
    if (chairsNeeded > 0)  price += chairsNeeded * 13.99f;
    if (cupsNeeded > 0)    price += cupsNeeded * 5.98f;
    if (dishesNeeded > 0)  price += dishesNeeded * 21.02f;

    printf("%.2f\n", price);

    if (tablesNeeded > 0)  printf("%d Table\n", tablesNeeded);
    if (chairsNeeded > 0)  printf("%d Chairs\n", chairsNeeded);
    if (cupsNeeded > 0)    printf("%d Cups\n", cupsNeeded);
    if (dishesNeeded > 0)  printf("%d Dishes\n", dishesNeeded);

    char filename[100];
    int  key;

    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter key (2-10): ");
    scanf("%d", &key);

    if (key < 2 || key > 10) {
        printf("Key must be between 2 and 10.\n");
        return 1;
    }
    */

    /* 2 Write a program for the computer game "Hangman". The player is shown the length
    of a word (represented by underscores) and tries to guess it by entering letters.
    Each time a new letter is entered the program checks if the word contains it.
    If it does the letter is revealed in its position(s). The player wins if they guess
    the word with a number of entered letters no more than the length of the word + 2.
    Example: if the word is "concatenation" the number of letters entered must be <= 15.

    char secret[MAX_WORD] = "concatenation";
    int  len = strlen(secret);
    char display[MAX_WORD];
    char guessed[MAX_WORD];
    int  guessed_count = 0;
    int  solved = 0;
    char letter;

    for (i = 0; i < len; i++) display[i] = '_';
    display[len] = '\0';
    guessed[0]   = '\0';

    printf("Word: %s (%d letters)\n", display, len);
    printf("You have %d guesses.\n", len + 2);

    while (guessed_count <= len + 2 && !solved)
    {
        printf("Enter letter: ");
        scanf(" %c", &letter);

        int already = 0;
        for (i = 0; i < guessed_count; i++)
            if (guessed[i] == letter) { already = 1; break; }
        if (already) { printf("Already guessed.\n"); continue; }

        guessed[guessed_count++] = letter;

        int found2 = 0;
        for (i = 0; i < len; i++)
            if (secret[i] == letter) { display[i] = letter; found2 = 1; }

        if (!found2) printf("Not in word.\n");
        printf("%s\n", display);

        solved = (strcmp(display, secret) == 0);
    }

    if (solved)
        printf("You win! The word was: %s\n", secret);
    else
        printf("You lose! The word was: %s\n", secret);
    */

    /* 3 Write a program that encodes the contents of a text file character by character
    using a key entered by the user and saves the encoded content to another file.
    The key is a whole number between 2 and 10. The name of the file to encode is read
    from the keyboard. (Caesar-style shift cipher)

    char filename[MAX_STR], outname[MAX_STR];
    int  key;
    char ch;

    printf("Enter filename: ");  scanf("%s", filename);
    printf("Enter key (2-10): "); scanf("%d", &key);

    // build output filename: add "_encoded" before extension
    strcpy(outname, "encoded_");
    strcat(outname, filename);

    FILE *fin2  = fopen(filename, "r");
    FILE *fout2 = fopen(outname, "w");

    while ((ch = fgetc(fin2)) != EOF)
        fputc(ch + key, fout2);

    fclose(fin2);
    fclose(fout2);
    printf("Encoded file saved as: %s\n", outname);
    */
    return 0;
}