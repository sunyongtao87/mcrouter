/*
 *  Copyright (c) 2016, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */
#include "umbrella.h"

uint32_t const umbrella_op_from_mc[UM_NOPS] = {
#define UM_OP(mc, um) [mc] = um,
#include "mcrouter/lib/mc/umbrella_conv.h" /* nolint */
};

uint32_t const umbrella_op_to_mc[UM_NOPS] = {
#define UM_OP(mc, um) [um] = mc,
#include "mcrouter/lib/mc/umbrella_conv.h" /* nolint */
};

uint32_t const umbrella_res_from_mc[mc_nres] = {
#define UM_RES(mc, um) [mc] = um,
#include "mcrouter/lib/mc/umbrella_conv.h" /* nolint */
};

uint32_t const umbrella_res_to_mc[mc_nres] = {
#define UM_RES(mc, um) [um] = mc,
#include "mcrouter/lib/mc/umbrella_conv.h" /* nolint */
};

