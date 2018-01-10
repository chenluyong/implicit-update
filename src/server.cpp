#include "server.h"
#include "client.h"
OEServer::OEServer()
{

}

int OEServer::getVersion() const
{
    return 0;
}

bool OEServer::operator ==(const OEClient &_ser) const
{
    return _ser.getVersion() == this->getVersion();
}
