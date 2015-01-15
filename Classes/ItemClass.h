//
//  ItemClass.h
//  Life
//
//  Created by Blaze Yang on 2015/1/15.
//
//

#ifndef __Life__ItemClass__
#define __Life__ItemClass__

#include <stdio.h>

using namespace std;

class ItemClass
{
public:
    ItemClass(int itemClassId, char* name, char* description, char* imageName, int price);
    ItemClass(int itemClassId);
    ItemClass(ItemClass const *itemClass);
    ~ItemClass();
    int getItemClassId();
    string getName();
    string getDescription();
    string getImageName();
    int getPrice();
    
protected:
    int mItemClassId;
    string mImageName;
    string mName;
    string mDescription;
    int mPrice;
};

#endif /* defined(__Life__ItemClass__) */
