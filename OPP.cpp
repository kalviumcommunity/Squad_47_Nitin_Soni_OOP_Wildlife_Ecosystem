#include <iostream>
#include <string>
using namespace std;

// Class definition for Animal
class Animal {
private:
    string species;
    int energyLevel;
    static int totalAnimals;  // Static variable to keep track of the number of Animal instances

public:
    // Constructor to initialize animal's species and energy level
    Animal(string sp, int energy) : species(sp), energyLevel(energy) {
        totalAnimals++;  // Increment totalAnimals when a new Animal is created
        cout << "A new " << species << " has been created. Total animals: " << totalAnimals << endl;  // Output the creation of a new animal
    }

    // Destructor to decrement totalAnimals when an Animal is destroyed
    ~Animal() {
        totalAnimals--;
        cout << species << " has been destroyed. Total animals: " << totalAnimals << endl;  // Output the destruction of an animal
    }

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

    // Static function to display the total number of animals
    static void displayTotalAnimals() {
        cout << "Total number of animals: " << totalAnimals << endl;
    }

    // Function to display animal information
    void displayInfo() {
        cout << "Species: " << this->species << ", Energy Level: " << this->energyLevel << endl;
    }
};

// Initialize static variable
int Animal::totalAnimals = 0;

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
    // Dynamically allocate memory for Animal objects
    Animal* animals[3];
    animals[0] = new Animal("Lion", 100);
    animals[1] = new Animal("Deer", 80);
    animals[2] = new Animal("Elephant", 150);

    // Call member functions on Animal objects
    for (int i = 0; i < 3; i++) {
        animals[i]->move();
        animals[i]->eat();
        animals[i]->displayInfo();
    }

    // Display total animals
    Animal::displayTotalAnimals();

    // Dynamically allocate memory for Plant objects
    Plant* plants[2];
    plants[0] = new Plant("Grass", 5);
    plants[1] = new Plant("Cactus", 2);

    // Call member functions on Plant objects
    for (int i = 0; i < 2; i++) {
        plants[i]->grow();
        plants[i]->isEdible();
        plants[i]->displayInfo();
    }

    // Deallocate memory for Animal objects
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    // Deallocate memory for Plant objects
    for (int i = 0; i < 2; i++) {
        delete plants[i];
    }
    
    cout << "Memory deallocated." << endl;

    return 0;
}
