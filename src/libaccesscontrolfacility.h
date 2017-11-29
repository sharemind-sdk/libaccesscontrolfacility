/*
 * Copyright (C) Cybernetica
 *
 * Research/Commercial License Usage
 * Licensees holding a valid Research License or Commercial License
 * for the Software may use this file according to the written
 * agreement between you and Cybernetica.
 *
 * GNU General Public License Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl-3.0.html.
 *
 * For further information, please contact us at sharemind@cyber.ee.
 */

#ifndef SHAREMIND_LIBACCESSCONTROLFACILITY_H
#define SHAREMIND_LIBACCESSCONTROLFACILITY_H

#ifdef __cplusplus
#include <cstddef>
#include <cstdint>
#endif
#include <sharemind/extern_c.h>
#ifndef __cplusplus
#include <stddef.h>
#include <stdint.h>
#endif


#ifndef SHAREMIND_ICONST
#ifdef SHAREMIND_INTERNAL_
#define SHAREMIND_ICONST
#else
#define SHAREMIND_ICONST const
#endif
#endif /* SHAREMIND_ICONST */

SHAREMIND_EXTERN_C_BEGIN

typedef enum SharemindAccessControlFacilityError_ {

    /** No error */
    SHAREMIND_ACCESS_CONTROL_FACILITY_OK,

    /** Unknown error */
    SHAREMIND_ACCESS_CONTROL_FACILITY_UNKNOWN_ERROR,

    /** Failed to allocate required memory */
    SHAREMIND_ACCESS_CONTROL_FACILITY_OUT_OF_MEMORY,

} SharemindAccessControlFacilityError;

typedef struct SharemindAccessControlFacilityProgramAcl_ {
    char const** allowedResources;
    size_t allowedResourcesLength;
    char const** deniedResources;
    size_t deniedResourcesLength;
} SharemindAccessControlFacilityProgramAcl;

struct SharemindAccessControlFacility_;
typedef struct SharemindAccessControlFacility_ SharemindAccessControlFacility;
struct SharemindAccessControlFacility_ {

    SharemindAccessControlFacilityProgramAcl *
    (* SHAREMIND_ICONST initProgramAcl)(
            size_t allowedResourcesLength, size_t deniedResourcesLength);

    void (* SHAREMIND_ICONST freeProgramAcl)(
            SharemindAccessControlFacilityProgramAcl * acl);

    SharemindAccessControlFacilityError
    (* SHAREMIND_ICONST getProgramAclForClient)(
            SharemindAccessControlFacility const * facility,
            char const * principal,
            char const * action,
            SharemindAccessControlFacilityProgramAcl *& resultAcl);

};

SHAREMIND_EXTERN_C_END

#endif /* SHAREMIND_LIBACCESSCONTROLFACILITY_H */
