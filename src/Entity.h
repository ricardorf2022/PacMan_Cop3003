//
// Created by kiara on 4/3/2024.
//
//
// Created by kiara on 4/3/2024.
//
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef ENTITY_H
#define ENTITY_H

//add this in global constants header file for enum ??
enum ENTITY_ANIMATION_STATE
{
    IDLE = 0,
    MOVING_LEFT = 1,
    MOVING_RIGHT = 2,
    MOVE_UP = 3,
    MOVE_DOWN = 4
};



class Entity {

private:
    sf::Sprite sprite;
    sf::Texture texture;
    //bool moving; // check it entity it's moving
    sf::Clock animationTimer;
    float movementSpeed;

    // Animations
    short aniState; // animation state
    sf::IntRect currentFrame;

    //Private Functions
    void initVariables();
    void initTexture();
    void initSprite();
    void initAnimations();

public:
    Entity();
    virtual ~Entity();

    // float movementSpeed;

// Public Functions

    void move(const float dirX, const float dirY ); // changed to updatedMovement

    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget & target);


};


#endif //ENTITY_H
