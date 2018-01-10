#include <iostream>
#include <update.h>
#include <client.h>
#include <server.h>


int main(void) {
    OEUpdate u;
    OEClient c;
    OEServer s;
    u.setClient(&c);
    u.setServer(&s);
    if (c == s) {
        std::cout << "is latest version." << std::endl;
    }
    else {
        u.update();
    }
    std::cout << OE_VERSION(1,1,1,1) << std::endl;
    system("pause");
    return 0;
}
