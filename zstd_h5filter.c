#include "zstd_h5filter.h"

#include "zstd_h5plugin.c"

int register_zstd_h5filter()
{
    return H5Zregister(H5PLget_plugin_info());
}
