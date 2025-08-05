#ifndef RECIPE_H
#define RECIPE_H

#include "ingredient.h"

#include <string>
#include <vector>

class Recipe{
    private:
        std::string name;
        std::vector<int> quantities;
        std::vector<Ingredient> ingredients;
        std::vector<std::string> steps;

    public:

        Recipe();
        Recipe(const std::string& name);
        Recipe(const Recipe&);

        //Getter
        std::string getName() const;
        Ingredient getIngredient(int index) const;
        int getQuantity(int index) const;
        std::string getStep(int index) const;
        std::string getAllStep() const;

        //Setter
        void setName(const std::string& name);

        // Ajouter un ingredient et sa quantité
        void addIngredient(int quantity, Ingredient ingredient);

        //Afficher tous les ingrédients
        void displayIngredients() const;

        //Obtenir le nombre d'ingredient
        size_t sizeIngredient() const;

        // Ajouter une étape
        void addStep(const std::string& step);

        //Afficher tous les étapes
        void displayStep() const;

        //Obtenir le nombre d'etapes
        size_t sizeStep() const;
};

#endif //RECIPE_H