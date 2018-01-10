#ifndef OELIB_SERVER_H
#define OELIB_SERVER_H


#include "update_global.h"
class OEClient;
class OEUPDATESHARED_EXPORT OEServer
{
public:
    OEServer();

    int getVersion(void) const;


    bool operator == (const OEClient&  _ser) const ;


    friend class OEClient;
};

#endif // OELIB_SERVER_H
