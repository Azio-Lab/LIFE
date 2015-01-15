//
//  DatabaseHandler.cpp
//  Life
//
//  Created by Blaze Yang on 2015/1/15.
//
//

#include "DatabaseHandler.h"

sqlite3* DatabaseHandler::open() {
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
    
    if (sqlite3_open(dbPath.c_str(), &lifeDB) == SQLITE_OK) {
        return lifeDB;
    }
    
    sqlite3_close(lifeDB);
    return NULL;
}

AntClass* DatabaseHandler::getAntClassById(int antClassId)
{
    sqlite3* lifeDB = DatabaseHandler::open();
    if (lifeDB == NULL) {
        sqlite3_close(lifeDB);
        return NULL;
    }
    
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
    
    return antClass;
}