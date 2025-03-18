#include "lvzstd/lvzstd.h"
#include "sg/export/lvzstd_version.h"

#include <zstd.h>

#include <memory>

#define ZSTD_RETURN_ON_ERROR(fn)                                                 \
do {                                                                             \
        size_t const err = (fn);                                                 \
        if (ZSTD_isError(err)) return static_cast<int32_t>(err); \
} while (0)

namespace {

struct compression_context_deleter {
    void operator()(ZSTD_CCtx *ctx) { ZSTD_freeCCtx(ctx); }
};
struct decompression_context_deleter {
    void operator()(ZSTD_DCtx *ctx) { ZSTD_freeDCtx(ctx); }
};

}

int32_t version(int32_t* major, int32_t *minor, int32_t* patch) {
    *major = PROJECT_VERSION_MAJOR;
    *minor = PROJECT_VERSION_MINOR;
    *patch = PROJECT_VERSION_PATCH;
    return 0;
}


int32_t compress(const uint8_t** srcHandle, uint8_t **dstHandle, int32_t* compressedSize, int32_t cLevel, int32_t noThreads) {
    thread_local auto comp_context = std::unique_ptr<ZSTD_CCtx, compression_context_deleter>(ZSTD_createCCtx());

    //auto srcHndPtr= (const int32_t*)*srcHandle;
    //int32_t srcSize= srcHndPtr[0];

    const int32_t srcSize = **(const int32_t**)srcHandle;
    int32_t dstSize = **(int32_t**)dstHandle;

    auto src = *srcHandle + sizeof(int32_t);
    auto dst = *dstHandle + sizeof(int32_t);

    /* Set parameters */
    ZSTD_RETURN_ON_ERROR(ZSTD_CCtx_setParameter(comp_context.get(), ZSTD_c_nbWorkers, noThreads));
    ZSTD_RETURN_ON_ERROR(
        ZSTD_CCtx_setParameter(comp_context.get(), ZSTD_c_compressionLevel, cLevel));

    // /* Compress */
    auto cSize = ZSTD_compress2(comp_context.get(), dst, dstSize, src, srcSize);
    ZSTD_RETURN_ON_ERROR(cSize);

    *compressedSize = cSize;

    return 0;
}

int32_t get_max_compressed_size(int32_t src_size, int32_t* max_compressed_size) {
    auto size = ZSTD_compressBound(src_size);
    ZSTD_RETURN_ON_ERROR(size);
    *max_compressed_size = size;
    return 0;
}

int32_t bounds_nothread(int32_t* min, int32_t* max) {
    auto b = ZSTD_cParam_getBounds(ZSTD_c_nbWorkers);
    *min = b.lowerBound;
    *max= b.upperBound;

    ZSTD_RETURN_ON_ERROR(b.error);
    return 0;
}
