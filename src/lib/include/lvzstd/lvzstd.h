#include "sg/export/lvzstd.h"

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

LVZSTD_EXPORT int32_t version(int32_t* major, int32_t *minor, int32_t* patch);

LVZSTD_EXPORT int32_t get_max_compressed_size(int32_t src_size, int32_t* max_compressed_size);

LVZSTD_EXPORT int32_t compress(const uint8_t **srcHandle, uint8_t **dstHandle, int32_t* compressedSize, int32_t cLevel, int32_t noThreads);

LVZSTD_EXPORT int32_t bounds_nothread(int32_t* min, int32_t* max);

#ifdef __cplusplus
}
#endif
