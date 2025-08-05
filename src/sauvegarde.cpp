#include "sauvegarde.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>


QJsonObject Sauvegarde::ingredientToJson(const Ingredient& ingredient) {
    QJsonObject obj;
    obj["name"] = QString::fromStdString(ingredient.getName());
    obj["unit"] = QString::fromStdString(ingredient.getUnit());
    return obj;
}

QJsonObject Sauvegarde::recipeToJson(const Recipe& recipe) {
    QJsonObject obj;
    obj["name"] = QString::fromStdString(recipe.getName());

    QJsonArray ingredientsArray;
    for (const auto& ing : recipe.getIngredients())
        ingredientsArray.append(ingredientToJson(ing));
    obj["ingredients"] = ingredientsArray;

    QJsonArray quantitiesArray;
    for (const auto& ing : recipe.getQuantities())
        quantitiesArray.append(ing);
    obj["quantities"] = quantitiesArray;

    QJsonArray stepsArray;
    for (const auto& step : recipe.getSteps())
        stepsArray.append(QString::fromStdString(step));
    obj["steps"] = stepsArray;

    return obj;
}

bool Sauvegarde::saveRecipesToFile(const QMap<QString, Recipe>& recipeMap, const QString& filePath) {
    QJsonArray recipesArray;

    for (const auto& recipe : recipeMap)
        recipesArray.append(recipeToJson(recipe));

    QJsonDocument doc(recipesArray);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning("Impossible d'ouvrir le fichier pour écriture");
        return false;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

QMap<QString, Recipe> Sauvegarde::loadRecipesFromFile(const QString& filePath) {
    QMap<QString, Recipe> recipeMap;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Impossible d'ouvrir le fichier pour lecture.");
        return recipeMap;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qWarning("Le fichier JSON n'est pas un tableau !");
        return recipeMap;
    }

    QJsonArray recipesArray = doc.array();

    for (const QJsonValue& value : recipesArray) {
        if (!value.isObject()) continue;

        QJsonObject recipeObj = value.toObject();

        QString name = recipeObj["name"].toString();
        Recipe recipe(name.toStdString());

        // Charger ingrédients
        QJsonArray ingredientsArray = recipeObj["ingredients"].toArray();
        for (const QJsonValue& ingVal : ingredientsArray) {
            QJsonObject ingObj = ingVal.toObject();
            QString ingName = ingObj["name"].toString();
            QString ingUnit = ingObj["unit"].toString();

            Ingredient ingredient(ingName.toStdString(), ingUnit.toStdString());
            recipe.addIngredient(ingredient);
        }

        // Charger quantités
        QJsonArray quantiteArray = recipeObj["quantities"].toArray();
        for (const QJsonValue& quanVal : quantiteArray) {
            int quantite = quanVal.toInt();
            recipe.addQuantity(quantite);
        }

        // Charger étapes
        QJsonArray stepsArray = recipeObj["steps"].toArray();
        for (const QJsonValue& stepVal : stepsArray) {
            QString step = stepVal.toString();
            recipe.addStep(step.toStdString());
        }

        recipeMap.insert(name, recipe);
    }

    return recipeMap;
}