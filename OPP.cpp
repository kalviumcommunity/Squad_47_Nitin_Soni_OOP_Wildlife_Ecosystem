#include <iostream>
#include <string>
using namespace std;

// Base class definition for Animal
class Animal {
private:
    string species;       // Private data member for species
    int energyLevel;      // Private data member for energy level
    static int totalAnimals;  // Static variable to keep track of total Animal objects

public:
    // Default constructor
    Animal() : species("Unknown"), energyLevel(50) {
        totalAnimals++;
        cout << "A new " << species << " has been created using the default constructor. Total animals: " << totalAnimals << endl;
    }
    
    // Parameterized constructor
    Animal(string sp, int energy) : species(sp), energyLevel(energy) {
        totalAnimals++;
        cout << "A new " << species << " has been created using the parameterized constructor. Total animals: " << totalAnimals << endl;
    }

    // Destructor
    ~Animal() {
        totalAnimals--;
        cout << species << " has been destroyed. Total animals: " << totalAnimals << endl;
    }

    // Accessor and mutator for species
    string getSpecies() { return species; }
    void setSpecies(string sp) { species = sp; }

    // Accessor and mutator for energyLevel
    int getEnergyLevel() { return energyLevel; }
    void setEnergyLevel(int energy) {
        if (energy >= 0) {
            energyLevel = energy;
        } else {
            cout << "Energy level can't be negative!" << endl;
        }
    }

    // Member functions for Animal
    void move() {
        setEnergyLevel(energyLevel - 10);
        cout << getSpecies() << " is moving. Energy left: " << getEnergyLevel() << endl;
    }
    void eat() {
        setEnergyLevel(energyLevel + 20);
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

// Derived class Mammal from Animal
class Mammal : public Animal {
public:
    // Constructor for Mammal
    Mammal(string sp, int energy) : Animal(sp, energy) {}

    // Additional behavior specific to Mammals
    void nurseYoung() {
        cout << getSpecies() << " is nursing its young." << endl;
    }
};

// Base class definition for Plant
class Plant {
private:
    string plantType;       // Private data member for plant type
    int growthRate;         // Private data member for growth rate
    static int totalPlants; // Static variable to keep track of total Plant objects

public:
    // Default constructor
    Plant() : plantType("Unknown"), growthRate(1) {
        totalPlants++;
        cout << "A new " << plantType << " has been created using the default constructor. Total plants: " << totalPlants << endl;
    }

    // Parameterized constructor
    Plant(string type, int rate) : plantType(type), growthRate(rate) {
        totalPlants++;
        cout << "A new " << plantType << " has been created using the parameterized constructor. Total plants: " << totalPlants << endl;
    }

    // Destructor
    ~Plant() {
        totalPlants--;
        cout << plantType << " has been destroyed. Total plants: " << totalPlants << endl;
    }

    // Accessor and mutator for plantType
    string getPlantType() { return plantType; }
    void setPlantType(string type) { plantType = type; }

    // Accessor and mutator for growthRate
    int getGrowthRate() { return growthRate; }
    void setGrowthRate(int rate) {
        if (rate > 0) {
            growthRate = rate;
        } else {
            cout << "Growth rate must be positive!" << endl;
        }
    }

    // Member functions for Plant
    void grow() {
        cout << getPlantType() << " is growing at a rate of " << getGrowthRate() << " per day." << endl;
    }
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

// Derived class FloweringPlant from Plant
class FloweringPlant : public Plant {
public:
    // Constructor for FloweringPlant
    FloweringPlant(string type, int rate) : Plant(type, rate) {}

    // Additional behavior specific to FloweringPlants
    void bloom() {
        cout << getPlantType() << " is blooming." << endl;
    }
};

int main() {
    // Dynamically allocate Animal objects using default and parameterized constructors
    Animal* animals[2];
    animals[0] = new Animal();                // Default constructor
    animals[1] = new Mammal("Tiger", 90);     // Parameterized constructor for Mammal

    // Call member functions on Animal objects
    animals[1]->move();  // This will work for both Animal and Mammal
    static_cast<Mammal*>(animals[1])->nurseYoung();  // Specific to Mammal

    // Display total animals
    Animal::displayTotalAnimals();

    // Dynamically allocate Plant objects using default and parameterized constructors
    Plant* plants[2];
    plants[0] = new Plant();                  // Default constructor
    plants[1] = new FloweringPlant("Rose", 3); // Parameterized constructor for FloweringPlant

    // Call member functions on Plant objects
    plants[1]->grow();
    static_cast<FloweringPlant*>(plants[1])->bloom();  // Specific to FloweringPlant

    // Display total plants
    Plant::displayTotalPlants();

    // Deallocate memory for Animal objects
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }

    // Deallocate memory for Plant objects
    for (int i = 0; i < 2; i++) {
        delete plants[i];
    }

    cout << "Memory deallocated." << endl;

    return 0;
}
