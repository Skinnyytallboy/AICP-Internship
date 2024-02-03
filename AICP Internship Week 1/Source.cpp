#include <iostream>
#include <string>
using namespace std;

const int pupils = 30;
const double MIN_WEIGHT = 20.0;
const double MAX_WEIGHT = 200.0;

bool CheckWeight(double weight) {
    return (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT);
}
bool CheckName(string names[], int times, string name) {
    int count = 0;
    for (int i = 0; i < times; i++) {
        if (name == names[i])
            count++;
    }
    return (count <= 1);
}
void firstinput(string names[], double weights[]) {
    for (int i = 0; i < pupils; i++) {
        cout << "Enter First Name and Weight (in kg) for pupil " << i + 1 << " : ";
        cin >> names[i] >> weights[i];
        while (!CheckName(names, i, names[i])) {
            cout << "You already entered the data of this pupil, Enter First name and Weight again: ";
            cin >> names[i] >> weights[i];
        }
        while (!CheckWeight(weights[i])) {
            cout << "Invalid Weight...\nWeight should be Greater than 20 and Lesser than 200.\nEnter Weight of Pupil " << names[i] << " Again: ";
            cin >> weights[i];
        }
    }
}
void Lastinput(string names[], double weights2[]) {
    for (int i = 0; i < pupils; i++) {
        cout << "Enter Weight (in kg) of Pupil " << names[i] << " on the last day of term: ";
        cin >> weights2[i];
        while (!CheckWeight(weights2[i])) {
            cout << "Invalid Weight...\nWeight should be Greater than 20 and Lesser than 200.\nEnter Weight of Pupil " << names[i] << " Again: ";
            cin >> weights2[i];
        }
    }
}
void print(string names[], double weights[], double weights2[]) {
    cout << endl;
    for (int i = 0; i < pupils; i++) {
        double diff = weights2[i] - weights[i];
        if (diff > 2.5)
            cout << "Weight of Pupil " << names[i] << " is increased by " << diff << " kg" << endl;
        else if (diff < -2.5)
            cout << "Weight of Pupil " << names[i] << " is decreased by " << -diff << " kg" << endl;
    }
}

int main() {
    double weights[pupils] = {};
    string names[pupils] = {};
    double weights2[pupils] = {};
    firstinput(names, weights);
    Lastinput(names, weights2);
    print(names, weights, weights2);
    return 0;
}