#ifndef OELIB_CLIENT_H
#define OELIB_CLIENT_H


#include <vector>
#include <string>

#include "update_global.h"
#include "host.h"
// io.h
struct _finddata32_t;

namespace oe {

class OEServer;
class OEClientPrivate;
class OEFile;


class OEUPDATESHARED_EXPORT OEClient : public OEHost
{
public:
    OEClient(void);


    int update(void);

protected:


    /// @brief : update local file information
    /// @remark: After the operation, you will have
    ///          the latest local file information.
    ///          `getAllFile` will be influenced.
    int updateLocalFileInfo(void);

private:

    int traverseDir(const std::string &_dir);
    /// @brief : `traverseDir` call `traverseRoute`
    /// @param : _filePath file abs path
    /// @param : _fileData file information
    /// @remark:
    int OELIB_CALLBACK traverseRoute(const std::string &_filePath,
                                             const _finddata32_t &_fileData);


private:
    friend class OEServer;
    OEClientPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEClient)

};

}
#endif // OELIB_CLIENT_H
