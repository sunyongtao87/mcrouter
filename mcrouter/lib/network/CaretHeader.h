/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

namespace facebook { namespace memcache {

constexpr char kCaretMagicByte = '^';
constexpr size_t kMaxAdditionalFields = 3;
constexpr size_t kMaxHeaderLength = 1 /* magic byte */ +
    1 /* GroupVarint header (lengths of 4 ints) */ +
    4 * sizeof(uint32_t) /* body size, typeId, reqId, num additional fields */ +
    2 * kMaxAdditionalFields * folly::kMaxVarintLength64; /* key and value for
                                                          additional fields */

enum class UmbrellaVersion : uint8_t {
  BASIC = 0,
  TYPED_MESSAGE = 1,
};

enum class CaretAdditionalFieldType {
  TRACE_ID = 0,

  // Range of supportted codecs
  SUPPORTED_CODECS_FIRST_ID = 1,
  SUPPORTED_CODECS_SIZE = 2,

  // Id of codec used to compress the data.
  USED_CODEC_ID = 3,

  // Size of body after decompression.
  UNCOMPRESSED_BODY_SIZE = 4,
};

}} // facebook::memcache