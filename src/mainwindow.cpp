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

    QMap<QString, Recipe> empty;

    populateRecipes(empty);
}

void MainWindow::populateRecipes(QMap<QString, Recipe> recipesMap) 
{
    for(auto it = recipesMap.begin(); it != recipesMap.end(); ++it)
    {
        QString name = it.key();
        for(size_t j = 0; j < it.value().sizeIngredient(); j++)
        {
            std::string ingredientQuantity = std::to_string(it.value().getQuantity(j)) + it.value().getIngredient(j).getUnit() + 
                " " + it.value().getIngredient(j).getName();
            ingredientsMap[name] << QString::fromStdString(ingredientQuantity);
        }
        stepsMap[name] = QString::fromStdString(it.value().getAllStep());
    }
    recipeList->addItems(ingredientsMap.keys());
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