#include <iostream>

#include "poller.h"


int main()
{
    std::cout << reinterpret_cast<void *>(dmuduo::Poller::NewDefaultPoller(nullptr)) << std::endl; // 不为空。
}
