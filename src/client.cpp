#include "client.h"
#include <iostream>

#include "server.h"

class OEClientPrivate {
public:

    Q_DECLARE_PUBLIC(OEClient)
    class OEClient* q_ptr;


private:

    int version_;
};


OEClient::OEClient()
    :d_ptr(new OEClientPrivate())
{
    // 获取当前版本
}

int OEClient::setVersion(int _version)
{
    Q_D(OEClient);
    d->version_ = _version;
    return 0;
}

int OEClient::getVersion() const
{
    return 0;
}

bool OEClient::operator ==(const OEServer &_ser)
{
    return _ser.getVersion() == this->getVersion();
}
