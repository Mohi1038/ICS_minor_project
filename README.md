# ICS_minor_project

# HANGMAN GAME

This is a simple implementation of the classic Hangman game in C. The game randomly selects a word from a provided file and challenges the player to guess the word by inputting letters. The player has a limited number of attempts to guess the word before the hangman is fully drawn, signifying game over.

# HOW TO PLAY:

1) Clone the repository to your local machine.
2) Compile the code using a C compiler.
3) Run the executable file.
4) Follow the prompts to guess letters and save       the hangman from being hanged.

# LIBRARIES USED:

1) stdio.h: Standard input-output library for basic input and output operations.
2) stdlib.h: Standard library for memory allocation, random number generation, etc.
3) string.h: String manipulation library for string-related functions.
4) time.h: Time library for generating a seed for random number generation.

# FEATURES:

1) Random Word Selection: The game selects a random word from a file containing a list of words.
2) Visual Hangman: As the player makes incorrect guesses, a visual representation of the hangman is displayed.
3) Limited Attempts: The player has a maximum number of attempts to guess the word before the game ends.
4) Input Validation: The program validates user input to ensure it is a valid letter.
5) Word Completion: If the player successfully guesses the word within the allowed attempts, the game ends with a victory message.
6) Game Over: If the player exhausts all attempts without guessing the word correctly, the game ends, revealing the correct word.

# FILE STRUCTURE:

1) hangman.c: Contains the C source code for the Hangman game.
2) medium_words.txt: A text file containing a list of words from which the game randomly selects one.


# CONTRIBUTING:
 
 b23cs1038@iitj.ac.in
