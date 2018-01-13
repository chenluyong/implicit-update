#include "host.h"
#include <vector>
#include "file.h"

namespace oe {

class OEHostPrivate {
    OEHostPrivate(OEHost* const _parent)
        : q_ptr(_parent){
    }
public:
    Q_DECLARE_PUBLIC(OEHost)
    OEHost* const q_ptr;

private:
    int version_;
    std::vector<OEFile> vecFile_;
};


OEHost::OEHost()
    :d_ptr(new OEHostPrivate(this)) {

}

int OEHost::getVersion() const
{
    const Q_D(OEHost);
    return d->version_;
}

void OEHost::setAllFile(const std::vector<OEFile> &_vecFile)
{
    Q_D(OEHost);
    d->vecFile_.assign(_vecFile.begin(),_vecFile.end());
}

int OEHost::getAllFile(std::vector<OEFile> &_vecFile)
{
    Q_D(OEHost);
    if (d->vecFile_.empty())
        return OELIB_ERROR;

    _vecFile.assign(d->vecFile_.begin(),d->vecFile_.end());
    return OELIB_SUCCESS;
}

void OEHost::addFile(const OEFile &_file)
{
    Q_D(OEHost);
    d->vecFile_.push_back(_file);
}

void OEHost::setVersion(int _ver)
{
    Q_D(OEHost);
    d->version_ = _ver;
}

bool OEHost::operator ==(const OEHost &_ser)
{
    return (this->getVersion() == _ser.getVersion());
}

bool OEHost::operator !=(const OEHost &_ser)
{
    return (this->getVersion() != _ser.getVersion());
}

}
