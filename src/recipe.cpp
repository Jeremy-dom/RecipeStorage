#include "recipe.h"
#include <iostream>

// Constructeur
Recipe::Recipe() {}

Recipe::Recipe(const std::string& name) : name(name) {}

Recipe::Recipe(const Recipe& recipe) : name(recipe.getName())
{
    for(size_t i = 0; i < recipe.sizeIngredient(); i++)
    {
        this->quantities.push_back(recipe.getQuantity(i));
        this->ingredients.push_back(recipe.getIngredient(i));
    }
    for(size_t i = 0; i < recipe.sizeStep(); i++)
    {
        this->steps.push_back(recipe.getStep(i));
    }
}

// Getters
std::string Recipe::getName() const {
    return name;
}

Ingredient Recipe::getIngredient(int index) const
{
    return ingredients[index];
}

const std::vector<Ingredient>& Recipe::getIngredients() const
{
    return ingredients;
}

int Recipe::getQuantity(int index) const
{
    return quantities[index];
}

const std::vector<int>& Recipe::getQuantities() const
{
    return quantities;
}

std::string Recipe::getStep(int index) const
{
    return steps[index];
}

const std::vector<std::string>& Recipe::getSteps() const
{
    return steps;
}

std::string Recipe::getAllStep() const
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

// Ajouter un ingredient
void Recipe::addIngredient(Ingredient ingredient)
{
    ingredients.push_back(ingredient);
}

// Ajouter sa quantité
void Recipe::addQuantity(int quantity)
{
    quantities.push_back(quantity);
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