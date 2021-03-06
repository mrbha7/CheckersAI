//
//  Sprite.cpp
//  Checkers
//
//  Created by Bhavish Bhattar on 6/22/18.
//  Copyright © 2018 Bhavish Bhattar. All rights reserved.
//

#include "Sprite.hpp"
#include "Graphics.h"

Sprite::Sprite(){
}

Sprite::Sprite(Graphics &graphics, const string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY):
    _x(posX),
    _y(posY)
{
    this->_sourceRect.x = sourceX;
    this->_sourceRect.y = sourceY;
    this->_sourceRect.w = width;
    this->_sourceRect.h = height;
    
    this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if(this->_spriteSheet == NULL){
        printf("\nError: Unable to load image \n");
    }
}

Sprite::~Sprite(){}

void Sprite::draw(Graphics &graphics, int x, int y){
    SDL_Rect destinationRectangle = {x, y, this->_sourceRect.w, this->_sourceRect.h};
    graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}
