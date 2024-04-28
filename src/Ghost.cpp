//
// Created by Ricardo on 4/27/2024.
//
#include <array>
#include <cmath>
#include "Ghost.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void Ghost::initVariables()
{
    this->aniState = ENTITY_ANIMATION_STATE::IDLE;
}

void Ghost::initTexture()
{
    if (!this->texture.loadFromFile("../../assets/pinky.png") );
}

void Ghost::initSprite()
{
    //setting the texture for the sprite
    this->sprite.setTexture(this->texture); // takes  the reference of a texture

    this->currentFrame = sf::IntRect(0,0,64,64);
    this->sprite.setTextureRect(currentFrame);    // rending a small bit of out texture

    //resize the sprite
    this->sprite.scale(.4f,.4f);        // putting (1.f,1.f) is going to be the original size of the image

    this->sprite.setPosition(400.f,450.f);        //set position of the sprite everytime in the middle of the screen
}

void Ghost::initAnimations()
{
    this->animationTimer.restart();

}

Ghost::Ghost(unsigned char i_id) {
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initAnimations();
}

Ghost::~Ghost() {

}

//Public Functions

void Ghost::move(const float dirX, const float dirY)
{

    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

}

void Ghost::updateAnimations()
{
    //CURRENTLY NOT USING IDLE
    if(this->aniState == ENTITY_ANIMATION_STATE::IDLE)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;
            if (this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVING_RIGHT)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 0.f;
            if (this->currentFrame.left >= 0.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVING_LEFT)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 0.f;
            if (this->currentFrame.left >= 0.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVE_UP)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 0.f;
            if (this->currentFrame.left >= 0.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVE_DOWN)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;
            this->currentFrame.left += 0.f;
            if (this->currentFrame.left >= 0.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

}
void Ghost::update()
{
    //this->updateMovement();
    this->updateAnimations();
}

void Ghost::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

//void Ghost::update_target(unsigned char i_entity_direction, const Position &i_ghost_position,
//                          const Position &i_entity_position)
//{
//    target = i_entity_position;
//}

/*Position Ghost::get_position()
{
    return position;
}*/