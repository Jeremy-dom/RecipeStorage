#include "recipe.h"
#include <iostream>

// Constructeur
Recipe::Recipe(const std::string& name) : name(name) {}

// Getters
std::string Recipe::getName() const {
    return name;
}

Ingredient Recipe::getIngredient(int index)
{
    return ingredients[index];
}

int Recipe::getQuantity(int index)
{
    return quantities[index];
}

std::string Recipe::getAllStep()
{
    std::string allStep;
    for(size_t i = 0; i < steps.size(); i++)
    {
        allStep += steps[i];
        allStep += "\n";
    }
    return allStep;
}

// Setters
void Recipe::setName(const std::string& name) {
    this->name = name;
}

// Ajouter un ingredient et sa quantité
void Recipe::addIngredient(int quantity, Ingredient ingredient) {
    quantities.push_back(quantity);
    ingredients.push_back(ingredient);
}

//Afficher tous les ingrédients
void Recipe::displayIngredients() const {

    std::cout << "Liste d'ingrédients pour " << name << " : " << std::endl; 
    for(size_t i = 0; i < ingredients.size(); i++)
    {
        if(ingredients[i].getUnit() != "")
            std::cout << quantities[i] << " " << ingredients[i].getUnit() << " " << ingredients[i].getName() << std::endl;
        else 
            std::cout << quantities[i] << " " << ingredients[i].getName() << std::endl;
    }
}

//Obtenir le nombre d'ingredient
size_t Recipe::sizeIngredient() const {
    return ingredients.size();
}

// Ajouter une étape
void Recipe::addStep(const std::string& step) {
    steps.push_back(step);
}

//Afficher tous les étapes
void Recipe::displayStep() const {
    std::cout << "Les étapes pour " << name << " : " << std::endl; 
    for(size_t i = 0; i < steps.size(); i++)
    {
        std::cout << i+1 << ") " << steps[i] << std::endl;
    }
}

//Obtenir le nombre d'etapes
size_t Recipe::sizeStep() const {
    return steps.size();
}