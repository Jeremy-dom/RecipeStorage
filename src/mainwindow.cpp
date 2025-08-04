#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      recipeList(new QListWidget(this)),
      ingredientList(new QListWidget(this)),
      stepText(new QTextEdit(this))
{
    QWidget *central = new QWidget(this);

    recipeList->setMinimumWidth(150);
    QVBoxLayout *leftColumn = new QVBoxLayout();
    QLabel *labelRecipes = new QLabel("Recettes");
    labelRecipes->setAlignment(Qt::AlignCenter);
    labelRecipes->setStyleSheet("font-weight: bold; font-size: 12px;");
    leftColumn->addWidget(labelRecipes);
    leftColumn->addWidget(recipeList);

    ingredientList->setMinimumWidth(200);
    QVBoxLayout *middleColumn = new QVBoxLayout();
    QLabel *labelIngredients = new QLabel("Ingrédients");
    labelIngredients->setAlignment(Qt::AlignCenter);
    labelIngredients->setStyleSheet("font-weight: bold; font-size: 12px;");
    middleColumn->addWidget(labelIngredients);
    middleColumn->addWidget(ingredientList);

    stepText->setReadOnly(true);
    QVBoxLayout *rightColumn = new QVBoxLayout();
    QLabel *labelSteps = new QLabel("Étapes");
    labelSteps->setAlignment(Qt::AlignCenter);
    labelSteps->setStyleSheet("font-weight: bold; font-size: 12px;");
    rightColumn->addWidget(labelSteps);
    rightColumn->addWidget(stepText);

    // Layout principal horizontal
    QHBoxLayout *layout = new QHBoxLayout(central);
    layout->addLayout(leftColumn);
    layout->addLayout(middleColumn);
    layout->addLayout(rightColumn);


    setCentralWidget(central);
    resize(1200, 600);
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