#include <lvzstd/lvzstd.h>

#include <iostream>
#include <zstd.h>
#include <vector>

void print_err(size_t err) {
    std::cout << "<nierror code=\"" << 7000+err << "\">" <<std::endl;
    std::cout << std::string(ZSTD_getErrorName(-err)) << std::endl;
    std::cout << "</nierror>" <<std::endl;
}

void print_err_own(int32_t err, std::string msg) {
    std::cout << "<nierror code=\"" << 7000-err << "\">" <<std::endl;
    std::cout << msg << std::endl;
    std::cout << "</nierror>" <<std::endl;
}

int main(){
    std::vector<ZSTD_ErrorCode> vec {
        ZSTD_error_GENERIC   ,
        ZSTD_error_prefix_unknown                 ,
        ZSTD_error_version_unsupported            ,
        ZSTD_error_frameParameter_unsupported     ,
        ZSTD_error_frameParameter_windowTooLarge  ,
        ZSTD_error_corruption_detected  ,
        ZSTD_error_checksum_wrong       ,
        ZSTD_error_literals_headerWrong  ,
        ZSTD_error_dictionary_corrupted       ,
        ZSTD_error_dictionary_wrong           ,
        ZSTD_error_dictionaryCreation_failed  ,
        ZSTD_error_parameter_unsupported    ,
        ZSTD_error_parameter_combination_unsupported  ,
        ZSTD_error_parameter_outOfBound     ,
        ZSTD_error_tableLog_tooLarge        ,
        ZSTD_error_maxSymbolValue_tooLarge  ,
        ZSTD_error_maxSymbolValue_tooSmall  ,
        ZSTD_error_cannotProduce_uncompressedBlock  ,
        ZSTD_error_stabilityCondition_notRespected  ,
        ZSTD_error_stage_wrong        ,
        ZSTD_error_init_missing       ,
        ZSTD_error_memory_allocation  ,
        ZSTD_error_workSpace_tooSmall ,
        ZSTD_error_dstSize_tooSmall  ,
        ZSTD_error_srcSize_wrong     ,
        ZSTD_error_dstBuffer_null    ,
        ZSTD_error_noForwardProgress_destFull  ,
        ZSTD_error_noForwardProgress_inputEmpty  ,
    };

    for (auto err :vec)
        print_err(err);

    print_err_own(ERROR_CONTENTSIZE, "unknowne error (e.g. given data not compressed by zstd, invalid magic number, srcSize too small)");
    print_err_own(ERROR_CONTENTSIZE_UNKNOWN, "zstd can't determine size of original uncompressed data");
    return 0;
}
