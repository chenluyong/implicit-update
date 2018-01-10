#include "update.h"
#include <iostream>


#include "client.h"
#include "server.h"

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
        return 87;
    }

    std::cout << "Update." << std::endl;
    return 0;
}
