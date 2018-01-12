#include "file.h"

namespace oe {

class OEFilePrivate {

    OEFilePrivate(OEFile* _parent)
        :q_ptr(_parent) {}

    Q_DECLARE_PUBLIC(OEFile)

private:
    class OEFile* q_ptr;
    std::string version_;
    OEFile::Type type_;
    // file path (if the type is HTTP, the path is URL.)
    std::string path_;
    // download to local, in software relative path/filename.
    // example: res/logo.png
    std::string fileName_;
    // file MD5
    std::string code_;
};


OEFile::OEFile(void)
    :d_ptr(new OEFilePrivate(this))
{
}

bool OEFile::isValid(void) const
{
    const Q_D(OEFile);
    return !(d->fileName_.empty());
}

const std::string &OEFile::getCode(void) const
{
    const Q_D(OEFile);
    return d->code_;
}

const OEFile::Type &OEFile::getFileType(void) const
{
    const Q_D(OEFile);
    return d->type_;
}


const std::string &OEFile::getFileName(void) const
{
    const Q_D(OEFile);
    return d->fileName_;
}

const std::string &OEFile::getNetworkPath() const
{
    const Q_D(OEFile);
    return d->path_;
}

bool OEFile::operator ==(const OEFile &_file) const
{
    return (this->getFileName() == _file.getFileName());
}

bool OEFile::operator !=(const OEFile &_file) const
{
    return (this->getFileName() != _file.getFileName());
}

}
