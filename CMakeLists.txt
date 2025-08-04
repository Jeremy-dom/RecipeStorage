cmake_minimum_required(VERSION 3.16)

project(RecipeStorage VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Rechercher Qt5 d'abord pour éviter la confusion
find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    inc/mainwindow.h    #Obligatoire a cause du Q_OBJECT
    src/ingredient.cpp
    src/recipe.cpp
)


# Qt6 utilise qt_add_executable, mais pas Qt5
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_add_executable(RecipeStorage
${PROJECT_SOURCES}
)
qt_finalize_executable(RecipeStorage)
else()
add_executable(RecipeStorage
${PROJECT_SOURCES}
)
endif()

target_include_directories(RecipeStorage PRIVATE inc)
target_link_libraries(RecipeStorage PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# On peut ignorer la partie bundle (spécifique macOS/iOS) si tu es sous Linux
# Si tu veux la garder proprement, mets-la sous condition :

if(APPLE)
    if(${QT_VERSION} VERSION_LESS 6.1.0)
        set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.RecipeStorage)
    endif()

    set_target_properties(RecipeStorage PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )
endif()

# Installer l'exécutable
include(GNUInstallDirs)
install(TARGETS RecipeStorage
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
