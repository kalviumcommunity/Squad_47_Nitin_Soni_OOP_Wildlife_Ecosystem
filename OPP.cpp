#include <iostream>
#include <string>
using namespace std;

// Class definition for Animal
class Animal {
private:
    string species;
    int energyLevel;

public:
    // Constructor to initialize animal's species and energy level
    Animal(string sp, int energy) : species(sp), energyLevel(energy) {}

    // Member function to simulate animal movement
    void move() {
        this->energyLevel -= 10;  // Use of 'this' pointer to access the object's energyLevel
        cout << this->species << " is moving. Energy left: " << this->energyLevel << endl;
    }

    // Member function to simulate animal eating
    void eat() {
        this->energyLevel += 20;  // Use of 'this' pointer to access the object's energyLevel
        cout << this->species << " is eating. Energy restored to: " << this->energyLevel << endl;
    }

    // Function to display animal information
    void displayInfo() {
        cout << "Species: " << this->species << ", Energy Level: " << this->energyLevel << endl;
    }
};

// Class definition for Plant
class Plant {
private:
    string plantType;
    int growthRate;

public:
    // Constructor to initialize plant type and growth rate
    Plant(string type, int rate) : plantType(type), growthRate(rate) {}

    // Member function to simulate plant growing
    void grow() {
        cout << this->plantType << " is growing at a rate of " << this->growthRate << " per day." << endl; // Use of 'this' pointer
    }

    // Member function to determine if the plant is edible
    void isEdible() {
        if (this->plantType == "Grass") {  // Use of 'this' pointer
            cout << this->plantType << " is edible by herbivores." << endl;
        } else {
            cout << this->plantType << " is not edible." << endl;
        }
    }

    // Function to display plant information
    void displayInfo() {
        cout << "Plant Type: " << this->plantType << ", Growth Rate: " << this->growthRate << endl;
    }
};

int main() {
    // Array of Animal objects
    Animal animals[3] = {
        Animal("Lion", 100),
        Animal("Deer", 80),
        Animal("Elephant", 150)
    };

    // Array of Plant objects
    Plant plants[2] = {
        Plant("Grass", 5),
        Plant("Cactus", 2)
    };

    // Call member functions on Animal objects
    for (int i = 0; i < 3; i++) {
        animals[i].move();
        animals[i].eat();
        animals[i].displayInfo();
    }

    // Call member functions on Plant objects
    for (int i = 0; i < 2; i++) {
        plants[i].grow();
        plants[i].isEdible();
        plants[i].displayInfo();
    }

    return 0;
}
