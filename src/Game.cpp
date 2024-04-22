//
// Created by kiara on 4/3/2024.
//

//
// Created by kiara on 4/3/2024.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Labyrinth.h"







//Constructors & Destructors
/**
 * constructor
 */
Game::Game()
{
    this->initEntity(); // calling my entity
}

Game::Game(sf::RenderWindow &window) {
    _window = &window;
    this->initEntity(); // calling my entity
}

/**
 *
 */
Game::~Game()
{
    delete this->entity;
}


/**
 * Private Function
 */

void Game::initEntity() // keep everything related to the entity in here
{
    this->entity = new Entity(); // keeps this empty because the player constructor is empty.

}

/**
 * contains all the player update to one function
 */
void Game::updateEntity()
{
    this->entity->update();
}

/**
 * updates all the positions
 */

void Game::renderEntity()
{
    this->entity->render(*this->_window); // dereference , since window is a pointer
}

void Game::update() {

    sf::Event events{}; // class from SFML
    while (this->_window->pollEvent(events))
    {
        if(events.Event::type == sf::Event::Closed)             // if user click the 'X' it will close the window
            this->_window->close();

        if( events.Event::key.code == sf::Keyboard::Escape)
            this->_window->close();
    }

    this->updateEntity(); //  Entity.cpp ->  Entity::updateEntity

}

/**
 * draws all the stuff out
 */
void Game::render()
{
    //this->_window->clear();

    //same thing as below just another way to write it but within the Game.h
    this->renderEntity();

    //Draws all the stuff

    //this-> entity->render(*this->window); // it takes a reference, since the window is a pointer
    // it needs to be dereferenced out window by the asterisk (*)

    this->_window->display();

}

void Game::runGame()
{
    this->update();
   // this->render();

}


