#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      recipeList(new QListWidget(this)),
      ingredientList(new QListWidget(this)),
      stepText(new QTextEdit(this))
{
    QWidget *central = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(central);

    recipeList->setMinimumWidth(150);
    ingredientList->setMinimumWidth(200);
    stepText->setReadOnly(true);

    layout->addWidget(recipeList);
    layout->addWidget(ingredientList);
    layout->addWidget(stepText);

    setCentralWidget(central);
    resize(800, 400);
    setWindowTitle("Livre de Recettes");

    // Connecter la sélection
    connect(recipeList, &QListWidget::currentTextChanged, this, &MainWindow::onRecipeSelected);

    std::vector<Recipe> empty;

    populateRecipes(empty);
}

void MainWindow::populateRecipes(std::vector<Recipe> recipes) {

    for(size_t i = 0; i < recipes.size(); i++)
    {
        QString name = QString::fromStdString(recipes[i].getName());
        for(size_t j = 0; j < recipes[i].sizeIngredient(); j++)
        {
            std::string ingredientQuantity = std::to_string(recipes[i].getQuantity(j)) + recipes[i].getIngredient(j).getUnit() + 
                " " + recipes[i].getIngredient(j).getName();
            ingredientsMap[name] << QString::fromStdString(ingredientQuantity);
        }
        stepsMap[name] = QString::fromStdString(recipes[i].getAllStep());
    }
    recipeList->addItems(ingredientsMap.keys());

    // QString name1 = "Spaghetti Bolognaise";
    // ingredientsMap[name1] = QStringList() << "Pâtes" << "Viande hachée" << "Tomates" << "Oignons" << "Ail";
    // stepsMap[name1] = "1. Faire revenir oignons et ail.\n2. Ajouter la viande.\n3. Ajouter les tomates.\n4. Laisser mijoter.\n5. Cuire les pâtes.\n6. Mélanger et servir.";

    // QString name2 = "Crêpes";
    // ingredientsMap[name2] = QStringList() << "Farine" << "Lait" << "Œufs" << "Sucre" << "Beurre";
    // stepsMap[name2] = "1. Mélanger farine et sucre.\n2. Ajouter œufs et lait.\n3. Bien fouetter.\n4. Cuire dans une poêle beurrée.";

    // recipeList->addItems(ingredientsMap.keys());
}

void MainWindow::onRecipeSelected() {
    QString selected = recipeList->currentItem()->text();

    // Affichage des ingrédients
    ingredientList->clear();
    ingredientList->addItems(ingredientsMap[selected]);

    // Affichage des étapes
    stepText->clear();
    stepText->setText(stepsMap[selected]);
}