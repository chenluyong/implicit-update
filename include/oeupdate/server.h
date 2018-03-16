#ifndef OELIB_SERVER_H
#define OELIB_SERVER_H

#include <iostream>
#include <vector>

#include "update_global.h"
#include "host.h"
namespace oe {

class OEFile;
class OEClient;
class OEServerPrivate;
class OEUPDATESHARED_EXPORT OEServer : public OEHost
{
public:
    OEServer(void);



public:
    virtual int connect(const std::string &_ip = "", const int _port = 0);

    virtual int update(void);

    virtual int disConnect(void);

    int getAllFile(std::vector<OEFile> *_vecFile);

    // attribute operate
public:


private:


    friend class OEClient;
    OEServerPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEServer)
};

}
#endif // OELIB_SERVER_H
