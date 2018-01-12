#include "update.h"
#include <iostream>


#include "client.h"
#include "server.h"
#include "file.h"
namespace oe {

OEUpdate::OEUpdate()
{
}

int OEUpdate::setServer(OEServer *_server)
{
    server_ = _server;
    return 0;
}

int OEUpdate::setClient(OEClient *_client)
{
    client_ = _client;
    return 0;
}

int OEUpdate::update()
{
    if (client_ == nullptr
        || nullptr == server_) {
#ifdef _DEBUG
        std::cout << "No server or client is set." << std::endl;
#endif
        return STD_PARAM_ERROR;
    }
    // check server availability
    if (0 != server_->connect()) {
#ifdef _DEBUG
        std::cout << "server connect failed." << std::endl;
#endif
    }

    // update computer information
    server_->update();
    client_->update();

    //
    std::list<OEFile> sev_list_file = server_->getAllFile();
    std::list<OEFile> clt_list_file = client_->getAllFile();
    std::list<OEFile> download_file;

//    for (const OEFile& sev_file : sev_list_file) {
//        for (const OEFile& clt_file : clt_list_file) {
//            if (sev_file == clt_file) {
//                break;
//            }
//        }
//    }

    std::cout << "Update." << std::endl;
    return 0;
}

int OEUpdate::asynUpdate()
{
    if (client_ == nullptr
        || nullptr == server_) {
#ifdef _DEBUG
        std::cout << "No server or client is set." << std::endl;
#endif
        return STD_PARAM_ERROR;
    }
    return 0;
}

}
