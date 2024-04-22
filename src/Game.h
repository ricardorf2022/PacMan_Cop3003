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

#ifndef GAME_H
#define GAME_H

class Game {

private:
    sf::RenderWindow * _window;

    //Player
    Entity * entity;

    //Private Functions
    void initWindow();
    void initEntity();



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






};



#endif //GAME_H