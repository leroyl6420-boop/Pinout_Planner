#include <iostream>
#include <string>
using namespace std;

int main() {
    bool custom;
    int pin;
    string mcu;

    cout << "Are you using an MCU out of the preset MCU's? (y/n): ";
    cin >> custom;

    if (custom == 'y') {
        //Write custom code here
    }
    else if (custom == 'n') {
        cout << "Which MCU are you using? : ";
        getline(cin, mcu);

        cout << mcu << endl;
    }
}