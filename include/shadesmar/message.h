/* MIT License

Copyright (c) 2020 Dheeraj R Reddy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
==============================================================================*/

#ifndef INCLUDE_SHADESMAR_MESSAGE_H_
#define INCLUDE_SHADESMAR_MESSAGE_H_

#include <chrono>
#include <cstdint>
#include <cstring>
#include <msgpack.hpp>
#include <utility>

#include "shadesmar/macros.h"

#define SHM_PACK(...) MSGPACK_DEFINE(seq, timestamp, __VA_ARGS__);

namespace shm {

class BaseMsg {
 public:
  uint32_t seq{};
  uint64_t timestamp{};

  BaseMsg() = default;

  void init_time();
};

void BaseMsg::init_time() { timestamp = current_time(); }
}  // namespace shm

#endif  // INCLUDE_SHADESMAR_MESSAGE_H_
