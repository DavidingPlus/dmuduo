#ifndef _DMUDUO_GLOBALMACROS_H_
#define _DMUDUO_GLOBALMACROS_H_


#define CLASS_NONCOPYABLE(ClassName)                       \
                                                           \
private:                                                   \
                                                           \
    ClassName(const ClassName &other) = delete;            \
    ClassName(ClassName &&other) = delete;                 \
    ClassName &operator=(const ClassName &other) = delete; \
    ClassName &operator=(ClassName &&other) = delete;


#endif
