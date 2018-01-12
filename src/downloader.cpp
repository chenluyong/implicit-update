#include "downloader.h"
#include "file.h"
#include "server.h"

namespace oe {

class OEDownloaderPrivate {
    OEDownloaderPrivate(OEDownloader* const _parent)
        :q_ptr(_parent) {}
    Q_DECLARE_PUBLIC(OEDownloader)

private:
    OEServer* server_;
    OEClient* client_;
    OEDownloader* const q_ptr;

};

OEDownloader::OEDownloader(OEServer * const _server, OEClient * const _client)
    :d_ptr(new OEDownloaderPrivate(this)) {
    d_ptr->server_ = _server;
    d_ptr->client_ = _client;
}

int OEDownloader::downloadFile(const OEFile &_file) {
    if (!_file.isValid())
        return STD_ERROR_PARAM_ERROR;

    switch (_file.getFileType()) {
    case OEFile::FTP:
        downloadFileFromFtp(_file);
        break;
    case OEFile::HTTP:
        downloadFileFromHttp(_file);
        break;
    case OEFile::LOCAL:
        return STD_ERROR_NETWORK_DOWNLOAD_FILE;
    default:
        return STD_ERROR_TYPE;
    }

    return OELIB_SUCCESS;
}

int OEDownloader::downloadDone(void) {
    return OELIB_SUCCESS;
}

int OEDownloader::downloadFileFromHttp(const OEFile &_file)
{
    const std::string& src_path = _file.getNetworkPath();
    if (src_path.empty())
        return STD_ERROR_PARAM_ERROR;

    return OELIB_SUCCESS;
}

int OEDownloader::downloadFileFromFtp(const OEFile &_file)
{
    const std::string& src_path = _file.getNetworkPath();
    if (src_path.empty())
        return STD_ERROR_PARAM_ERROR;

    return OELIB_SUCCESS;
}



}
