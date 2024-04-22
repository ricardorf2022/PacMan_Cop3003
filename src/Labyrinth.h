//
// Created by sting on 4/11/2024.
//

#ifndef CMAKESFMLMAP_LABYRINTH_H
#define CMAKESFMLMAP_LABYRINTH_H


#include <array>
#include <string>
#include "GLOBAL.h"
#include "SFML/Graphics.hpp"
#include "Cell.h"


class Labyrinth{
private:

    sf::Texture tileSheetTexture;
    std::string mapSketch1[MAP_HEIGHT];
    sf::RenderWindow * _window;
    sf::Sprite sprite;
    Cell cells[MAP_HEIGHT][MAP_WIDTH];




    //Private Functions:
    void render();
    void checkWall(int row, int col);
    void convertMap();


public:

    //Constructors
    Labyrinth();
    Labyrinth(sf::RenderWindow & window);

    //Destructor
    ~Labyrinth();

    //Member Functions


    void initialize();
    void load();
    void update();

    void print();
};



#endif //CMAKESFMLMAP_LABYRINTH_H
