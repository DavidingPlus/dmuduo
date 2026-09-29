#ifndef _DMUDUO_TIMESTAMP_H_
#define _DMUDUO_TIMESTAMP_H_

#include "globalmacros.h"

#include <string>


DMUDUO_NAMESPACE_BEGIN(dmuduo)


class Timestamp
{

public:

    Timestamp() = default;

    explicit Timestamp(int64_t microSecondsSinceEpoch) : m_microSecondsSinceEpoch(microSecondsSinceEpoch) {}

    ~Timestamp() = default;

    int64_t microSecondsSinceEpoch() const { return m_microSecondsSinceEpoch; }

    // 获取当前系统时间戳。
    static Timestamp Now();

    std::string toString() const;


private:

    int64_t m_microSecondsSinceEpoch = static_cast<int64_t>(0);
};


DMUDUO_NAMESPACE_END


#endif
