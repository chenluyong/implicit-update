#include "update.h"
#include <iostream>


#include "client.h"
#include "server.h"
#include "file.h"
#include "downloader.h"
namespace oe {

class OEUpdatePrivate {

    OEUpdatePrivate(OEUpdate* const _parent)
        : q_ptr(_parent){

    }
public:
    Q_DECLARE_PUBLIC(OEUpdate)
    OEUpdate* const q_ptr;
private:
    OEServer* server_;
    OEClient* client_;
};

OEUpdate::OEUpdate(OEServer *_ser, OEClient *_clt)
    :d_ptr(new OEUpdatePrivate(this))
{
    Q_D(OEUpdate);
    d->server_ = _ser;
    d->client_ = _clt;
}

int OEUpdate::setServer(OEServer *_server)
{
    Q_D(OEUpdate);
    d->server_ = _server;
    return OELIB_SUCCESS;
}

int OEUpdate::setClient(OEClient *_client)
{
    Q_D(OEUpdate);
    d->client_ = _client;
    return OELIB_SUCCESS;
}

int OEUpdate::update(void)
{
    Q_D(OEUpdate);
    if (d->client_ == NULL
        || NULL == d->server_) {
#ifdef _DEBUG
        std::cout << "No server or client is set." << std::endl;
#endif
        return STD_ERROR_PARAM_ERROR;
    }
    // check server availability
    if (0 != d->server_->connect()) {
#ifdef _DEBUG
        std::cout << "server connect failed." << std::endl;
#endif
    }

    // update computer information
    d->server_->update();
    d->client_->update();

    if (d->client_->getVersion() == d->server_->getVersion())
            return OELIB_ERROR_HIGHEST_VERSION;



    // get download file
    std::vector<OEFile> sev_vec_file, clt_vec_file, download_file;
    d->server_->getAllFile(sev_vec_file);
    d->client_->getAllFile(clt_vec_file);

    // compare file
    int clt_file_size = 0;
    for (auto sev_file : sev_vec_file) {
        clt_file_size = clt_vec_file.size();
        for (int i = 0; i < clt_file_size; ++i) {
            if (sev_file == clt_vec_file.at(i)) {
                // check file
                if (sev_file.getCode() != clt_vec_file.at(i).getCode())
                    download_file.push_back(sev_file);
                // erase clt_file
                clt_vec_file.erase(clt_vec_file.begin()+i);
                break;
            }
        }
    }

    // begin download file to local
    OEDownloader::DownloadReturn ret = OEDownloader::OK;
    OEDownloader downloader(d->server_, d->client_);
    for (auto file : download_file) {
        ret = downloader.downloadFile(file);
        if (ret.status != OEDownloader::OK) {
#ifdef _DEBUG
            std::cout << "Download exception, error code:" << ret.status << std::endl;
#endif
        }
    }

    if (OEDownloader::OK != downloader.downloadDone().status) {
        return OELIB_ERROR;
    }

    return OELIB_SUCCESS;
}

int OEUpdate::asynUpdate(void)
{
    Q_D(OEUpdate);
    if (d->client_ == NULL
        || NULL == d->server_) {
#ifdef _DEBUG
        std::cout << "No server or client is set." << std::endl;
#endif
        return STD_ERROR_PARAM_ERROR;
    }
    return OELIB_SUCCESS;
}

}
