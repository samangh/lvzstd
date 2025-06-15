# lvzstd Zstandard Compression

A LabVIEW compression library using the [standard Compression algorithm](https://github.com/facebook/zstd). ZStandard is a fast lossless compression algorithm, targeting real-time compression scenarios at zlib-level and better compression ratios.

Supports multithraded Zstandard compression/decompression on:

  * Windows (x86, 32/64-bit)
  * Linux (x86 64-bit)
  * NI Real-Time Linux (x86 64-bit)

Features:

  * VIs are thread safe, reentrant, and can be called in parallel
  * when compressing, can optionally set the number of threads and the compresssion level

This package relies on a compile library (.dll/.so), which is also distributed here.

This library will only work on LabVIEW 2020 or later.

## Installation

You can install it using the VI package manager.

/wamplv/ is available on the [[https://www.vipm.io/package/samangh_lib_wamplv_wamp_client/][VIPM Community repository]]. Alternatively,
the VI package is also available to download [[https://github.com/samangh/wamplv/releases][here]].

## License

Licensed under MIT. See [LICENSE](LICENSE).
