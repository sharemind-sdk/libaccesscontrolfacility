#
# Copyright (C) 2017 Cybernetica
#
# Research/Commercial License Usage
# Licensees holding a valid Research License or Commercial License
# for the Software may use this file according to the written
# agreement between you and Cybernetica.
#
# GNU General Public License Usage
# Alternatively, this file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl-3.0.html.
#
# For further information, please contact us at sharemind@cyber.ee.
#

CMAKE_MINIMUM_REQUIRED(VERSION "3.0")
PROJECT(SharemindLibAccessControlFacility VERSION "0.1.0" LANGUAGES "C")

INCLUDE("${CMAKE_CURRENT_SOURCE_DIR}/config.local" OPTIONAL)
INCLUDE("${CMAKE_CURRENT_BINARY_DIR}/config.local" OPTIONAL)

FIND_PACKAGE(SharemindCMakeHelpers REQUIRED)

SharemindSetProjectVersion()
SET(SharemindLibAccessControlFacility_COMPAT_VERSION "${SharemindLibAccessControlFacility_VERSION}")

FIND_PACKAGE(SharemindCHeaders REQUIRED)

FILE(GLOB_RECURSE SHAREMIND_LIBACCESSCONTROLFACILITY_HEADERS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
ADD_CUSTOM_TARGET("include_SharemindLibAccessControlFacility_headers_in_IDE"
                  SOURCES ${SHAREMIND_LIBACCESSCONTROLFACILITY_HEADERS})

INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/"
        DESTINATION "include/sharemind"
        COMPONENT "api-dev")

# Install cmake files:
SET(SharemindLibAccessControlFacility_INSTALL_INCLUDE_DIRS
    ${Boost_INCLUDE_DIRS}
    ${SharemindCHeaders_INCLUDE_DIRS}
    "${CMAKE_INSTALL_PREFIX}/include"
)
SharemindUseCMakeFindFiles(COMPONENT "api-dev")


# Packaging:
SharemindSetupPackaging()
SharemindAddComponentPackage("api-dev"
    NAME "libsharemind-accesscontrolfacility-api-dev"
    DESCRIPTION "Sharemind Access Control Facility API development headers"
    DEB_SECTION "libdevel"
    DEB_DEPENDS
        "libsharemind-cheaders-dev (>= 0.1.0)"
        "libc6-dev (>= 2.19)"
)
SharemindPackagingFinalize()
