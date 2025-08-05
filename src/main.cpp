#include "mainwindow.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QMap<QString, Recipe> recipeMap = Sauvegarde::loadRecipesFromFile("recettes.json");

    QApplication a(argc, argv);
    MainWindow w;
    w.populateRecipes(recipeMap);
    w.show();
    return a.exec();
}
