#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pin {
    int number;
    bool digital;
    bool analog;
    bool pwm;
    bool occupied;
};

struct Component {
    string name;
    int digital;
    int analog;
    int pwm;
    bool connected;
}

vector<Component> components = {
    {"LED", 1, 0, 0, false};
    {"Button", 1, 0, 0, false};
    {"Photoresistor", 0, 1, 0, false};
    {"Buzzer", 0, 0, 1, false};
};

vector<Pin> createzeropins() {
    return {
        {0, true, false, true, false},
        {1, true, false, true, false},
        {2, true, false, true, false},
        {3, true, false, true, false},
        {4, true, false, true, false},
        {5, true, false, true, false},
        {6, true, false, true, false},
        {7, true, false, true, false},
        {8, true, false, true, false},
        {9, true, false, true, false},
        {10, true, false, true, false},
        {11, true, false, true, false},
        {12, true, false, true, false},
        {13, true, false, true, false},
        {14, true, false, true, false},
        {15, true, false, true, false},
        {26, true, true, true, false},
        {27, true, true, true, false},
        {28, true, true, true, false},
        {29, true, true, true, false},
    };
}

vector<Pin> createpicopins() {
    return {
        {0, false, false, false, false}
        // add rest later
    };
}

int main() {
    int choice;
    vector<Pin> pins;

    cout << "Which MCU are you using?\n";
    cout << "1) Waveshare RP2040 Zero\n";
    cout << "2) Raspberry Pi Pico\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        pins = createzeropins();
    }
    else if (choice == 2) {
        pins = createpicopins();
    }
    else {
        cout << "Invalid MCU selection!\n";
        return 1;
    }    

    cout << "MCU loaded successfully!\n";
    cout << "Number of pins: " << pins.size() << endl;

    return 0;
}