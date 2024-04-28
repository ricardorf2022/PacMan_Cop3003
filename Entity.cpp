//
// Created by kiara on 4/3/2024.
//
#include <cmath>
#include<array>
#include "GLOBAL.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void Entity::initVariables()
{
    this->aniState = ENTITY_ANIMATION_STATE::IDLE; // or can just use IDLE but this is coming from the ENUM

}


/**
 *
 */
void Entity::initTexture()
{
    // Error message will appear if specific png file in not in assets folder

    if (!this->texture.loadFromFile("../../assets/PacGirly.png") )
    {
        std::cout << "ERROR::ENTITY::INITTEXTURE::Could not load texture file" << std::endl ;
    }

}

/**
 *
 */
void Entity::initSprite()
{
    //setting the texture for the sprite
    this->sprite.setTexture(this->texture); // takes  the reference of a texture

    this->currentFrame = sf::IntRect(0,0,64,64);
    this->sprite.setTextureRect(currentFrame);    // rending a small bit of out texture

    //resize the sprite
    this->sprite.scale(.4f,.4f);        // putting (1.f,1.f) is going to be the original size of the image

    this->sprite.setPosition(500.f,450.f);        //set position of the sprite everytime in the middle of the screen


}

/**
 *
 */
void Entity::initAnimations()
{
    this->animationTimer.restart();

}


/**
 *  Constructor
 */
Entity::Entity()
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->initAnimations();
}

/**
 *
 */
Entity::~Entity()
{

}

void Entity::move(const float dirX, const float dirY)
{

    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);

}


/**
 *
 */
void Entity::updateMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //MOVE LEFT
    {
        this->sprite.move(-1.5f, 0.f);
        this->aniState = ENTITY_ANIMATION_STATE::MOVING_LEFT;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // MOVE RIGHT
    {
        this->sprite.move(1.5f, 0.f);
        this->aniState = ENTITY_ANIMATION_STATE::MOVING_RIGHT;

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //MOVE UP
    {
        this->sprite.move(0.f, -1.5f);
        this->aniState = ENTITY_ANIMATION_STATE::MOVE_UP;

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // MOVE DOWN
    {
        this->sprite.move(0.f, 1.5f);
        this->aniState = ENTITY_ANIMATION_STATE::MOVE_DOWN;

    }

}
void Entity::updateAnimations() //maybe create a separate class for animations ??
{
    //CURRENTLY NOT USING IDLE
    if(this->aniState == ENTITY_ANIMATION_STATE::IDLE)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;
            if (this->currentFrame.left >= 128.f) // to the nex
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVING_RIGHT)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 0.f;   //getting the first row my texture
            this->currentFrame.left += 64.f; // getting the first row
            if (this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVING_LEFT)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 64.f;
            this->currentFrame.left += 64.f;
            if (this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVE_UP)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 128.f;
            this->currentFrame.left += 64.f;
            if (this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

    else if (this->aniState == ENTITY_ANIMATION_STATE::MOVE_DOWN)
    {
        if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
        {
            this->currentFrame.top = 192.f;
            this->currentFrame.left += 64.f;
            if (this->currentFrame.left >= 128.f)
                this->currentFrame.left = 0;

            this->animationTimer.restart();
            this->sprite.setTextureRect(this->currentFrame);
        }
    }

}

void Entity::update()
{
    this->updateMovement();
    this->updateAnimations();
}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}