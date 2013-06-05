#ifndef CPACKER_CPP_H_
#define CPACKER_CPP_H_

#include <iostream>
#include "cpacker.h"

namespace cpacker
{
    class Buffer
    {
    public:
        enum class Mode;

        Buffer();
        ~Buffer();

        inline size_t size(void) const
        {
            return cpacker_buf_size(&buf);
        }
        inline char *data(void) const
        {
            return cpacker_buf_data(&buf);
        }

        void reset();

        Mode mode(Mode mode);
        size_t index(size_t index);

        Buffer &put(const char *src, size_t length);
        Buffer &putVarInt(size_t n);
        Buffer &putUint64(uint64_t n);
        Buffer &putUint32(uint32_t n);
        Buffer &putUint16(uint16_t n);
        Buffer &putUint8(uint8_t n);
        Buffer &putChar(char c);
        Buffer &putString(const char *s);
        Buffer &putString(const char *s, size_t length);
        Buffer &putStringPrefix(const char *s);

        Buffer &pack(const char *fmt, ...);
        Buffer &unpack(const char *fmt, ...);

    private:
        cpacker_buf_t buf;
    };

    enum class Buffer::Mode
    {
        LittleEndian,
        BigEndian
    };
}

#endif /* CPACKER_CPP_H_ */
