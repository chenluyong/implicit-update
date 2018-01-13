#include "file.h"

namespace oe {

class OEFilePrivate {

    OEFilePrivate(OEFile* _parent, const std::string& _fileName, OEFile::Type _type)
        :q_ptr(_parent),fileName_(_fileName), type_(_type) {}

    Q_DECLARE_PUBLIC(OEFile)

private:
    class OEFile* q_ptr;
    std::string version_;
    // file path (if the type is HTTP, the path is URL.)
    std::string path_;
    // download to local, in software relative path/filename.
    // example: res/logo.png
    const std::string fileName_;
    // file type
    OEFile::Type type_;
    // file MD5
    std::string code_;
};


OEFile::OEFile(const std::string &_fileName, OEFile::Type _type)
    :d_ptr(new OEFilePrivate(this, _fileName, _type))
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

const std::string &OEFile::getNetworkPath(void) const
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
