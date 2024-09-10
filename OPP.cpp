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
        energyLevel -= 10;
        cout << species << " is moving. Energy left: " << energyLevel << endl;
    }

    // Member function to simulate animal eating
    void eat() {
        energyLevel += 20;
        cout << species << " is eating. Energy restored to: " << energyLevel << endl;
    }
};

// Class definition for Plant
class Plant {
private:
    string plantType;
    int growthRate;

public:

    Plant(string type, int rate) : plantType(type), growthRate(rate) {}
    void grow() {
        cout << plantType << " is growing at a rate of " << growthRate << " per day." << endl;
    }
    void isEdible() {
        if (plantType == "Grass") {
            cout << plantType << " is edible by herbivores." << endl;
        } else {
            cout << plantType << " is not edible." << endl;
        }
    }
};

int main() {
   
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
    cout<<"Hello World!"<<endl;
    return 0;
}
