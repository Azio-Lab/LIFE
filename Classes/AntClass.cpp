//
//  AntClass.cpp
//  Life
//
//  Created by Blaze Yang on 2015/1/13.
//
//

#include "AntClass.h"

AntClass::AntClass(int antId, char* name, char* description, char* antImageName,
                   char* headImageName, double deathRate, double rarity, int price,
                   char* material, int skill)
{
    mAntId = antId;
    mName.assign(name);
    mDescription.assign(description);
    mAntImageName.assign(antImageName);
    mHeadImageName.assign(headImageName);
    mDeathRate = deathRate;
    mRarity = rarity;
    mPrice = price;
    mMaterial.assign(material);
    mSkill = skill;
}

AntClass::AntClass(const AntClass *antClass)
{
    mAntId = antClass->mAntId;
    mName = antClass->mName;
    mDescription = antClass->mDescription;
    mAntImageName = antClass->mAntImageName;
    mHeadImageName = antClass->mHeadImageName;
    mDeathRate = antClass->mDeathRate;
    mRarity = antClass->mRarity;
    mPrice = antClass->mPrice;
    mMaterial = antClass->mMaterial;
    mSkill = antClass->mSkill;
}

/*
AntClass::AntClass(int antClassId)
{
    char** antClassData = DatabaseHandler::getAntClassById(antClassId);
    mAntId = atoi(*(antClassData));
    mName.assign(*(antClassData+1));
    mDescription.assign(*(antClassData+2));
    mAntImageName.assign(*(antClassData+3));
    mHeadImageName.assign(*(antClassData+4));
    mDeathRate = atof(*(antClassData+5));
    mRarity = atof(*(antClassData+6));
    mPrice = atoi(*(antClassData+7));
    mMaterial.assign(*(antClassData+8));
    mSkill = atof(*(antClassData+9));
}

AntClass::AntClass()
{
    mAntId = -1;
    mName.assign("");
    mDescription.assign("");
    mAntImageName.assign("");
    mHeadImageName.assign("");
    mDeathRate = .0;
    mRarity = .0;
    mPrice = 0;
    mMaterial.assign("");
    mSkill = 0;
}
*/
AntClass::~AntClass() {
}

int AntClass::getAntId() {
    return mAntId;
}

string AntClass::getName() {
    return mName;
}

string AntClass::getDescription() {
    return mDescription;
}

string AntClass::getAntImageName() {
    return mAntImageName;
}

string AntClass::getHeadImageName() {
    return mHeadImageName;
}

double AntClass::getDeathRate() {
    return mDeathRate;
}

int AntClass::getRarity() {
    return mRarity;
}

int AntClass::getPrice() {
    return mPrice;
}

string AntClass::getMaterial() {
    return mMaterial;
}

int AntClass::getSKill() {
    return mSkill;
}