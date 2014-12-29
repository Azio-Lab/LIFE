//
//  Ant.cpp
//  Life
//
//  Created by Blaze Yang on 2014/12/17.
//
//

#include "Ant.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Ant::Ant()
{
    // 1. load a default image
    initWithSpriteFrameName("queen1.png");
    
    this->setAnchorPoint(Vec2(0.5, 0));
    //this->setScale(0.5);
    // 2. run the move action
    //auto mySpawn = Spawn::createWithTwoActions(action(), moving());
    this->runAction(action());
    this->runAction(moving());
    
    sqlite3 *antClass = NULL;
    std::string path = FileUtils::sharedFileUtils()->getWritablePath()+"citybus.sqlite3";
    
    std::string sql;
    int result;
    result = sqlite3_open(path.c_str(), &antClass);
    if (result != SQLITE_OK) {
        log("open database failed,  number%d",result);
    }
}

RepeatForever* Ant::action()
{
    // 3. repeat the frame
    int numFrame = 3;
    
    cocos2d::Vector<cocos2d::SpriteFrame *> frames;
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    
    char file[100] = {0};
    
    for (int i = 0; i < numFrame; i++) {
        sprintf(file, "queen%1d.png", i+1);
        SpriteFrame *frame = frameCache->getSpriteFrameByName(file);
        frames.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frames, 0.5);
    Animate *animate = Animate::create(animation);
    
    RepeatForever *repeat = RepeatForever::create(animate);
    return repeat;
}

RepeatForever* Ant::moving()
{
    auto move = MoveBy::create(4, Vec2(300, 200));
    auto move_back = move->reverse();
    
    auto move2 = MoveBy::create(4, Vec2(-300, 400));
    auto move2_back = move2->reverse();
    
    auto scale = ScaleBy::create(4, 0.5);
    auto scale_back = ScaleBy::create(4, 2);
    
    auto spawn_move = Spawn::createWithTwoActions(move, scale);
    auto spawn_move2 = Spawn::createWithTwoActions(move2, scale);
    
    auto spawn_move_back = Spawn::createWithTwoActions(move_back, scale_back);
    auto spawn_move2_back = Spawn::createWithTwoActions(move2_back, scale_back);
    
    //auto move_ease_in = EaseBounceIn::create(move->clone());
    //auto move_ease_in_back = EaseBounceIn::create(move_back->clone());
    auto move_ease_in_out = EaseInOut::create(move->clone(), 2.f);
    auto move_back_ease_in_out = EaseInOut::create(move_back->clone(), 2.f);
    
    auto move2_ease_in_out = EaseInOut::create(move2->clone(), 2.f);
    auto move2_back_ease_in_out = EaseInOut::create(move2_back->clone(), 2.f);
    
    auto delay = DelayTime::create(0.25f);
    
    auto flipRight = FlipX::create(true);
    
    auto flipLeft = FlipX::create(false);
    
    auto seq = Sequence::create(flipRight->clone(), spawn_move, delay->clone(), flipLeft->clone(), spawn_move2, delay->clone(), flipRight->clone(), spawn_move2_back,  delay->clone(), flipLeft->clone(), spawn_move_back, delay->clone(), nullptr);
    
    RepeatForever *repeat = RepeatForever::create(seq);
    return repeat;
}