/*

Copyright (c) 2017, Alden Torres
Copyright (c) 2017, 2020, Arvid Norberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef TORRENT_ALIGNED_UNION_HPP_INCLUDE
#define TORRENT_ALIGNED_UNION_HPP_INCLUDE

#include <type_traits>

namespace libtorrent { namespace aux {

constexpr std::size_t max(std::size_t a)
{ return a; }

constexpr std::size_t max(std::size_t a, std::size_t b)
{ return a > b ? a : b; }

template <typename... Vals>
constexpr std::size_t max(std::size_t a, std::size_t b, Vals... v)
{ return max(a, max(b, v...)); }

// this is for backwards compatibility with not-quite C++11 compilers
// and for C++23 which deprecated std::aligned_union
template <std::size_t Len, typename... Types>
struct aligned_union
{
	struct type
	{
		alignas(max(alignof(Types)...))
			char buffer[max(Len, max(sizeof(Types)...))];
	};
};

}}

#endif
