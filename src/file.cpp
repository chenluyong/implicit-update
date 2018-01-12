#include "file.h"

namespace oe {

class OEFilePrivate {


    Q_DECLARE_PUBLIC(OEFile)

private:
    class OEFile* q_ptr;
    std::string version_;
    OEFile::Type type_;
    // file path (if the type is HTTP, the path is URL.)
    std::string path_;
    // file MD5
    std::string code_;
};


OEFile::OEFile()
{

}

inline bool OEFile::isValid() const
{
    const Q_D(OEFile);
    return !(d->path_.empty());
}

inline const std::string &OEFile::getCode() const
{
    const Q_D(OEFile);
    return d->code_;
}

inline const OEFile::Type &OEFile::getFileType() const
{
    const Q_D(OEFile);
    return d->type_;;
}

inline const std::string &OEFile::getFilePath() const
{
    const Q_D(OEFile);
    return d->path_;
}

inline bool OEFile::operator ==(const OEFile &_file) const
{
    return this->getCode() == _file.getCode();
}

inline bool OEFile::operator !=(const OEFile &_file) const
{
    return this->getCode() != _file.getCode();
}

}
