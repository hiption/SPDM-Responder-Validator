/**
    Copyright Notice:
    Copyright 2021 DMTF. All rights reserved.
    License: BSD 3-Clause License. For full text see link: https://github.com/DMTF/spdm-emu/blob/main/LICENSE.md
**/

#ifndef _SPDM_RESPONDER_TEST_H_
#define _SPDM_RESPONDER_TEST_H_

#include "library/spdm_requester_lib.h"

/* TBD */
return_status spdm_get_version(void *spdm_context,
                               uint8_t *version_number_entry_count,
                               spdm_version_number_t *version_number_entry);
return_status spdm_get_capabilities(void *spdm_context);

#include "library/spdm_responder_conformance_test_lib.h"
#include "library/common_test_utility_lib.h"

#define SPDM_TEST_CONTEXT_SIGNATURE SIGNATURE_32('S', 'C', 'T', 'S')

#define SPDM_TEST_SCRATCH_BUFFER_SIZE 0x100

typedef struct {
    uint32_t signature;
    void *spdm_context;
    /* test case specific scratch buffer between setup and case, avoid writable global variable */
    uint8_t test_scratch_buffer[SPDM_TEST_SCRATCH_BUFFER_SIZE];
    uint32_t test_scratch_buffer_size;
} spdm_test_context_t;

/**
  return one bit in the data according to the mask

  @retval 0                if (data & mask) is 0.
  @retval 0xFFFFFFFF       if (data & mask) includes more than one bit.
  @return (data & mask)    if (data & mask) includes one bit.
**/
uint32_t spdm_test_get_one_bit (uint32_t data, uint32_t mask);

extern common_test_case_t m_spdm_test_group_version[];
extern common_test_case_t m_spdm_test_group_capabilities[];
extern common_test_case_t m_spdm_test_group_algorithms[];

#endif