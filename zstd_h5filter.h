#pragma once

#ifndef ZSTD_H5FILTER_H
#define ZSTD_H5FILTER_H

#if defined(_WIN32) && !defined(zstd_h5_STATIC)
#  ifdef zstd_h5filter_API_EXPORTS
#    define zstd_h5filter_API __declspec(dllexport)
#  else
#    define zstd_h5filter_API __declspec(dllimport)
#  endif
#else
#  ifdef zstd_h5filter_API_EXPORTS
#    define zstd_h5filter_API __attribute__((__visibility__("default")))
#  else
#    define zstd_h5filter_API
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define ZSTD_H5FILTER 32015

zstd_h5filter_API int register_zstd_h5filter();

#ifdef __cplusplus
}
#endif

#endif


