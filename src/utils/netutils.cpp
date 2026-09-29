#include "netutils.h"

#include <fmt/format.h>

#include <dlog/core/logger.h>

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
        if (evtfd < 0) DLOG_FATAL() << fmt::format("eventfd error: {}", errno);
        return evtfd;
    }

    int CreateSocketNonblocking()
    {
        int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
        if (sockfd < 0) DLOG_FATAL() << fmt::format("{}:{}:{} listen socket create err: {}", __FILE__, __FUNCTION__, __LINE__, errno);
        return sockfd;
    }

    EventLoop *CheckLoopNotNull(EventLoop *loop)
    {
        if (!loop) DLOG_FATAL() << fmt::format("{}:{}:{} mainLoop is null!", __FILE__, __FUNCTION__, __LINE__);
        return loop;
    }

}


DMUDUO_NAMESPACE_END
