#include <stdarg.h>
#include "cpacker.h"
#include "cpacker-cpp.h"

using namespace cpacker;

Buffer &Buffer::pack(const char *fmt, ...)
{
    va_list vl;

    va_start(vl, fmt);
    cpacker_buf_packv(&buf, fmt, vl);
    va_end(vl);
    return *this;
}

Buffer &Buffer::unpack(const char *fmt, ...)
{
    va_list vl;

    va_start(vl, fmt);
    cpacker_buf_unpackv(&buf, fmt, vl);
    va_end(vl);
    return *this;
}
