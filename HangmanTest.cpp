#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


/* Notes:
    It's a bit of a self-compromising program since you're typing in the answer yourself lol
    Still very fun to code and figure out as my first real C++ project.
*/

int main() {

    string word;
    int attempts = 6;
    bool valid = true;
    bool loopOn = true;

    cout << "=========HANGMAN=========";

    // The game keeps asking the writer to enter a valid word, composed of up to 20 letters.
    // The loop repeats if the writer keeps entering invalid strings.
    while (loopOn == true) {
        // Ask for the word to be guessed.
        cout << "\nType out the word that will be guessed.\nPlease use up to 20 letters only, no spaces.\n";
        cin >> word;

        // Prompt the writer to try again if they exceed 20 characters.
        //cout << word.length();
        int length = word.length();
        if (length > 20) {
            cout << "\nThe word is too long. Please try again.\n";
            continue;
        }

        // Create a character array to which the string will be copied.
        // In addition to being used to compare letter guesses with,
        // we can also make sure that the guess word only contains letters.
        char wordArray[word.length()];
        strcpy(wordArray, word.c_str());

        // Iterate through the character array to check for non-letters.
        for (int i = 0; i < length; i++) {

            // Do nothing if the character is confirmed to be a letter.
            if (isalpha(wordArray[i])) {
            }
            // Change the boolean value to false if a non-letter is found.
            // This invalidates the string.
            else {
                valid = false;
            }
        }
        // If the string is invalid, loop back to request a new word.
        if (valid == false) {
            cout << "\nInvalid character(s) found. Please try again.\n";
            valid = true;
            continue;
        }
        // If the string is valid, break the loop.
        else {
            loopOn = false;
            break;
        }
    };

    // Redeclare the word array to reference it later.
    char wordArray[word.length()];
    strcpy(wordArray, word.c_str());
    //cout << sizeof(wordArray);

    // Then, make a guess array full of blanks.
    // This array will be filled in periodically as correct guesses are made.
    char guessArray[word.length()];
    for (int i = 0; i < word.length(); i++)
    {
        guessArray[i] = '*';
    }

    loopOn = true;
    cout << "\n=========GAME ON!=========";

    // Once the word has been validated, start taking guesses.
    string guess;


    while (loopOn == true) {
        // Ask for a guess.
        cout << "\nPlease enter a guess: ";
        cin >> guess;

        // Ensure the guess is one character long.
        if (guess.length() != 1) {
            cout << "The guess is invalid. Please try again.";
            continue;
        }

        char guessChar[1];
        strcpy(guessChar, guess.c_str());
        //cout << guessChar[0] << "\n\n";

        // Ensure the guess is one letter.
        if (isalpha(guessChar[0]) == 0) {
            cout << "The guess is invalid. Please try again.";
                continue;
        }

        bool match = false;

        // Check if the letter is in the word.
        // First, iterate through the word array.
        // If the guess matches up with any letters in the word array, replace them in their
        // respective positions in the guest array.
        for (int i = 0; i < word.length(); i++) {


            if (wordArray[i] == guessChar[0] || toupper(wordArray[i]) == toupper(guessChar[0]))
            {
                guessArray[i] = guessChar[0];
                match = true;
            }
        }



        // Decrease remaining attempts for each incorrect guess.
        // End the game once six incorrect guesses have been made.
        if (match == false) {
            attempts--;
            cout << "\nThe letter wasn't found!\nRemaining attempts: " << attempts;

            if (attempts == 0) {
                cout << "\n\nGame over! The word was [" << word << "].\n\n";
                break;
            }

            continue;
        }
        // Otherwise, indicate that the letter was found and
        // print the guess array for reference.
        else {
            bool complete = true;
            cout << "\nThe letter was found!\nWord: " << guessArray;

            // Check the guess array to see if all asterisks were removed,
            // which indicates every letter was found.
            // End the game after making congratulations.
            for (int i = 0; i < word.length(); i++) {
                if (guessArray[i] == '*') {
                    complete = false;
                }
            }
            if (complete == false) {
                continue;
            }
            else {
                loopOn = false;
                cout << "\n\nCongratulations! The word was [" << word << "].\n\n";
                break;
            }
        }

    }

    return (0);
}
