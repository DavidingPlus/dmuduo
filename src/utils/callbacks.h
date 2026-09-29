#ifndef _DMUDUO_CALLBACKS_H_
#define _DMUDUO_CALLBACKS_H_

#include "globalmacros.h"

#include <memory>
#include <functional>


DMUDUO_NAMESPACE_BEGIN(dmuduo)


class Buffer;
class TcpConnection;
class Timestamp;


using TcpConnectionPtr = std::shared_ptr<TcpConnection>;

using ConnectionCallback = std::function<void(const TcpConnectionPtr &)>;

using CloseCallback = std::function<void(const TcpConnectionPtr &)>;

using WriteCompleteCallback = std::function<void(const TcpConnectionPtr &)>;

using HighWaterMarkCallback = std::function<void(const TcpConnectionPtr &, size_t)>;

using MessageCallback = std::function<void(const TcpConnectionPtr &, Buffer &, const Timestamp &)>;


DMUDUO_NAMESPACE_END


#endif
