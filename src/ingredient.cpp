#include "ingredient.h"
#include <iostream>

// Constructeur
Ingredient::Ingredient(const std::string& name, const std::string& unit) : name(name), unit(unit) {}

// Getters
std::string Ingredient::getName() const {
    return name;
}

std::string Ingredient::getUnit() const {
    return unit;
}

// Setters
void Ingredient::setName(const std::string& name) {
    this->name = name;
}

void Ingredient::setUnit(const std::string& unit) {
    this->unit = unit;
}

// Méthode d'affichage
void Ingredient::display() const {
    std::cout << "Name: " << name << ", Unit: " << unit << std::endl;
}