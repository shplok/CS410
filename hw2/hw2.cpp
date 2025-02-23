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
        // Use ternary operator for feedback as required:
        cout << (answer == correctAnswer ? "Correct!" : "Wrong! " + insultPlayer());
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
    
    int completed = 0;
    int score;
    string topic = "foo";

    do {
        askQuestion(topic, difficulty, &score);
        completed += 1;
    } while (completed < 3); 
}


inline void insultPlayer() {

    string insultLst[6] = {
        "I hope you're joking..", 
        "You buffoon!",
        "This is the second worst thing I've seen today...",
        "You've convinced me you have the brain of a 10 year old, though Herbert might take more convincing",
        "booo, booo! I'm booing you",
        "Insult"};
        int randomSelection = rand() % insultLst->size();
    cout << insultLst[randomSelection] << "\n";
}


template <typename T>


bool isPassing(T correctAnswers) {
    return true if correctAnswers >= 2 else false;
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


int generateRandomQuestion(int difficulty) {
    // maybe take a random number from 0 -> 9 and mult by difficulty for the numbers?
    int seed = 37;
    
    srand(seed);
    
}


int main() {
    int score;
    gameMenu();

    return 0;
}
