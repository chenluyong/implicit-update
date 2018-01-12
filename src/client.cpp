#include "client.h"
#include <iostream>

#include "server.h"
#include "file.h"
namespace oe {

class OEClientPrivate {
public:

    Q_DECLARE_PUBLIC(OEClient)
    class OEClient* q_ptr;


private:
    std::list<OEFile> listFile_;
    int version_;
};


OEClient::OEClient()
    :d_ptr(new OEClientPrivate())
{
    // get current version
}

int OEClient::setVersion(int _version)
{
    Q_D(OEClient);
    d->version_ = _version;
    return 0;
}

int OEClient::getVersion() const
{
    const OEClientPrivate* const d = d_func();
    return d->version_;
}

int OEClient::update()
{
    return 0;
}

std::list<OEFile> OEClient::getAllFile()
{
    Q_D(OEClient);
    return d->listFile_;
}

bool OEClient::operator ==(const OEServer &_ser)
{
    return _ser.getVersion() == this->getVersion();
}

}
