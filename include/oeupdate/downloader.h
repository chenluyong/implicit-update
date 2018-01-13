#ifndef OELIB_DOWNLOADER_H
#define OELIB_DOWNLOADER_H

#include "update_global.h"
#include <iostream>

namespace oe {

class OEDownloaderPrivate;
class OEServer;
class OEClient;
class OEFile;
class OEUPDATESHARED_EXPORT OEDownloader
{
public:

    enum StatusCode // Returned by DownloadFile
    {
        OK,
        InvalidNetwork,
        InvalidAddress,
        InvalidType
    };

    struct DownloadReturn {
        DownloadReturn(StatusCode status = OK):
            status(status) {}
        StatusCode status;
    };

public:
    OEDownloader(OEServer* const _server, OEClient* const _client);

public:

    virtual DownloadReturn downloadFile(const OEFile &_file);

    virtual DownloadReturn downloadDone(void);

protected:

    virtual DownloadReturn downloadFileFromHttp(const OEFile &_file);

    virtual DownloadReturn downloadFileFromFtp(const OEFile &_file);

private:
    friend class OEServer;
    OEDownloaderPrivate* d_ptr;
    Q_DECLARE_PRIVATE(OEDownloader)

};

}

#endif // OELIB_DOWNLOADER_H
