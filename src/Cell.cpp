//
// Created by Ricardo on 4/22/2024.
//
#include <iostream>
#include "Cell.h"

Cell::Cell(){
    xPos = 0.f;
    yPos = 0.f;
    topWall = false;
    bottomWall = false;
    leftWall = false;
    rightWall = false;
    cellData.topWall = false;
    cellData.bottomWall = false;
    cellData.leftWall = false;
    cellData.rightWall = false;
}

int Cell::getWallType() { //determines all sides of wall
    ////////////////////////////////////////////////////////
    if(topWall && bottomWall && !rightWall && !leftWall) {
        return 1;
    }
    else if(topWall && rightWall && !leftWall && !bottomWall){
        return 2;
    }
    else if(bottomWall && rightWall && !leftWall && !topWall){
        return 3;
    }
    else if(leftWall && bottomWall && !topWall && !rightWall) {
        return 4;
    }
    else if(leftWall && rightWall && !topWall && !bottomWall) {
        return 5;
    }
    else if(leftWall && topWall && !bottomWall && !rightWall){
        return 6;
    }
    else if(topWall && bottomWall && rightWall && !leftWall) {
        return 7;
    }
    else if(leftWall && rightWall && bottomWall && !topWall){
        return 8;
    }
    else if(leftWall && !rightWall && !topWall && !bottomWall){
        return 9;
    }
    else if(leftWall && rightWall && topWall && !bottomWall){
        return 10;
    }
    else{
        return 11;
    }
}


std::string Cell::getCell(int row, int col) {

}

void Cell::setCellPosition(int row, int col) {
    xPos = (CELL_SIZE * col) + 480.f;
    yPos = (CELL_SIZE * row);
}

void Cell::setWalls(WallDirection direction, bool wallBool) {
    switch (direction) {
        case WallDirection::Up:
            topWall = wallBool;
            break;
        case WallDirection::Down:
            bottomWall = wallBool;
            break;
        case WallDirection::Left:
            leftWall = wallBool;
            break;
        case WallDirection::Right:
            rightWall = wallBool;
            break;
    }
}

//Returns all bools via tuple
std::tuple<bool, bool, bool, bool> Cell::getAllWalls() {
    return std::make_tuple(cellData.topWall, cellData.bottomWall, cellData.leftWall, cellData.rightWall);
}