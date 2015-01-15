//
//  ItemClass.cpp
//  Life
//
//  Created by Blaze Yang on 2015/1/15.
//
//

#include "ItemClass.h"

ItemClass::ItemClass(int itemClassId, char* name, char* description, char* imageName, int price)
{
    mItemClassId = itemClassId;
    mName.assign(name);
    mDescription.assign(description);
    mImageName.assign(imageName);
    mPrice = price;
}

ItemClass::ItemClass(ItemClass const *itemClass)
{
    mItemClassId = itemClass->mItemClassId;
    mName = itemClass->mName;
    mDescription = itemClass->mDescription;
    mPrice = itemClass->mPrice;
}

ItemClass::ItemClass(int itemClassId)
{
   
}

ItemClass::~ItemClass() {
}

int ItemClass::getItemClassId() {
    return mItemClassId;
}

string ItemClass::getName() {
    return mName;
}

string ItemClass::getDescription() {
    return mDescription;
}

int ItemClass::getPrice() {
    return mPrice;
}