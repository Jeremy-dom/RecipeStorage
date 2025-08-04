#include "mainwindow.h"
#include "recipe.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    std::vector<Recipe> recipeVector;
    Recipe pateAlfredo("Pâtes Alfredo");
    pateAlfredo.addIngredient(720, {"Blanc de poulet", "g"});
    pateAlfredo.addIngredient(200, {"Pâtes", "g"});
    pateAlfredo.addIngredient(1, {"Oignon", ""});
    pateAlfredo.addIngredient(2, {"Gousse d'ail", ""});
    pateAlfredo.addIngredient(150, {"Concentré de tomates", "g"});
    pateAlfredo.addIngredient(200, {"Crème fraiche", "mL"});
    pateAlfredo.addIngredient(130, {"Philadelphia", "g"});

    pateAlfredo.addStep("Faire cuire les pâtes");
    pateAlfredo.addStep("Couper le poulet en petit morceaux");
    pateAlfredo.addStep("Mettre le poulet dans un saladier");
    pateAlfredo.addStep("Dans le saladier, rajouter du sel, du poivre, de l'ail en poudre, du paprika, des herbes de provences et de l'huile d'olive puis melanger");
    pateAlfredo.addStep("Faire cuire le poulet");
    pateAlfredo.addStep("Couper un oignon et de l'ail en petit morceaux");
    pateAlfredo.addStep("Lorsque le poulet est cuit, le retirer de la poêle");
    pateAlfredo.addStep("Dans la même poêle, mettre de l'huile d'olive puis l'oignon et l'ail coupé");
    pateAlfredo.addStep("Faire revenir l'oignon et l'ail");
    pateAlfredo.addStep("Mettre du sel, du poivre, du paprika, des herbes de provences sur l'oignon et l'ail");
    pateAlfredo.addStep("Mettre le concentré de tomate et melanger");
    pateAlfredo.addStep("Rajouter la creme fraiche et le philadelphia puis mélanger");
    pateAlfredo.addStep("Faire réduire la sauce pendant 5 min");
    pateAlfredo.addStep("Mettre le poulet et les pates dans la sauce puis melanger");

    Recipe boeufTacoRiz("Boeuf Tacos et riz");
    boeufTacoRiz.addIngredient(720, {"Boeuf haché", "g"});
    boeufTacoRiz.addIngredient(1, {"Oignon", ""});
    boeufTacoRiz.addIngredient(1, {"Taco seasoning", ""});
    boeufTacoRiz.addIngredient(120, {"Concentré de tomates", "g"});
    boeufTacoRiz.addIngredient(200, {"riz", "g"});
    boeufTacoRiz.addIngredient(500, {"Bouillon de boeuf", "mL"});
    boeufTacoRiz.addIngredient(100, {"Mozarella", "g"});

    boeufTacoRiz.addStep("Dorer les oignons");
    boeufTacoRiz.addStep("Cuire le Boeuf");
    boeufTacoRiz.addStep("Quand le boeuf est presque cuit, ajouter le paquet de taco seasoning et mélanger");
    boeufTacoRiz.addStep("Ajouter l'ail et mélanger");
    boeufTacoRiz.addStep("Ajouter la tomate et mélanger");
    boeufTacoRiz.addStep("Ajouter le riz");
    boeufTacoRiz.addStep("Ajouter le bouillon");
    boeufTacoRiz.addStep("Mélanger et laisser couvert à feu doux pendant 15 à 20 min");
    boeufTacoRiz.addStep("Pensez à remuez toutes les 2-3 minutes");
    boeufTacoRiz.addStep("Mettre le fromage par dessus et couvrir pour 5min");

    recipeVector.push_back(pateAlfredo);
    recipeVector.push_back(boeufTacoRiz);

    QApplication a(argc, argv);
    MainWindow w;
    w.populateRecipes(recipeVector);
    w.show();
    return a.exec();
}
