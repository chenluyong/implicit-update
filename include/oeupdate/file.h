#ifndef OELIB_FILE_H
#define OELIB_FILE_H

#include <iostream>
#include "update_global.h"

namespace oe {

class OEFilePrivate;
class OEUPDATESHARED_EXPORT OEFile
{
public:
    enum Type {
        FTP=0,
        HTTP=1,
        LOCAL=2
    };

    OEFile(const std::string &_fileName, Type _type);

    // check file
    bool isValid(void) const;

    const std::string &getCode(void) const;

    const Type &getFileType(void) const;

    const std::string &getFileName(void) const;

    const std::string &getNetworkPath(void) const;

public:

    bool operator ==(const OEFile &_file) const;
    bool operator !=(const OEFile &_file) const;

private:

    friend class OEServer;
    OEFilePrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEFile)

};

}
#endif // OELIB_FILE_H
