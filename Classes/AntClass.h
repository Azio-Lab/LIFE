//
//  AntClass.h
//  Life
//
//  Created by Blaze Yang on 2015/1/13.
//
//

#ifndef __Life__AntClass__
#define __Life__AntClass__

#include <stdio.h>

using namespace std;

class AntClass
{
public:
    AntClass(int antId, char* name, char* description, char* antImageName,
             char* headImageName, double mDeathRate, double rarity, int price,
             char* material, int skill);
    AntClass(AntClass const *antClass);
    //AntClass(int antClassId);
    //AntClass();
    ~AntClass();
    int getAntId();
    string getName();
    string getDescription();
    string getAntImageName();
    string getHeadImageName();
    double getDeathRate();
    int getRarity();
    int getPrice();
    string getMaterial();
    int getSKill();
    
private:
    int mAntId;
    string mName;
    string mDescription;
    string mAntImageName;
    string mHeadImageName;
    double mDeathRate;
    double mRarity;
    int mPrice;
    string mMaterial;
    int mSkill;
};

#endif /* defined(__Life__AntClass__) */
