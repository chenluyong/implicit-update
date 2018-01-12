#ifndef OELIB_UPDATE_H
#define OELIB_UPDATE_H

#include "update_global.h"

namespace oe {
class OEUpdatePrivate;
class OEServer;
class OEClient;
class OEFile;

class OEUPDATESHARED_EXPORT OEUpdate
{

public:
    OEUpdate();



    virtual int update(void);

    virtual int asynUpdate(void);

public:

    int setServer(OEServer* _ser);

    int setClient(OEClient* _clt);

private:

    OEUpdatePrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEUpdate)
};

}
#endif // OELIB_UPDATE_H
