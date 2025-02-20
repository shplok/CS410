#include <iostream>
using namespace std;

int main() {

    // instantiating Variables, to default/ unimportant values.
    const auto EFFICENCY = 0.85;

    string component1 = "";
    string component2 = "";
    string component3 = "";

    double power1 = 0;
    double power2 = 0;
    double power3 = 0;

    double totalEnergyRequired = 0;

    
    // handle user input using std::cin and std::cout
    cout << "Welcome to Stewie’s Time Machine Calculator!\n\n";

    cout << "Please enter the name of the first component: ";
    getline(cin, component1);
    cout << "Please Enter Power Requirement for Time Machine Component 1 (Watts): ";
    cin >> power1;
    cin.ignore(); // to make sure that each line is read correctly and not using next line as input.

    cout << "Please enter the name of the second component: ";
    getline(cin, component2);
    cout << "Please Enter Power Requirement for Time Machine Component 2 in (Watts): ";
    cin >> power2;
    cin.ignore(); // to make sure that each line is read correctly and not using next line as input.
 
    cout << "Please enter the name of the third component: ";
    getline(cin, component3);
    cout << "Please Enter Power Requirement for Time Machine Component 3 in (Watts): ";
    cin >> power3;
    cin.ignore(); // to make sure that each line is read correctly and not using next line as input.

    // calculate the total energy required for running the time machine
    totalEnergyRequired = (power1 + power2 + power3) * EFFICENCY;


    // print the components in proper format to standard output
    cout << "Component List: \n";
    cout << "1. " << component1 << " - " << power1 << "\n";
    cout << "2. " << component2 << " - " << power2 << "\n";
    cout << "3. " << component3 << " - " << power3 << "\n";

    cout << "Total Energy Required: " << totalEnergyRequired << " Watts\n";

    // Print some creative and fun output!
    // Stewie ascii from https://emojicombos.com/family-guy-stewie-ascii-art
    cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⠶⠄⠠⠒⠒⠂⡠⠴⠤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⠤⠎⠁⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠦⡀⠀⠀⠀⠀⠀⠀
⠀⠀⡀⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢆⠀⠀⠀⠀
⡜⠙⠀⠀⠀⠀⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠓⡆⠀⠀
⠀⢢⠀⠀⠀⡄⠒⠚⠳⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠼⣄⠀
⠀⠈⠆⠀⡜⠬⢅⡂⠠⡄⠀⠀⠀⠀⠀⠀⠀⠀⠠⣤⠄⡀⠒⠂⠀⠀⠀⠠⠼⡀
⠀⠀⠈⢢⠱⡀⠀⠀⡩⠃⠀⠀⡠⠀⠀⠀⠀⠠⢌⣀⡀⠀⠑⡀⠀⠀⠀⠀⠠⢇
⠀⠀⠀⠀⠑⢬⡉⠉⠀⠀⠀⠀⠑⠀⠀⠀⠀⠏⠀⠒⠢⠤⠬⠁⠀⠀⠀⡠⠌⠜
⠀⠀⠀⠀⠀⠀⠈⠒⠤⣀⠀⠑⠖⠒⠒⠀⠀⠈⠢⠤⠤⠄⠂⢀⡠⠔⠉⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠉⡐⣲⡤⢤⢀⣀⣀⠤⢤⠄⠒⠈⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠈⡏⠋⣳⠈⠊⠐⠁⠀⠈⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡳⠤⣓⠄⣛⣙⡤⢤⡤⠤⠐⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⠀⠀⠀⠈⠈⠐⠊⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⠀⠀⢄⠀⠀⠀⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣃⡀⠀⠀⢈⠀⠀⠀⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢰⠁⠀⠀⠉⡔⠈⠁⠐⠢⠤⠤⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠘⠢⠤⠄⣀⣀⠠⠄⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)" << "\n" 
    << "Okay Brian, That's it! I'm travelling forward in time just so I can put you down myself.\n";

    return 0;
}