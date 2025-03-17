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

int default_compresssion_level()
{
    return ZSTD_defaultCLevel();
}

int32_t compress(const void *src, size_t srcSize, void *dst, size_t dstSize, int cLevel, int noThreads) {
    thread_local auto comp_context = std::unique_ptr<ZSTD_CCtx, compression_context_deleter>(ZSTD_createCCtx());

    /* Set parameters */
    ZSTD_RETURN_ON_ERROR(ZSTD_CCtx_setParameter(comp_context.get(), ZSTD_c_nbWorkers, noThreads));
    ZSTD_RETURN_ON_ERROR(
        ZSTD_CCtx_setParameter(comp_context.get(), ZSTD_c_compressionLevel, cLevel));

    /* Compress */
    auto cSize = ZSTD_compress2(comp_context.get(), dst, dstSize, src, srcSize);
    ZSTD_RETURN_ON_ERROR(cSize);

    return 0;
}
