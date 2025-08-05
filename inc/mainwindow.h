#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "recipe.h"
#include "sauvegarde.h"

#include <QMainWindow>
#include <QListWidget>
#include <QTextEdit>
#include <QMap>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void populateRecipes(QMap<QString, Recipe> recipesMap);

private slots:
    void onRecipeSelected();
    void onLoadRecipes();
    void onSaveRecipes();

private:
   
    QListWidget *recipeList;
    QListWidget *ingredientList;
    QTextEdit *stepText;

    QMap<QString, Recipe> recipeMap;
    QMap<QString, QStringList> ingredientsMap;
    QMap<QString, QString> stepsMap;

    void refreshRecipeList();
};

#endif // MAINWINDOW_H