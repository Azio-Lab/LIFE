//
//  DatabaseHandler.h
//  Life
//
//  Created by Blaze Yang on 2015/1/15.
//
//

#ifndef __Life__DatabaseHandler__
#define __Life__DatabaseHandler__

#include <stdio.h>
#include "sqlite3.h"
#include "AntClass.h"

class DatabaseHandler {
public:
    static AntClass* getAntClassById(int antClassId);
//private:
    static sqlite3* open();
};
#endif /* defined(__Life__DatabaseHandler__) */
