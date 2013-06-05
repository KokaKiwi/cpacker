#include <iostream>
#include <stdio.h>
#include "cpacker.h"
#include "cpacker-cpp.h"

using namespace cpacker;

Buffer::Buffer()
{
    cpacker_buf_init(&buf);
}

Buffer::~Buffer()
{
    cpacker_buf_destroy(&buf);
}

void Buffer::reset()
{
    cpacker_buf_reset(&buf);
}

Buffer::Mode Buffer::mode(Buffer::Mode mode)
{
    Buffer::Mode old = buf.mode == CPACKER_MODE_LITTLE ? Buffer::Mode::LittleEndian : Buffer::Mode::BigEndian;

    buf.mode = mode == Buffer::Mode::LittleEndian ? CPACKER_MODE_LITTLE : CPACKER_MODE_BIG;

    return old;
}

size_t Buffer::index(size_t index)
{
    return cpacker_buf_set_index(&buf, index);
}
