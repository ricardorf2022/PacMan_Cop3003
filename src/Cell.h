//
// Created by Ricardo on 4/22/2024.
//

#ifndef CMAKESFMLPROJECT_CELL_H
#define CMAKESFMLPROJECT_CELL_H
#include <iostream>
#include "GLOBAL.h"
#include "SFML/Graphics.hpp"

class Cell {
private:

    sf::Vector2f coord;
    //Cell type
    CellType _cellType;

    //for walls
    bool topWall;
    bool bottomWall;
    bool leftWall;
    bool rightWall;
    struct CellData{
        bool topWall;
        bool bottomWall;
        bool leftWall;
        bool rightWall;
    };
    CellData cellData;


    //cells positions
    float xPos;
    float yPos;


    //Private Functions
    void setWallType();

public:

    Cell();

    int getWallType();
    std::string getCell(int row, int col);


    //get and set current cells position
    sf::Vector2f getCellPos() {return {xPos, yPos};}
    void setCellPosition(int row, int col);


    //set and get the current cells enumerator type
    void setCellType(CellType cellType) {_cellType = cellType;}
    CellType getCellType() {return _cellType;}


    //sets and gets the status of surround walls if cell is a wall
    void setWalls(WallDirection direction, bool wallBool);
    std::tuple<bool,bool,bool,bool> getAllWalls();
};



#endif //CMAKESFMLPROJECT_CELL_H
