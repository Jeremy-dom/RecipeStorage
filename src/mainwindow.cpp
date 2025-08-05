#include "mainwindow.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QFileDialog>


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

    // Menu
    QMenu *fileMenu = menuBar()->addMenu("Fichier");

    QAction *loadAction = new QAction("Ouvrir", this);
    QAction *saveAction = new QAction("Enregistrer sous", this);

    fileMenu->addAction(loadAction);
    fileMenu->addAction(saveAction);

    connect(loadAction, &QAction::triggered, this, &MainWindow::onLoadRecipes);
    connect(saveAction, &QAction::triggered, this, &MainWindow::onSaveRecipes);

    refreshRecipeList();

    // Sélectionner la première recette par défaut
    if (!recipeMap.isEmpty())
        recipeList->setCurrentRow(0);
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

void MainWindow::onLoadRecipes() {
    QString fileName = QFileDialog::getOpenFileName(this, "Charger recettes", "", "JSON (*.json)");
    if (fileName.isEmpty()) return;

    recipeMap = Sauvegarde::loadRecipesFromFile(fileName); 
    populateRecipes(recipeMap);
    refreshRecipeList();
}

void MainWindow::onSaveRecipes() {
    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder recettes", "", "JSON (*.json)");
    if (fileName.isEmpty()) return;

    bool success = Sauvegarde::saveRecipesToFile(recipeMap, fileName);
    if (!success) {
        QMessageBox::warning(this, "Erreur", "Échec de la sauvegarde du fichier.");
    }
}

void MainWindow::refreshRecipeList() {
    recipeList->clear();

    for (const QString& name : recipeMap.keys()) {
        recipeList->addItem(name);
    }
}