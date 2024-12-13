#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Abstract Class for Animal
class Animal {
private:
    int energyLevel;
    static int totalAnimals;

protected:
    string species;

public:
    Animal(string sp, int energy) : species(sp), energyLevel(energy) {
        totalAnimals++;
        cout << "A new " << species << " has been created. Total animals: " << totalAnimals << endl;
    }

    virtual ~Animal() {
        totalAnimals--;
        cout << species << " has been destroyed. Total animals: " << totalAnimals << endl;
    }

    int getEnergyLevel() const { return energyLevel; }

    void setEnergyLevel(int energy) {
        if (energy >= 0) {
            energyLevel = energy;
        } else {
            cout << "Energy level can't be negative!" << endl;
        }
    }

    string getSpecies() const { return species; }

    // Abstract methods to enforce OCP
    virtual void move() = 0;
    virtual void eat() = 0;

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
        if (getEnergyLevel() > 5) {
            setEnergyLevel(getEnergyLevel() - 5);
            cout << getSpecies() << " is running. Energy left: " << getEnergyLevel() << endl;
        } else {
            cout << getSpecies() << " is too tired to run. Energy too low!" << endl;
        }
    }

    void eat() override {
        setEnergyLevel(getEnergyLevel() + 15);
        cout << getSpecies() << " is eating. Energy restored to: " << getEnergyLevel() << endl;
    }

    void nurseYoung() {
        cout << getSpecies() << " is nursing its young." << endl;
    }
};

// Derived class Bird inheriting from Animal
class Bird : public Animal {
public:
    Bird(string sp, int energy) : Animal(sp, energy) {}

    void move() override {
        if (getEnergyLevel() > 10) {
            setEnergyLevel(getEnergyLevel() - 10);
            cout << getSpecies() << " is flying. Energy left: " << getEnergyLevel() << endl;
        } else {
            cout << getSpecies() << " is too tired to fly. Energy too low!" << endl;
        }
    }

    void eat() override {
        setEnergyLevel(getEnergyLevel() + 10);
        cout << getSpecies() << " is eating seeds. Energy restored to: " << getEnergyLevel() << endl;
    }

    void sing() {
        cout << getSpecies() << " is singing a beautiful song." << endl;
    }
};

// Abstract Class for Plant
class Plant {
private:
    static int totalPlants;

protected:
    string plantType;
    int growthRate;

public:
    Plant(string type, int rate) : plantType(type), growthRate(rate) {
        totalPlants++;
        cout << "A new " << plantType << " has been created. Total plants: " << totalPlants << endl;
    }

    virtual ~Plant() {
        totalPlants--;
        cout << plantType << " has been destroyed. Total plants: " << totalPlants << endl;
    }

    string getPlantType() const { return plantType; }

    int getGrowthRate() const { return growthRate; }

    void setGrowthRate(int rate) {
        if (rate > 0) {
            growthRate = rate;
        } else {
            cout << "Growth rate must be positive!" << endl;
        }
    }

    // Abstract method to enforce OCP
    virtual void grow() = 0;

    static void displayTotalPlants() {
        cout << "Total number of plants: " << totalPlants << endl;
    }

    void displayInfo() const {
        cout << "Plant Type: " << plantType << ", Growth Rate: " << growthRate << endl;
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
    animalManager.addAnimal(make_unique<Mammal>("Lion", 90));  // Mammal
    animalManager.addAnimal(make_unique<Bird>("Parrot", 50));  // Bird

    cout << "\nDisplaying All Animals:\n";
    animalManager.displayAllAnimals();

    // Adding Plants
    plantManager.addPlant(make_unique<FloweringPlant>("Rose", 3));

    cout << "\nDisplaying All Plants:\n";
    plantManager.displayAllPlants();

    cout << "\nProgram Ended Successfully." << endl;
    return 0;
}
