cmake_minimum_required(VERSION 2.8.10)
project(zstd_h5)

find_package(hdf5 CONFIG REQUIRED)
find_package(zstd CONFIG REQUIRED)

# zstd_h5plugin
add_library(zstd_h5plugin SHARED zstd_h5plugin.c)
target_link_libraries(zstd_h5plugin PRIVATE libzstd $<IF:${zstd_h5_SHARED},hdf5::hdf5-shared,hdf5::hdf5-static>)
install(TARGETS zstd_h5plugin RUNTIME DESTINATION plugin ARCHIVE DESTINATION plugin LIBRARY DESTINATION plugin)

# zstd_h5filter
if(zstd_h5_SHARED)
	add_library(zstd_h5filter SHARED zstd_h5filter.c)
	target_compile_definitions(zstd_h5filter PRIVATE zstd_h5filter_API_EXPORTS)
	target_link_libraries(zstd_h5filter PRIVATE libzstd hdf5::hdf5-shared)
else()
	add_library(zstd_h5filter STATIC zstd_h5filter.c)
	target_compile_definitions(zstd_h5filter PUBLIC zstd_h5_STATIC)
	target_link_libraries(zstd_h5filter PUBLIC libzstd hdf5::hdf5-static)
endif()

target_include_directories(zstd_h5filter PUBLIC $<INSTALL_INTERFACE:include>)
install(TARGETS zstd_h5filter EXPORT zi-zstd-h5-config RUNTIME DESTINATION bin ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)
install(EXPORT zi-zstd-h5-config NAMESPACE zi:: DESTINATION share/cmake/zi-zstd-h5)
install(FILES zstd_h5filter.h DESTINATION include)
