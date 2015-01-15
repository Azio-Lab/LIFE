//
//  Ant.cpp
//  Life
//
//  Created by Blaze Yang on 2014/12/17.
//
//

#include "Ant.h"
#include "HelloWorldScene.h"
#include "DatabaseHandler.h"

USING_NS_CC;

Ant::Ant(AntClass *antClass)
{
    mAntClass = new AntClass(antClass);
    // 1. load a default image
    ostringstream oss;
    oss << mAntClass->getAntImageName() << 1 << ".png";
    string antImageName = oss.str();
    //initWithSpriteFrameName(antImageName);
    initWithSpriteFrameName("queen1.png");
    
    this->setAnchorPoint(Vec2(0.5, 0));
    //this->setScale(0.5);
    // 2. run the move action
    //auto mySpawn = Spawn::createWithTwoActions(action(), moving());
    //this->runAction(action());
    //this->runAction(moving());
    
    
}

Ant::Ant(int antClassId) {
    //Ant(DatabaseHandler::getAntClassById(antClassId));
    
    sqlite3 *lifeDB = NULL;
    
    std::string dbPath  = cocos2d::FileUtils::getInstance()->fullPathForFilename("life.sqlite3");
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    dbPath  = CCFileUtils::sharedFileUtils()->getWritablePath();
    dbPath  += "life.sqlite3";
    
    FILE* file = fopen(dbPath.c_str(), "r");
    if (file == nullptr)
    {
        long size;
        const char* data = (char*) cocos2d::FileUtils::getInstance()->getFileData("life.sqlite3", "rb", &size);
        file = fopen(dbPath.c_str(), "wb");
        fwrite(data, size, 1, file);
        CC_SAFE_DELETE_ARRAY(data);
    }
    fclose(file);
#endif
    
    sqlite3_open(dbPath.c_str(), &lifeDB);
    
    char **re;
    char *err;
    int r,c;
    
    char *sql;
    sprintf(sql, "SELECT * FROM antClass WHERE antClassId = %d", antClassId);
    //ostringstream oss;
    //oss << "SELECT * FROM antClass WHERE antClassId = " << antClassId << ".png";
    //string antImageName = oss.str();
    
    sqlite3_get_table(lifeDB, sql,&re,&r,&c,&err);
    AntClass* antClass = new AntClass(atoi(*(re+c)), re[c+1], *(re+c+2), re[c+3], re[c+4], atof(re[c+5]), atof(re[c+6]), atoi(re[c+7]), re[c+8], atoi(re[c+9]));
    sqlite3_free_table(re);
    sqlite3_close(lifeDB);
    
    Ant(antClass);
}

Ant::~Ant() {
    delete mAntClass;
}

RepeatForever* Ant::action()
{
    // 3. repeat the frame
    int numFrame = 3;
    
    cocos2d::Vector<cocos2d::SpriteFrame *> frames;
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    
    for (int i = 0; i < numFrame; i++) {
        ostringstream oss;
        oss << mAntClass->getAntImageName() << i+1 << ".png";
        string antImageName = oss.str();
        SpriteFrame *frame = frameCache->getSpriteFrameByName(oss.str());
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