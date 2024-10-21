#pragma once
#include "Entity.h"
class Player :
    public Entity
{
private:
    void initVarialbes();
    void initComponenets();


public:
    Player(float x, float y, const sf::String tex);
    virtual ~Player();



};

