#include "mainwindow.h"
#include "recipe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Recipe pateAlfredo("Pâtes Alfredo");
    pateAlfredo.addIngredient(720, {"Blanc de poulet", "g"});
    pateAlfredo.addIngredient(200, {"Pâtes", "g"});
    pateAlfredo.addIngredient(1, {"Oignon", ""});
    pateAlfredo.addIngredient(2, {"Gousse d'ail", ""});
    pateAlfredo.addIngredient(150, {"Concentré de tomates", "g"});
    pateAlfredo.addIngredient(200, {"Crème fraiche", "mL"});
    pateAlfredo.addIngredient(130, {"Philadelphia", "g"});

    pateAlfredo.displayIngredients();

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

    pateAlfredo.displayStep();

    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    return 0; //a.exec();
}
