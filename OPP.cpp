#include <iostream>
#include <string>
using namespace std;

// Class definition for Animal
class Animal {
private:
    string species;
    int energyLevel;
    static int totalAnimals;

public:
    Animal() : species("Unknown"), energyLevel(50) {
        totalAnimals++;
        cout << "A new " << species << " has been created using the default constructor. Total animals: " << totalAnimals << endl;
    }

    Animal(string sp, int energy) : species(sp), energyLevel(energy) {
        totalAnimals++;
        cout << "A new " << species << " has been created using the parameterized constructor. Total animals: " << totalAnimals << endl;
    }

    virtual ~Animal() {
        totalAnimals--;
        cout << species << " has been destroyed. Total animals: " << totalAnimals << endl;
    }

    string getSpecies() {
        return species;
    }

    void setSpecies(string sp) {
        species = sp;
    }

    int getEnergyLevel() {
        return energyLevel;
    }

    void setEnergyLevel(int energy) {
        if (energy >= 0) {
            energyLevel = energy;
        } else {
            cout << "Energy level can't be negative!" << endl;
        }
    }

    virtual void move() { // Virtual function to be overridden
        setEnergyLevel(energyLevel - 10);
        cout << getSpecies() << " is moving. Energy left: " << getEnergyLevel() << endl;
    }

    virtual void eat() { // Virtual function to be overridden
        setEnergyLevel(energyLevel + 20);
        cout << getSpecies() << " is eating. Energy restored to: " << getEnergyLevel() << endl;
    }

    static void displayTotalAnimals() {
        cout << "Total number of animals: " << totalAnimals << endl;
    }

    void displayInfo() {
        cout << "Species: " << getSpecies() << ", Energy Level: " << getEnergyLevel() << endl;
    }
};

int Animal::totalAnimals = 0;

// Derived class Mammal inheriting from Animal
class Mammal : public Animal {
public:
    Mammal(string sp, int energy) : Animal(sp, energy) {}

    // Overriding the move function for Mammal
    void move() override {
        setEnergyLevel(getEnergyLevel() - 5); // Less energy consumed for mammals
        cout << getSpecies() << " is running. Energy left: " << getEnergyLevel() << endl;
    }

    void nurseYoung() {
        cout << getSpecies() << " is nursing its young." << endl;
    }
};

// Class definition for Plant
class Plant {
private:
    string plantType;
    int growthRate;
    static int totalPlants;

public:
    Plant() : plantType("Unknown"), growthRate(1) {
        totalPlants++;
        cout << "A new " << plantType << " has been created using the default constructor. Total plants: " << totalPlants << endl;
    }

    Plant(string type, int rate) : plantType(type), growthRate(rate) {
        totalPlants++;
        cout << "A new " << plantType << " has been created using the parameterized constructor. Total plants: " << totalPlants << endl;
    }

    virtual ~Plant() {
        totalPlants--;
        cout << plantType << " has been destroyed. Total plants: " << totalPlants << endl;
    }

    string getPlantType() {
        return plantType;
    }

    void setPlantType(string type) {
        plantType = type;
    }

    int getGrowthRate() {
        return growthRate;
    }

    void setGrowthRate(int rate) {
        if (rate > 0) {
            growthRate = rate;
        } else {
            cout << "Growth rate must be positive!" << endl;
        }
    }

    virtual void grow() { // Virtual function to be overridden
        cout << getPlantType() << " is growing at a rate of " << getGrowthRate() << " per day." << endl;
    }

    void isEdible() {
        if (getPlantType() == "Grass") {
            cout << getPlantType() << " is edible by herbivores." << endl;
        } else {
            cout << getPlantType() << " is not edible." << endl;
        }
    }

    static void displayTotalPlants() {
        cout << "Total number of plants: " << totalPlants << endl;
    }

    void displayInfo() {
        cout << "Plant Type: " << getPlantType() << ", Growth Rate: " << getGrowthRate() << endl;
    }
};

int Plant::totalPlants = 0;

// Derived class FloweringPlant inheriting from Plant
class FloweringPlant : public Plant {
public:
    FloweringPlant(string type, int rate) : Plant(type, rate) {}

    // Overriding the grow function for FloweringPlant
    void grow() override {
        cout << getPlantType() << " is blooming and growing at a rate of " << getGrowthRate() << " per day." << endl;
    }

    void bloom() {
        cout << getPlantType() << " is blooming!" << endl;
    }
};

int main() {
    // Animal objects
    Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Animal("Deer", 80);
    animals[2] = new Animal("Elephant", 150);

    animals[1]->move();  // Will call Animal's move
    animals[2]->eat();   // Will call Animal's eat

    Animal::displayTotalAnimals();

    // Derived Mammal object
    Mammal* mammal = new Mammal("Lion", 90);
    mammal->nurseYoung();
    mammal->move(); // Will call Mammal's move

    Animal::displayTotalAnimals();

    // Plant objects
    Plant* plants[2];
    plants[0] = new Plant();
    plants[1] = new Plant("Cactus", 2);

    for (int i = 0; i < 2; i++) {
        plants[i]->grow();  // Will call Plant's grow
        plants[i]->isEdible();
        plants[i]->displayInfo();
    }

    Plant::displayTotalPlants();

    // Derived FloweringPlant object
    FloweringPlant* floweringPlant = new FloweringPlant("Rose", 3);
    floweringPlant->bloom();
    floweringPlant->grow(); // Will call FloweringPlant's grow

    Plant::displayTotalPlants();

    // Deallocate memory for Animal and Plant objects
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    delete mammal;

    for (int i = 0; i < 2; i++) {
        delete plants[i];
    }
    delete floweringPlant;

    cout << "Memory deallocated." << endl;

    return 0;
}
