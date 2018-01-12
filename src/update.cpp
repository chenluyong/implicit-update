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

OEUpdate::OEUpdate(void)
    :d_ptr(new OEUpdatePrivate(this))
{
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
    if (d->client_ == nullptr
        || nullptr == d->server_) {
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
    std::list<OEFile> sev_list_file = d->server_->getAllFile();
    std::list<OEFile> clt_list_file = d->client_->getAllFile();
    std::list<OEFile> download_file;

    // compare file
    for (auto sev_file : sev_list_file) {
        for (auto clt_file : clt_list_file) {
            if (sev_file == clt_file) {
                if (sev_file.getCode() != clt_file.getCode())
                    download_file.push_back(sev_file);
                break;
            }
        }
    }

    // begin download file to local
    int ret = 0;
    OEDownloader downloader(d->server_, d->client_);
    for (auto file : download_file) {
        ret = downloader.downloadFile(file);
        if (0 != ret) {
#ifdef _DEBUG
            std::cout << "Download exception, error code:" << ret << std::endl;
#endif
        }
    }

    return downloader.downloadDone();
}

int OEUpdate::asynUpdate(void)
{
    Q_D(OEUpdate);
    if (d->client_ == nullptr
        || nullptr == d->server_) {
#ifdef _DEBUG
        std::cout << "No server or client is set." << std::endl;
#endif
        return STD_ERROR_PARAM_ERROR;
    }
    return OELIB_SUCCESS;
}

}
