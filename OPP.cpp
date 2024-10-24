#include <iostream>
#include <string>
using namespace std;

// Class definition for Animal
class Animal {
private:
    string species;
    int energyLevel;
    static int totalAnimals;  // Static variable to keep track of the number of Animals

public:
    // Constructor to initialize animal's species and energy level
    Animal(string sp, int energy) : species(sp), energyLevel(energy) {
        totalAnimals++;  // Increment totalAnimals
        cout << "A new " << species << " has been created. Total animals: " << totalAnimals << endl;
    }

    // Destructor to decrement totalAnimals when an Animal is destroyed
    ~Animal() {
        totalAnimals--;
        cout << species << " has been destroyed. Total animals: " << totalAnimals << endl;
    }

    // Accessor (getter) for species
    string getSpecies() {
        return species;
    }

    // Mutator (setter) for species
    void setSpecies(string sp) {
        species = sp;
    }

    // Accessor (getter) for energyLevel
    int getEnergyLevel() {
        return energyLevel;
    }

    // Mutator (setter) for energyLevel
    void setEnergyLevel(int energy) {
        if (energy >= 0) {  // Ensuring energy level is non-negative
            energyLevel = energy;
        } else {
            cout << "Energy level can't be negative!" << endl;
        }
    }

    // Member function to simulate animal movement
    void move() {
        setEnergyLevel(energyLevel - 10);  // Using setter
        cout << getSpecies() << " is moving. Energy left: " << getEnergyLevel() << endl;
    }

    // Member function to simulate animal eating
    void eat() {
        setEnergyLevel(energyLevel + 20);  // Using setter
        cout << getSpecies() << " is eating. Energy restored to: " << getEnergyLevel() << endl;
    }

    // Static function to display the total number of animals
    static void displayTotalAnimals() {
        cout << "Total number of animals: " << totalAnimals << endl;
    }

    // Function to display animal information
    void displayInfo() {
        cout << "Species: " << getSpecies() << ", Energy Level: " << getEnergyLevel() << endl;
    }
};

// Initialize static variable
int Animal::totalAnimals = 0;


// Class definition for Plant
class Plant {
private:
    string plantType;
    int growthRate;
    static int totalPlants;  // Static variable to keep track of the number of Plant instances

public:
    // Constructor to initialize plant type and growth rate
    Plant(string type, int rate) : plantType(type), growthRate(rate) {
        totalPlants++;  // Increment totalPlants when a new Plant is created
        cout << "A new " << plantType << " has been created. Total plants: " << totalPlants << endl;
    }

    // Destructor to decrement totalPlants when a Plant is destroyed
    ~Plant() {
        totalPlants--;
        cout << plantType << " has been destroyed. Total plants: " << totalPlants << endl;
    }

    // Accessor (getter) for plantType
    string getPlantType() {
        return plantType;
    }

    // Mutator (setter) for plantType
    void setPlantType(string type) {
        plantType = type;
    }

    // Accessor (getter) for growthRate
    int getGrowthRate() {
        return growthRate;
    }

    // Mutator (setter) for growthRate
    void setGrowthRate(int rate) {
        if (rate > 0) {
            growthRate = rate;
        } else {
            cout << "Growth rate must be positive!" << endl;
        }
    }

    // Member function to simulate plant growing
    void grow() {
        cout << getPlantType() << " is growing at a rate of " << getGrowthRate() << " per day." << endl;
    }

    // Member function to determine if the plant is edible
    void isEdible() {
        if (getPlantType() == "Grass") {
            cout << getPlantType() << " is edible by herbivores." << endl;
        } else {
            cout << getPlantType() << " is not edible." << endl;
        }
    }

    // Static function to display the total number of plants
    static void displayTotalPlants() {
        cout << "Total number of plants: " << totalPlants << endl;
    }

    // Function to display plant information
    void displayInfo() {
        cout << "Plant Type: " << getPlantType() << ", Growth Rate: " << getGrowthRate() << endl;
    }
};

// Initialize static variable
int Plant::totalPlants = 0;

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

    // Display total plants
    Plant::displayTotalPlants();

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
