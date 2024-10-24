#include <iostream>
#include <string>
using namespace std;

// Class definition for Animal
class Animal {
private:
    string species;       // Private data member for species (abstracts internal details)
    int energyLevel;      // Private data member for energy level (abstracts internal details)
    static int totalAnimals;  // Static variable to keep track of the total number of Animal objects

public:
    // Default constructor: Initializes the species and energyLevel with default values
    Animal() : species("Unknown"), energyLevel(50) {
        totalAnimals++;  // Increment totalAnimals
        cout << "A new " << species << " has been created using the default constructor. Total animals: " << totalAnimals << endl;
    }

    // Parameterized constructor: Initializes the species and energy level with specified values
    Animal(string sp, int energy) : species(sp), energyLevel(energy) {
        totalAnimals++;  // Increment totalAnimals
        cout << "A new " << species << " has been created using the parameterized constructor. Total animals: " << totalAnimals << endl;
    }

    // Destructor: Called when an object is destroyed
    ~Animal() {
        totalAnimals--;  // Decrement totalAnimals
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
        setEnergyLevel(energyLevel - 10);  // Using setter to update energy
        cout << getSpecies() << " is moving. Energy left: " << getEnergyLevel() << endl;
    }

    // Member function to simulate animal eating
    void eat() {
        setEnergyLevel(energyLevel + 20);  // Using setter to update energy
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
    string plantType;       // Private data member for plant type (abstracts internal details)
    int growthRate;         // Private data member for growth rate (abstracts internal details)
    static int totalPlants; // Static variable to keep track of the total number of Plant objects

public:
    // Default constructor: Initializes plantType and growthRate with default values
    Plant() : plantType("Unknown"), growthRate(1) {
        totalPlants++;  // Increment totalPlants when a new Plant is created
        cout << "A new " << plantType << " has been created using the default constructor. Total plants: " << totalPlants << endl;
    }

    // Parameterized constructor: Initializes plantType and growthRate with specified values
    Plant(string type, int rate) : plantType(type), growthRate(rate) {
        totalPlants++;  // Increment totalPlants when a new Plant is created
        cout << "A new " << plantType << " has been created using the parameterized constructor. Total plants: " << totalPlants << endl;
    }

    // Destructor: Called when an object is destroyed
    ~Plant() {
        totalPlants--;  // Decrement totalPlants when a Plant is destroyed
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
    // Dynamically allocate memory for Animal objects using both default and parameterized constructors
    Animal* animals[3];
    animals[0] = new Animal();                // Default constructor
    animals[1] = new Animal("Deer", 80);      // Parameterized constructor
    animals[2] = new Animal("Elephant", 150); // Parameterized constructor

    // Call member functions on Animal objects
    for (int i = 0; i < 3; i++) {
        animals[i]->move();
        animals[i]->eat();
        animals[i]->displayInfo();
    }

    // Display total animals
    Animal::displayTotalAnimals();

    // Dynamically allocate memory for Plant objects using both default and parameterized constructors
    Plant* plants[2];
    plants[0] = new Plant();               // Default constructor
    plants[1] = new Plant("Cactus", 2);    // Parameterized constructor

    // Call member functions on Plant objects
    for (int i = 0; i < 2; i++) {
        plants[i]->grow();
        plants[i]->isEdible();
        plants[i]->displayInfo();
    }

    // Display total plants
    Plant::displayTotalPlants();

    // Deallocate memory for Animal objects (explicit destructor call)
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    // Deallocate memory for Plant objects (explicit destructor call)
    for (int i = 0; i < 2; i++) {
        delete plants[i];
    }

    cout << "Memory deallocated." << endl;

    return 0;
}
