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
};


int main() {
    // Create objects (instances) of Animal and Plant classes
    Animal lion("Lion", 100);
    Animal deer("Deer", 80);

    Plant grass("Grass", 5);
    Plant cactus("Cactus", 2);

    // Call member functions on Animal objects
    lion.move();
    lion.eat();

    deer.move();
    deer.eat();

    // Call member functions on Plant objects
    grass.grow();
    grass.isEdible();

    cactus.grow();
    cactus.isEdible();

    return 0;
}
