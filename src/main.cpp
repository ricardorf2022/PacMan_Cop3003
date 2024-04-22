#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Labyrinth.h"
#include "Entity.h"


int main() {

    sf::RenderWindow window(sf::VideoMode(1080,1080), "SFML PROJECT");
    window.setFramerateLimit(60);

    Game game(window);
    Labyrinth map(window);

    sf::Event events;
    while(window.isOpen()){
        while (window.pollEvent(events)) {
            if (events.Event::type == sf::Event::Closed)             // if user click the 'X' it will close the window
                window.close();

            if (events.Event::key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear();
        game.runGame();// nothing blibks
        map.initialize();
        map.load();
        map.update();
        //window.display();  //this displays the blinking map

        game.render();//pac girl not blinking

    }















    return 0;
}