//
// Created by kiara on 4/3/2024.
//
//
// Created by kiara on 4/3/2024.
//
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Entity.h"
#include "Labyrinth.h"
#include "Ghost.h"

#ifndef GAME_H
#define GAME_H

class Game {

private:
    sf::RenderWindow * _window;

    //Player
    Entity * entity;
    Ghost * ghost;

    //Private Functions
    void initWindow();
    void initEntity();
    void initGhost();



public:
    Game();
    Game(sf::RenderWindow & window);
    virtual ~Game();

    //Functions
    void runGame(); // this function is going to just run the game

    void updateEntity();
    void update();
    void renderEntity();
    void render();
    void updateGhost();
    void renderGhost();






};



#endif //GAME_H