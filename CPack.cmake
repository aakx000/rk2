include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_CONTACT aakx000)
set(CPACK_PACKAGE_VERSION ${PRINT_VERSION})
set(CPACK_PACKAGE_NAME "example")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "static C++")
set(CPACK_PACKAGE_VENDOR "aakx000")
set(CPACK_PACKAGE_PACK_NAME "example-${PRINT_VERSION}")

set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)

set(CPACK_SOURCE_GENERATOR "TGZ;ZIP")

include(CPack)
