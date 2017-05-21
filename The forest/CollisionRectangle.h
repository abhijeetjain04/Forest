#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
 
class CCollisionRectangle
{
public:
    CCollisionRectangle();
    CCollisionRectangle(int x, int y, int w, int h);
    ~CCollisionRectangle(void);
 
    void SetRectangle(int x, int y, int w, int h);
    SDL_Rect GetRectangle() { return CollisionRect; }
 
    void SetX(int x) { CollisionRect.x = x + OffsetX; }  
    void SetY(int y) { CollisionRect.y = y + OffsetY; }  
 
private:
    int OffsetX;
    int OffsetY;
    SDL_Rect CollisionRect;
};