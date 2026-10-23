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
    bool connected = false;
    int assignedpin = -1;
};

vector<Component> components = {
    //{"LED", 1, 0, 0, false, -1},
    //{"Button", 1, 0, 0, false, -1},
    //{"Photoresistor", 0, 1, 0, false, -1},
    //{"Buzzer", 0, 0, 1, false, -1},
    //{"Thermistor", 0, 1, 0, false, -1}
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
        {9, true, false, true, false},
        {10, true, false, true, false},
        {11, true, false, true, false},
        {12, true, false, true, false},
        {13, true, false, true, false},
        {14, true, false, true, false},
    };
}

int main() {
    int choice;
    vector<Pin> pins;   
    int led;
    int button;
    int photoresistor;
    int buzzer;
    int thermistor;
    vector<Component> components;

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
    cout << "How many LED's are being used?\n";
    cout << "LED's: ";
    cin >> led;
    cout << "How many buttons are being used?\n";
    cout << "Buttons: ";
    cin >> button;
    cout << "How many photoresistors are being used?\n";
    cout << "Photoresistors: ";
    cin >> photoresistor;
    cout << "How many thermistors are being used?\n";
    cout << "Thermistors";
    cin >> thermistor;
    cout << "How many passive buzzers are being used?\n";
    cout << "Buzzers: ";
    cin >> buzzer;
    
    for (int i = 0; i < led; i++) {
        components.push_back({"LED", 1, 0, 0});
    }
    for (int i = 0; i < button; i++) {
        components.push_back({"Button", 1, 0, 0});
    }
    for (int i = 0; i < photoresistor; i++) {
        components.push_back({"Photoresistor", 0, 1, 0});
    }
    for (int i = 0; i < thermistor; i++) {
        components.push_back({"Thermistor", 0, 1, 0});
    }
    for (int i = 0; i < buzzer; i++) {
        components.push_back({"Buzzer", 0, 0, 1});
    }

    for (int i = 0; i < components.size(); i++) {
        Component& component = components[i];


        for (int x = 0; x < pins.size() && !component.connected; x++) {
            Pin& gpio0 = pins[x];

            if (component.digital == 1 && gpio0.digital && !gpio0.occupied) {
                component.assignedpin = gpio0.number;
                component.connected = true;
                gpio0.occupied = true;
                break;
            }
            else if (component.analog == 1 && gpio0.analog && !gpio0.occupied) {
                component.assignedpin = gpio0.number;
                component.connected = true;
                gpio0.occupied = true;
                break;
            }
            else if (component.pwm == 1 && gpio0.pwm && !gpio0.occupied) {
                component.assignedpin = gpio0.number;
                component.connected = true;
                gpio0.occupied = true;
                break;
            }

        }

        cout << component.name << " assigned to GPIO" << component.assignedpin << endl;

    }
    
    
    return 0;
}