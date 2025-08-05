#ifndef SAUVEGARDE_HPP
#define SAUVEGARDE_HPP

#include "recipe.h"

#include <QMap>
#include <QStringList>
#include <QJsonObject>

class Sauvegarde{
    public:
        static bool saveRecipesToFile( const QMap<QString, Recipe> &recipeMap,
                                        const QString &filePath);
        static QMap<QString, Recipe> loadRecipesFromFile(const QString& filePath);
    
    private:
        static QJsonObject ingredientToJson(const Ingredient& ingredient);
        static QJsonObject recipeToJson(const Recipe& recipe);
};

#endif