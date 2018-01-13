#include <iostream>
#include <update.h>
#include <client.h>
#include <server.h>

using namespace oe;

int main(void) {
    OEUpdate u;
    OEClient c;
    c.update();
    OEServer s;
    u.setClient(&c);
    u.setServer(&s);
    if (c != s) {
        std::cout << "is latest version." << std::endl;
    }
    else {
        u.update();
        u.asynUpdate();
    }
    system("pause");
    return 0;
}
