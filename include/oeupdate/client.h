#ifndef OELIB_CLIENT_H
#define OELIB_CLIENT_H

#include <list>

#include "update_global.h"

namespace oe {

class OEServer;
class OEClientPrivate;
class OEFile;


class OEUPDATESHARED_EXPORT OEClient
{
public:
    OEClient(void);


    virtual int update(void);


public:
    int setVersion(int _version);

    int getVersion(void) const;

    const std::list<OEFile> &getAllFile(void);




public:

    bool operator == (const OEServer&  _ser);
    bool operator != (const OEServer&  _ser);

private:
    friend class OEServer;
    OEClientPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEClient)

};

}
#endif // OELIB_CLIENT_H
