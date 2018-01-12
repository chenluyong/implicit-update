#ifndef OELIB_SERVER_H
#define OELIB_SERVER_H

#include <iostream>
#include <list>

#include "update_global.h"

namespace oe {

class OEFile;
class OEClient;
class OEServerPrivate;
class OEUPDATESHARED_EXPORT OEServer
{
public:
    OEServer();



public:
    virtual int connect(const std::string &_ip = "", const int _port = 0);

    virtual int update(void);

    virtual int disConnect(void);

    // attribute operate
public:

    int getVersion(void) const;

    std::list<OEFile> getAllFile(void);



public:

    bool operator == (const OEClient&  _ser) const ;

private:


    friend class OEClient;
    OEServerPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEServer)
};

}
#endif // OELIB_SERVER_H
