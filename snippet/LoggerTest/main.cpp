#include <dlog/core/logger.h>


int main()
{
    DLOG_INFO() << "plain info message";
    DLOG_DEBUG() << "plain debug message";
    DLOG_ERROR() << "plain error message";
    DLOG_FATAL() << "plain fatal message";
}
