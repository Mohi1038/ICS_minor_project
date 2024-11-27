#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// MACROS
#define MAX_TRIES 6   // Maximum tries for user to guess
#define MAX_LENGTH 60 // Maximum length of word

// Using file handling to choose random word from file
void chooseRandomWord(char *word)
{
    // opening the file of words
    FILE *file = fopen("medium_words.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int numWords = 0;
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        numWords++;
    }

    fseek(file, 0, SEEK_SET);

    srand((unsigned int)time(NULL));
    int randomIndex = rand() % numWords;

    int i;
    for (i = 0; i <= randomIndex; i++)
    {
        if (fgets(word, sizeof(line), file) == NULL)
        {
            fprintf(stderr, "Error: Failed to read word from file.\n");
            exit(EXIT_FAILURE);
        }
    }

    int len = strlen(word);
    if (word[len - 1] == '\n')
    {
        word[len - 1] = '\0';
    }
    fclose(file);
}

// drawing hangman
void drawmyhangman(int wrong_guess)
{
    switch (wrong_guess)
    {
    case 0:
        printf("\n\n");
        break;
    case 1:
        printf("\n\n\n\n");
        printf("   ___\n");
        printf("  |   |\n");
        printf("  |   O\n");
        break;
    case 2:
        printf("\n\n\n");
        printf("   ___\n");
        printf("  |   |\n");
        printf("  |   O\n");
        printf("  |   |\n");
        break;
    case 3:
        printf("\n\n\n");
        printf("   ___\n");
        printf("  |   |\n");
        printf("  |   O\n");
        printf("  |  /|\n");
        break;
    case 4:
        printf("\n\n\n");
        printf("   ___\n");
        printf("  |   |\n");
        printf("  |   O\n");
        printf("  |  /|\\\n");
        break;
    case 5:
        printf("\n\n\n");
        printf("   ___\n");
        printf("  |   |\n");
        printf("  |   O\n");
        printf("  |  /|\\\n");
        printf("  |  /\n");
        break;
    case 6:
        printf("\n\n\n");
        printf("   ___\n");
        printf("  |   |\n");
        printf("  |   O\n");
        printf("  |  /|\\\n");
        printf("  |  / \\\n");
        break;
    default:
        break;
    }
}

int main()
{
    char secretword[MAX_LENGTH];
    char guessword[MAX_LENGTH];
    char guessedletter[MAX_LENGTH];

    chooseRandomWord(secretword);

    int word_length = strlen(secretword);

    int i;
    for (i = 0; i < word_length; i++)
    {
        guessword[i] = '_';
    }
    guessword[word_length] = '\0';

    printf("Welcome to the HANGMAN GAME!!\n");
    printf("Save the man from hanging by guessing the correct word.\n");

    int wrong_guess = 0;

    while (wrong_guess < MAX_TRIES)
    {
        printf("\nCurrent word: %s\n", guessword);
        printf("Incorrect guesses left: %d\n", MAX_TRIES - wrong_guess);

        char guess;
        printf("Enter a letter:");
        // taking input from the user
        scanf(" %c", &guess);

        // it convert Capital letter to lower case
        if (guess >= 'A' && guess <= 'Z')
        {
            guess += ('a' - 'A');
        }

        int alreadyGuessed = 0;
        for (i = 0; i < strlen(guessedletter); i++) // says thay letter is already gussed
        {
            if (guessedletter[i] == guess)
            {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed)
        {
            printf("You already guessed that letter.\nTry again...\n");
            continue;
        }

        guessedletter[i] = guess;
        guessedletter[i + 1] = '\0';



        int found = 0;
        for (i = 0; i < word_length; i++)
        {
            if (secretword[i] == guess)
            {
                guessword[i] = guess;
                found = 1;
            }
        }

        if (!found)
        {
            wrong_guess++;
            printf("Wrong guess!! \nSave him, bro.\nTry again...\n");
        }
        else
        {
            printf("Correct guess!!\n");
        }

        drawmyhangman(wrong_guess); // drawing the hangman for each wrong guess

        int wordGuessed = 1;
        for (i = 0; i < word_length; i++)
        {
            if (guessword[i] != secretword[i])
            {
                wordGuessed = 0;
                break;
            }
        }

        if (wordGuessed)
        {
            printf("Congratulations! You guessed the word: %s\n", secretword);
            printf("Hurray!! You saved the man.\n");
            break;
        }
    }

    if (wrong_guess == MAX_TRIES)
    {
        printf("Sorry, you ran out of attempts.\n The correct word was: %s\n", secretword);
        printf("Alas!! Now, cry with me.\n");
    }
    return 0;
}
