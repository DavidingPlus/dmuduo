#include "netutils.h"

#include <fmt/format.h>

#include <cstdio>
#include <cstdlib>

#include <dlog/core/log.h>

#include <cerrno>

#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/eventfd.h>
#include <sys/socket.h>


DMUDUO_NAMESPACE_BEGIN(dmuduo)


namespace NetUtils
{

    int CreateEventfd()
    {
        int evtfd = ::eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
        if (evtfd < 0) { fmt::print(stderr, "eventfd error: {}\n", errno); std::abort(); }
        return evtfd;
    }

    int CreateSocketNonblocking()
    {
        int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
        if (sockfd < 0) { fmt::print(stderr, "{}:{}:{} listen socket create err: {}\n", __FILE__, __FUNCTION__, __LINE__, errno); std::abort(); }
        return sockfd;
    }

    EventLoop *CheckLoopNotNull(EventLoop *loop)
    {
        if (!loop) { fmt::print(stderr, "{}:{}:{} mainLoop is null!\n", __FILE__, __FUNCTION__, __LINE__); std::abort(); }
        return loop;
    }

}


DMUDUO_NAMESPACE_END
