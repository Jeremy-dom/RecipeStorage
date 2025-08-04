#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "recipe.h"

#include <QMainWindow>
#include <QListWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QMap>
#include <QStringList>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void populateRecipes(std::vector<Recipe> recipes);

private slots:
    void onRecipeSelected();

private:
   
    QListWidget *recipeList;
    QListWidget *ingredientList;
    QTextEdit *stepText;

    QMap<QString, QStringList> ingredientsMap;
    QMap<QString, QString> stepsMap;

};

#endif // MAINWINDOW_H