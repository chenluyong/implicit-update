#include "server.h"
#include "client.h"
#include "file.h"
namespace oe {

class OEServerPrivate {
    OEServerPrivate(OEServer* const _parent)
        : q_ptr(_parent){

    }
public:
    Q_DECLARE_PUBLIC(OEServer)
    OEServer* const q_ptr;

private:
    std::list<OEFile> listFile_;
    int version_;
    std::string ip_;
    int port_;
    // with server connect status.
    bool connectSate_;
};


OEServer::OEServer(void)
    : d_ptr(new OEServerPrivate(this))
{
    // init server ip and port
    Q_D(OEServer);
    d->ip_ = "127.0.0.1";
    d->port_ = 19940;
    d->version_ = OE_VERSION(1,1,1,1);

}

int OEServer::connect(const std::string& _ip, const int _port)
{
    if ((_ip.empty() && (_port != 0))
            || (!_ip.empty() && (_port == 0))) {
#ifdef _DEBUG
        std::cout << "check params error" << std::endl;
        std::cout << "\t  IP :" << _ip.c_str() << std::endl;
        std::cout << "\t PORT:" << _port << std::endl;
#endif
        return STD_PARAM_ERROR;
    }
    Q_D(OEServer);

    if (d->connectSate_) {
        return STD_NETWORK_CONNECTED;
    }

    // try connect server
    int ret = 0;
    if (0 != ret)
        return OELIB_ERROR;

    // connect success, save ip and port to d_ptr.
    d->ip_ = _ip;
    d->port_ = _port;
    d->connectSate_ = true;
    return 0;
}

int OEServer::update(void)
{
    return 0;
}

int OEServer::disConnect(void)
{
    Q_D(OEServer);
    d->connectSate_ = false;
    return 0;
}

int OEServer::getVersion(void) const
{
    const Q_D(OEServer);
    return d->version_;
}

std::list<OEFile> OEServer::getAllFile(void)
{
//    Q_D(OEServer);
    return {};//d->listFile_;
}

bool OEServer::operator ==(const OEClient &_ser) const
{
    return _ser.getVersion() == this->getVersion();
}

}
