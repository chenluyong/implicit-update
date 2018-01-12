#ifndef OELIB_UPDATE_H
#define OELIB_UPDATE_H

#include "update_global.h"

namespace oe {

class OEServer;
class OEClient;

class OEUPDATESHARED_EXPORT OEUpdate
{

public:
    OEUpdate();


    int setServer(OEServer* _ser);

    int setClient(OEClient* _clt);

    int update(void);

    int asynUpdate(void);

protected:



private:

    OEServer* server_;
    OEClient* client_;

};

}
#endif // OELIB_UPDATE_H
