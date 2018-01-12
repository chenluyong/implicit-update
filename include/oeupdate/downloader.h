#ifndef OELIB_DOWNLOADER_H
#define OELIB_DOWNLOADER_H

#include "update_global.h"

namespace oe {

class OEDownloaderPrivate;
class OEServer;
class OEClient;
class OEFile;
class OEUPDATESHARED_EXPORT OEDownloader
{
public:
    OEDownloader(OEServer* const _server, OEClient* const _client);

public:

    virtual int downloadFile(const OEFile &_file);

    virtual int downloadDone(void);

protected:

    virtual int downloadFileFromHttp(const OEFile &_file);

    virtual int downloadFileFromFtp(const OEFile &_file);

private:
    friend class OEServer;
    OEDownloaderPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEDownloader)

};

}

#endif // OELIB_DOWNLOADER_H
