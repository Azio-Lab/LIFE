//
//  Ant.h
//  Life
//
//  Created by Blaze Yang on 2014/12/17.
//
//

#ifndef __Life__Ant__
#define __Life__Ant__

#include "cocos2d.h"
#include "sqlite3.h"
#include <string>
using namespace cocos2d;
using namespace std;

class Ant : public Sprite
{
public:
    Ant();
    
private:
    int id;
    string name;
    string description;
    string imageName;
    string headImageName;
    float deathRate;
    float rarity;
    int price;
    string material;
    
    RepeatForever *moving();
    RepeatForever *action();
};


#endif /* defined(__Life__Ant__) */