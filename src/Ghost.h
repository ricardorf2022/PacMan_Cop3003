//
// Created by Ricardo on 4/27/2024.
//

#ifndef CMAKESFMLPROJECT_GHOST_H
#define CMAKESFMLPROJECT_GHOST_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GLOBAL.h"

class Ghost {
    unsigned char direction;
    unsigned char id;
//    Position target;
//    Position position;

private:
    sf::Sprite sprite;
    sf::Texture texture;
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
    Ghost(unsigned char i_id);
    Ghost();
    virtual ~Ghost();
    void move(const float dirX, const float dirY );
    void updateMovement();
    void updateAnimations();
    void update();
    void render(sf::RenderTarget & target);

    void update_target(unsigned char i_entity_direction, const Position& i_ghost_position, const Position& i_entity_position);
    void set_position(short i_x, short i_y);
//    Position get_position();
    float get_target_distance(unsigned char i_direction);
};

#endif //CMAKESFMLPROJECT_GHOST_H
