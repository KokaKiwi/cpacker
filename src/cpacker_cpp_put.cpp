#include "cpacker.h"
#include "cpacker-cpp.h"

using namespace cpacker;

Buffer &Buffer::put(const char *src, size_t length)
{
    cpacker_buf_put_data(&buf, src, length);
    return *this;
}

Buffer &Buffer::putVarInt(size_t n)
{
    cpacker_buf_put_varint(&buf, n);
    return *this;
}

Buffer &Buffer::putUint64(uint64_t n)
{
    cpacker_buf_put_uint64(&buf, n);
    return *this;
}

Buffer &Buffer::putUint32(uint32_t n)
{
    cpacker_buf_put_uint32(&buf, n);
    return *this;
}

Buffer &Buffer::putUint16(uint16_t n)
{
    cpacker_buf_put_uint16(&buf, n);
    return *this;
}

Buffer &Buffer::putUint8(uint8_t n)
{
    cpacker_buf_put_uint8(&buf, n);
    return *this;
}

Buffer &Buffer::putChar(char c)
{
    cpacker_buf_put_char(&buf, c);
    return *this;
}

Buffer &Buffer::putString(const char *s)
{
    cpacker_buf_put_string(&buf, s);
    return *this;
}

Buffer &Buffer::putString(const char *s, size_t length)
{
    cpacker_buf_put_string_pad(&buf, s, length);
    return *this;
}

Buffer &Buffer::putStringPrefix(const char *s)
{
    cpacker_buf_put_string_prefix(&buf, s);
    return *this;
}
