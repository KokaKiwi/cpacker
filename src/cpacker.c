#include <stdlib.h>
#include "cpacker.h"

cpacker_buf_t *cpacker_buf_new(void)
{
    cpacker_buf_t *buf = malloc(sizeof(cpacker_buf_t));

    if (buf)
    {
        cpacker_buf_init(buf);
    }

    return buf;
}

void cpacker_buf_free(cpacker_buf_t *buf)
{
    if (buf)
    {
        cpacker_buf_destroy(buf);
        free(buf);
    }
}

void cpacker_buf_init(cpacker_buf_t *buf)
{
    buf->index = 0;
    buf->size = 0;
    buf->data_size = 0;
    buf->data = NULL;
    buf->mode = CPACKER_MODE_LITTLE;
}

void cpacker_buf_destroy(cpacker_buf_t *buf)
{
    if (buf->data)
    {
        free(buf->data);
    }
}

void cpacker_buf_reset(cpacker_buf_t *buf)
{
    cpacker_buf_destroy(buf);
    cpacker_buf_init(buf);
}

void cpacker_buf_resize(cpacker_buf_t *buf, size_t size)
{
    size_t num = size / CPACKER_BUFFER_SIZE;
    if (size % CPACKER_BUFFER_SIZE)
    {
        num++;
    }

    buf->data = realloc(buf->data, num * CPACKER_BUFFER_SIZE);
    buf->data_size = num * CPACKER_BUFFER_SIZE;
}

void cpacker_buf_ensure_size(cpacker_buf_t *buf, size_t size)
{
    if (buf->data_size < size)
    {
        cpacker_buf_resize(buf, size);
    }
}

void cpacker_buf_set_mode(cpacker_buf_t *buf, cpacker_mode_t mode)
{
    buf->mode = mode;
}

void cpacker_buf_set_data(cpacker_buf_t *buf, char *data, size_t size)
{
    buf->index = 0;
    buf->data = data;
    buf->size = buf->data_size = size;
}

void cpacker_buf_set_index(cpacker_buf_t *buf, size_t index)
{
    buf->index = 0;
}
