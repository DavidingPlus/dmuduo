#ifndef _DMUDUO_INETADDRESS_H_
#define _DMUDUO_INETADDRESS_H_

#include "globalmacros.h"

#include <string>

#include <arpa/inet.h>
#include <netinet/in.h>


DMUDUO_NAMESPACE_BEGIN(dmuduo)


// 封装 socket 地址类型。
class DMUDUO_API_EXPORTED InetAddress
{

public:

    explicit InetAddress(uint16_t port = 0, const std::string &ip = "127.0.0.1");

    explicit InetAddress(const sockaddr_in &addr) : m_addr(addr) {}

    std::string toIp() const;

    std::string toIpPort() const;

    uint16_t toPort() const { return ::ntohs(m_addr.sin_port); }

    const sockaddr_in *getSockAddr() const { return &m_addr; }

    void setSockAddr(const sockaddr_in &addr) { m_addr = addr; }


private:

    sockaddr_in m_addr{};
};


DMUDUO_NAMESPACE_END


#endif
