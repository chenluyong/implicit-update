#ifndef HOST_H
#define HOST_H

#include "update_global.h"
#include <vector>
namespace oe {

class OEHostPrivate;
class OEFile;

class OEUPDATESHARED_EXPORT OEHost
{
public:
    OEHost();

    int getVersion(void) const;


    int getAllFile(std::vector<OEFile>* const _vecFile);

protected:

    void addFile(const OEFile &_file);

    void setAllFile(const std::vector<OEFile> & _vecFile);

    void setVersion(int _ver);

public:
    bool operator == (const OEHost&  _ser);
    bool operator != (const OEHost&  _ser);

private:
    OEHostPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEHost)
};

}

#endif // HOST_H
