#include <iostream>
#include <string>
#include <vector>
#include <memory>
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

    string getSpecies() const { return species; }

    void setSpecies(const string& sp) { species = sp; }

    int getEnergyLevel() const { return energyLevel; }

    void setEnergyLevel(int energy) {
        if (energy >= 0) {
            energyLevel = energy;
        } else {
            cout << "Energy level can't be negative!" << endl;
        }
    }

    virtual void move() {
        setEnergyLevel(energyLevel - 10);
        cout << species << " is moving. Energy left: " << energyLevel << endl;
    }

    virtual void eat() {
        setEnergyLevel(energyLevel + 20);
        cout << species << " is eating. Energy restored to: " << energyLevel << endl;
    }

    static void displayTotalAnimals() {
        cout << "Total number of animals: " << totalAnimals << endl;
    }

    void displayInfo() const {
        cout << "Species: " << species << ", Energy Level: " << energyLevel << endl;
    }
};

int Animal::totalAnimals = 0;

// Derived class Mammal inheriting from Animal
class Mammal : public Animal {
public:
    Mammal(string sp, int energy) : Animal(sp, energy) {}

    void move() override {
        setEnergyLevel(getEnergyLevel() - 5);
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

    string getPlantType() const { return plantType; }

    void setPlantType(const string& type) { plantType = type; }

    int getGrowthRate() const { return growthRate; }

    void setGrowthRate(int rate) {
        if (rate > 0) {
            growthRate = rate;
        } else {
            cout << "Growth rate must be positive!" << endl;
        }
    }

    virtual void grow() {
        cout << plantType << " is growing at a rate of " << growthRate << " per day." << endl;
    }

    void displayInfo() const {
        cout << "Plant Type: " << plantType << ", Growth Rate: " << growthRate << endl;
    }

    static void displayTotalPlants() {
        cout << "Total number of plants: " << totalPlants << endl;
    }
};

int Plant::totalPlants = 0;

// Derived class FloweringPlant inheriting from Plant
class FloweringPlant : public Plant {
public:
    FloweringPlant(string type, int rate) : Plant(type, rate) {}

    void grow() override {
        cout << getPlantType() << " is blooming and growing at a rate of " << getGrowthRate() << " per day." << endl;
    }

    void bloom() {
        cout << getPlantType() << " is blooming!" << endl;
    }
};

// Manager class for Animals
class AnimalManager {
private:
    vector<unique_ptr<Animal>> animals;

public:
    void addAnimal(unique_ptr<Animal> animal) {
        animals.push_back(move(animal));
    }

    void displayAllAnimals() const {
        for (const auto& animal : animals) {
            animal->displayInfo();
        }
    }
};

// Manager class for Plants
class PlantManager {
private:
    vector<unique_ptr<Plant>> plants;

public:
    void addPlant(unique_ptr<Plant> plant) {
        plants.push_back(move(plant));
    }

    void displayAllPlants() const {
        for (const auto& plant : plants) {
            plant->displayInfo();
        }
    }
};

int main() {
    AnimalManager animalManager;
    PlantManager plantManager;

    // Adding Animals
    animalManager.addAnimal(make_unique<Animal>());
    animalManager.addAnimal(make_unique<Animal>("Deer", 80));
    animalManager.addAnimal(make_unique<Mammal>("Lion", 90));

    cout << "\nDisplaying All Animals:\n";
    animalManager.displayAllAnimals();

    // Adding Plants
    plantManager.addPlant(make_unique<Plant>());
    plantManager.addPlant(make_unique<FloweringPlant>("Rose", 3));

    cout << "\nDisplaying All Plants:\n";
    plantManager.displayAllPlants();

    cout << "\nProgram Ended Successfully." << endl;
    return 0;
}
