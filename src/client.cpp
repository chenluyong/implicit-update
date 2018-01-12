#include "client.h"
#include <iostream>

#include "server.h"
#include "file.h"
namespace oe {

class OEClientPrivate {
public:
    OEClientPrivate(OEClient* const parent)
        :q_ptr(parent) {
        version_ = OE_VERSION(1,1,1,1);
    }

    Q_DECLARE_PUBLIC(OEClient)
    class OEClient* q_ptr;


private:
    std::list<OEFile> listFile_;
    int version_;
};


OEClient::OEClient(void)
    :d_ptr(new OEClientPrivate(this))
{
    // get current version
}

int OEClient::setVersion(int _version)
{
    Q_D(OEClient);
    d->version_ = _version;
    return OELIB_SUCCESS;
}

int OEClient::getVersion(void) const
{
    const OEClientPrivate* const d = d_func();
    return d->version_;
}

int OEClient::update(void)
{
    return OELIB_SUCCESS;
}

const std::list<OEFile> &OEClient::getAllFile(void)
{
    Q_D(OEClient);
    return d->listFile_;
}

bool OEClient::operator ==(const OEServer &_ser)
{
    return (_ser.getVersion() == this->getVersion());
}

bool OEClient::operator !=(const OEServer &_ser)
{
    return (_ser.getVersion() != this->getVersion());
}

}
