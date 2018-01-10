#ifndef OELIB_CLIENT_H
#define OELIB_CLIENT_H


#include "update_global.h"

class OEServer;
class OEClientPrivate;
class OEUPDATESHARED_EXPORT OEClient
{
public:
    OEClient();

    int setVersion(int _version);

    int getVersion(void) const;

    bool operator == (const OEServer&  _ser);


private:
    friend class OEServer;
    OEClientPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEClient)

};

#endif // OELIB_CLIENT_H
