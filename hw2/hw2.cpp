#include <iostream>
#include <random>
#include <string>
using namespace std;



void askQuestion(int difficulty, int& score) {
    try {
        int answer;
        cout << generateRandomQuestion(difficulty) << endl;
        cin >> answer;
        if(cin.fail()) {
            throw runtime_error("Invalid input - must be a number!");
        }
        
        bool isCorrect = (answer == currentCorrectAnswer);
        cout << (isCorrect ? "Correct!" : "Wrong! " + insultPlayer()) << endl;

        if (isCorrect) {
            score++;
        }
    }
    catch(const runtime_error& e) {
        cout << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void askQuestion(string topic, int difficulty, int& score) {
    cout << "also asking question";
    
}


void startQuiz(std::string playerName, int difficulty = 1) {
    
    int totalQuestions = 3;
    int score;
    string topic = "foo";
    int completed = 0;

    cout << "Stewie: Alright, " << playerName << ", let's see how smart you really are!" << endl;

    do {
        askQuestion(difficulty, score);
        completed += 1;
    } while (completed < 3); 

    cout << "You got " << score << "/" << totalQuestions << " correct!" << endl;
    cout << "Stewie: " << (isPassing(score) ? "Fine, you win this round..." : "Ha! As expected!") << endl;
}


inline string insultPlayer() {  // Changed return type to string
    const int NUM_INSULTS = 6;
    string insults[NUM_INSULTS] = {
        "I hope you're joking...", 
        "You buffoon!",
        "This is the second worst thing I've seen today...",
        "You've convinced me you have the brain of a 10 year old...",
        "Booo, booo! I'm booing you!",
        "Oh, how predictably mediocre!"
    };
    
    return insults[rand() % NUM_INSULTS]; 
}

template <typename T>


bool isPassing(T correctAnswers) {
    return correctAnswers >= 2;
}


void gameMenu() {

    string playerName;
    char selection;
    cin >> selection;
    cout << "Choose a Character!: \n";

    cout << "1. Peter \n";
    cout <<  "2. Lois \n";
    cout << "3. Meg \n";
    cout << "4. Chris \n";
    cout << "5. Brian \n";
    cout << "6. Stewie \n";
    cout << "7. Exit \n";
    
    switch (selection) {
        case '1':
            startQuiz("Peter", 1);
            playerName = "Peter";
            break;
        case '2':
            startQuiz("Lois", 2);
            playerName = "Lois";
            break;
        case '3':
            startQuiz("Meg", 3);
            playerName = "Meg";
            break;
        case '4':
            startQuiz("Chris", 4);
            playerName = "Chris";
            break;
        case '5':
            startQuiz("Brian", 5);
            playerName = "Brian";
            break;
        case '6':
            startQuiz("Stewie", 6);
            playerName = "Stewie";
            break;
        case '7':
            break;
        default:
            break;
    }
}

int currentCorrectAnswer = 0;

int generateRandomQuestion(int difficulty) {
    // maybe take a random number from 0 -> 9 and mult by difficulty for the numbers?
    
    difficulty = 1;

    int num1 = (rand() % 10) * difficulty;
    int num2 = (rand() % 10) * difficulty;

    int operation = 0; // 0 addition, 

    string question;

    if (operation == 0) {
        question = to_string(num1) + " + " + to_string(num2) + " = ?";
    }

    currentCorrectAnswer = num1 + num2;
    return question;
}


int main() {
    srand(37); // set the random seed
    int score;
    gameMenu();

    return 0;
}
