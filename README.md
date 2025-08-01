# RecipeStorage
App to store recipe in QT
To learn to use QT in a project.

The app will :
    - store recipe with all the ingredients and all the step
    - save and load it in a file
    - take random recipes and write a grocery list
    - calculate all the macro by webscrapping the macro of each ingredient

It will be seperated in 3 directories :
    - src -> All the .cpp files
    - inc -> All the .h files
    - build -> All the files needed by CMake to compile the project
To build the project : 
    - Create a folder build
    - Enter cmake -B build/
    - Enter cmake --build build/

Then you can go to the build directory and use make to compile if you change some files.