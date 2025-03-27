#include <iostream>
#include <random>
#include <string>
#include <limits>
using namespace std;

// forward declaration of functions
void insultPlayer();
int generateRandomQuestion(int difficulty);
template <typename T>
bool isPassing(T correctAnswers);

// global variables to store generated numbers for questions
int generatedNum1 = 0;
int generatedNum2 = 0;
int totalQuestions = 0;

// function to ask a math question based on difficulty level and update the score
void askQuestion(int difficulty, int& score) {
    try {
        int answer;
        // generate a random question based on difficulty
        int currentCorrectAnswer = generateRandomQuestion(difficulty);

        // format the question as addition of two numbers
        string question = to_string(generatedNum1) + " + " + to_string(generatedNum2);
        cout << "What is " << question << " > ";
    
        // get user input for answer
        cin >> answer;
        // validate that input is a number
        if(cin.fail()) {
            throw runtime_error("Invalid input - must be a number!");
        }
        
        // check if answer is correct
        bool isCorrect = (answer == currentCorrectAnswer);
        cout << (isCorrect ? "Correct!" : "Wrong! ");
        
        // insult player if they got it wrong
        if (!isCorrect) {
            insultPlayer();
        }
        
        cout << endl;

        // increase score for correct answers
        if (isCorrect) {
            score++;
        }
    }
    // error handling for invalid inputs
    catch(const runtime_error& e) {
        cout << e.what() << endl;
        // clear input stream error flags
        cin.clear();
        // discard remaining input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// overloaded function with topic parameter to ask questions from different topics
void askQuestion(string topic, int difficulty, int& score) {
   
    // variables for topic selection and answer handling
    int topChoice;
    int answer;
    int currentCorrectAnswer = generateRandomQuestion(difficulty);

    // display topic menu
    cout << "Please Choose a Topic: " << '\n' << endl;
    cout << "1. Maths";
    cout << "2. History" << endl;
    cout << "3. Geography" << endl;
    cout << "> ";
    cin >> topChoice;
    
    // process based on selected topic
    switch (topChoice) {
        case '1':
            try {
                int answer;
                // generate a new question for math topic
                int currentCorrectAnswer = generateRandomQuestion(difficulty);
        
                // format question as addition
                string question = to_string(generatedNum1) + " + " + to_string(generatedNum2);
                cout << "What is " << question << " > ";
            
                // get and validate user answer
                cin >> answer;
                if(cin.fail()) {
                    throw runtime_error("Invalid input - must be a number!");
                }
                
                // check correctness and provide feedback
                bool isCorrect = (answer == currentCorrectAnswer);
                cout << (isCorrect ? "Correct!" : "Wrong! ");
                
                // insult for wrong answers
                if (!isCorrect) {
                    insultPlayer();
                }
                
                cout << endl;
        
                // update score for correct answers
                if (isCorrect) {
                    score++;
                }
            }
            // handle input errors
            catch(const runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        case '2':
            // todo: history questions implementation
            return;
        case '3':
            // todo: geography questions implementation
            return;
        default:
            return;
    }       
    // recursive call to continue asking questions
    askQuestion(difficulty, score);
}

// function to start the quiz with player name and difficulty setting
void startQuiz(string playerName, int difficulty) {
    // initialize quiz variables
    int targetCorrectAnswers = 3;
    int score = 0;

    totalQuestions = 0;

    // stewie's greeting message
    cout << "Stewie: Alright, " << playerName << ", let's see how smart you really are!" << endl;

    // loop to ask questions until 3 correct answers
    do {
        askQuestion(difficulty, score);
        totalQuestions += 1;
    } while (score < targetCorrectAnswers);

    // display final score
    cout << "You got " << score << "/" << totalQuestions << " correct!" << endl;
    
    // final message based on pass/fail status using the isPassing template function
    cout << "Stewie: " << (isPassing(score) ? "Fine, you win this round..." : "Ha! As expected!") << endl;
}

// function to display a random insult when player answers incorrectly
inline void insultPlayer() {
    // array of possible insults
    const int NUM_INSULTS = 6;
    string insults[NUM_INSULTS] = {
        "I hope you're joking...", 
        "You buffoon!",
        "This is the second worst thing I've seen today...",
        "You've convinced me you have the brain of a 10 year old...",
        "Booo, booo! I'm booing you!",
        "Moron!"
    };
    // select and display a random insult
    cout << insults[rand() % NUM_INSULTS];
}

// template function to check if player passed the quiz
template <typename T>
bool isPassing(T correctAnswers) {
    // pass threshold is 2 correct answers
    return ((double)correctAnswers / totalQuestions >= 0.5);
}

// function to generate random numbers for questions based on difficulty
int generateRandomQuestion(int difficulty) {
    // generate two random numbers scaled by difficulty
    generatedNum1 = rand() % (difficulty * 10);
    generatedNum2 = rand() % (difficulty * 5);
    
    // return the sum as the correct answer
    return generatedNum1 + generatedNum2;
}

// function to display the main game menu and handle character selection
void gameMenu() {
    // variables for player choice
    string playerName;
    char selection;
    
    // display character selection menu
    cout << "Choose a Character!: " << endl;
    cout << "1. Peter" << endl;
    cout << "2. Lois" << endl;
    cout << "3. Meg" << endl;
    cout << "4. Chris" << endl;
    cout << "5. Brian" << endl;
    cout << "6. Exit" << endl;
    cout << "> ";
    
    // get player selection
    cin >> selection;
    
    // process based on selected character
    switch (selection) {
        case '1':
            playerName = "Peter";
            // start quiz with difficulty 1
            startQuiz(playerName, 1);
            break;
        case '2':
            playerName = "Lois";
            // start quiz with difficulty 2
            startQuiz(playerName, 2);
            break;
        case '3':
            playerName = "Meg";
            // start quiz with difficulty 3
            startQuiz(playerName, 3);
            break;
        case '4':
            playerName = "Chris";
            // start quiz with difficulty 4
            startQuiz(playerName, 4);
            break;
        case '5':
            playerName = "Brian";
            // start quiz with difficulty 5
            startQuiz(playerName, 5);
            break;
        case '6':
            // exit the program
            return;
        default:
            // handle invalid selections
            return;
    }
    
    // recursive call to display menu again after quiz ends
    gameMenu();
}

// main function to start the game
int main() {
    // set the random seed to 37 as required in the assignment
    srand(37);
    
    // display the game menu to start playing
    gameMenu();
    
    // end program with success code
    return 0;
}