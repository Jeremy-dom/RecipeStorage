#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient{
    private:
        std::string name;
        std::string unit;

    public:
        // Constructeur
        Ingredient(const std::string& name, const std::string& unit);

        // Getter
        std::string getName() const;
        std::string getUnit() const;

        // Setter
        void setName(const std::string& name);
        void setUnit(const std::string& unit);

        // Méthode pour afficher les infos
        void display() const;
};

#endif //INGREDIENT_H