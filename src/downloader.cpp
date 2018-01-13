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

OEDownloader::DownloadReturn OEDownloader::downloadFile(const OEFile &_file) {
    if (!_file.isValid())
        return DownloadReturn(InvalidType);
    DownloadReturn ret = OK;
    switch (_file.getFileType()) {
    case OEFile::FTP:
        ret = downloadFileFromFtp(_file);
        break;
    case OEFile::HTTP:
        ret = downloadFileFromHttp(_file);
        break;
    case OEFile::LOCAL:
        ret = DownloadReturn(InvalidAddress);
    default:
        ret = DownloadReturn(InvalidType);
    }

    return ret;
}

OEDownloader::DownloadReturn OEDownloader::downloadDone(void) {
    return DownloadReturn(OK);
}

OEDownloader::DownloadReturn OEDownloader::downloadFileFromHttp(const OEFile &_file)
{
    const std::string& src_path = _file.getNetworkPath();
    if (src_path.empty())
        return InvalidType;

    return OK;
}

OEDownloader::DownloadReturn OEDownloader::downloadFileFromFtp(const OEFile &_file)
{
    const std::string& src_path = _file.getNetworkPath();
    if (src_path.empty())
        return InvalidType;

    return OK;
}



}
