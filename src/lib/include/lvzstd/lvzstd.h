#include "sg/export/lvzstd.h"

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

LVZSTD_EXPORT int32_t version(int32_t* major, int32_t *minor, int32_t* patch);

LVZSTD_EXPORT int default_compresssion_level();

LVZSTD_EXPORT int32_t compress(const void *src, size_t srcSize, void *dst, size_t dstSize, int cLevel, int noThreads);

#ifdef __cplusplus
}
#endif
