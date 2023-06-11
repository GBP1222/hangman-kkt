#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
string words[] = {
        "Elephant", "Sunshine", "Butterfly", "Mountain", "Rainbow",
        "Guitar", "Pizza", "Dragon", "Universe", "Chocolate",
        "Computer", "Laptop", "Keyboard", "Mouse", "Monitor",
        "Internet", "Programming", "Algorithm", "Database", "Software",
        "Artificial", "Intelligence", "Machine", "Learning", "Robot",
        "Science", "Physics", "Chemistry", "Biology", "Astronomy",
        "Music", "Dance", "Theater", "Painting", "Sculpture",
        "Poetry", "Literature", "History", "Geography", "Mathematics",
        "Football", "Basketball", "Baseball", "Tennis", "Swimming",
        "Cycling", "Running", "Hiking", "Yoga", "Meditation",
        "Beach", "Mountain", "Forest", "Desert", "Waterfall",
        "Coffee", "Tea", "Juice", "Smoothie", "Milkshake",
        "Pizza", "Burger", "Sushi", "Pasta", "Ice Cream",
        "Dog", "Cat", "Bird", "Fish", "Rabbit",
        "Elephant", "Lion", "Tiger", "Giraffe", "Monkey",
        "Rain", "Sun", "Wind", "Snow", "Cloud",
        "Love", "Happiness", "Friendship", "Peace", "Hope",
        "Adventure", "Dream", "Success", "Inspiration", "Courage",
        "Family", "Home", "Travel", "Laughter", "Smile",
        "Book", "Movie", "Music", "Game", "Art"
};
string hangmanPics[] = {
        R"('''
      +---+
      |   |
      O   |
     /|   |
          |
          |
    =========''')",
        R"('''
      +---+
      |   |
      O   |
     /|\  |
          |
          |
    =========''')",
        R"('''
      +---+
      |   |
      O   |
     /|\  |
     /    |
          |
    =========''')",
        R"('''
      +---+
      |   |
      O   |
     /|\  |
     / \  |
          |
    =========''')"
};
bool checkIf(char* b, char letter, int length) {
    for (int i = 0; i < length; i++) {
        if (tolower(b[i]) == tolower(letter)) {
            return true;
        }
    }
    return false;
}
int main() {
    srand(time(nullptr));
    char letter, b[100], c[100];
    string a;
    bool found = false;
    int tries = 0;

    a = words[rand() % 100];
    int wordLength = a.length();
    strcpy(b, a.c_str());

    for (int i = 0; i < wordLength; i++) {
        c[i] = '_';
    }

    while (!found) {
        cout << "Guess a letter: ";
        cin >> letter;
        letter = tolower(letter);
        if (checkIf(b, letter, wordLength)) {
            for (int i = 0; i < wordLength; i++) {
                if (tolower(b[i]) == letter){
                    c[i] = a[i];
                }
            }
        }else{
            tries++;
            cout << hangmanPics[tries - 1] << endl;

            if (tries == 6) {
                cout << "You lost! The word was: " << a << endl;
                break;
            }
        }

        cout << "Current word: ";
        for (int i = 0; i < wordLength; i++) {
            cout << c[i] << " ";
        }
        cout << endl;

        if (strcmp(b, c) == 0) {
            cout << "Congratulations! You guessed the word correctly." << endl;
            found = true;
        }
    }

    return 0;
}
