/*
 * Copyright (c) 2016, Niklas Hauser
 *
 * This file is part of the modm project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_LEGACY_MACROS_HPP
#define XPCC_LEGACY_MACROS_HPP

#include "detect.hpp"

#ifndef __DOXYGEN__

#ifndef XPCC_DISABLE_LEGACY_MACROS

#	define STRINGIFY(s)			XPCC_STRINGIFY(s)
#	define CONCAT(a,b)			XPCC_CONCAT(a,b)
#	define CONCAT3(a,b,c)		XPCC_CONCAT3(a,b,c)
#	define CONCAT4(a,b,c,d)		XPCC_CONCAT4(a,b,c,d)
#	define CONCAT5(a,b,c,d,e)	XPCC_CONCAT5(a,b,c,d,e)

#	define ALWAYS_INLINE  		xpcc_always_inline
#	define ATTRIBUTE_UNUSED		xpcc_unused
#	define ATTRIBUTE_WEAK		xpcc_weak
#	define ATTRIBUTE_ALIGNED(n)	xpcc_aligned(n)
#	define ATTRIBUTE_PACKED		xpcc_packed
#	define ATTRIBUTE_FASTCODE	xpcc_fastcode
#	define ATTRIBUTE_FASTDATA	xpcc_fastdata
#	define ATTRIBUTE_MAY_ALIAS	xpcc_may_alias
#	define likely(x)			xpcc_likely(x)
#	define unlikely(x)			xpcc_unlikely(x)

#	ifdef XPCC_OS_HOSTED
#		define 	MAIN_FUNCTION		int main( int argc, char* argv[] )
#		define	MAIN_FUNCTION_NAKED	int main( int,      char**       )
#	else
#		define	MAIN_FUNCTION	int main(void)
#		define	MAIN_FUNCTION_NAKED MAIN_FUNCTION
#	endif

#	define ENUM_CLASS_FLAG(name) \
		inline name operator|(name a, name b) \
		{return static_cast<name>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));} \
		inline uint32_t operator&(name a, name b) \
		{return (static_cast<uint32_t>(a) & static_cast<uint32_t>(b));} \
		inline uint32_t operator&(uint32_t a, name b) \
		{return ((a) & static_cast<uint32_t>(b));} \
		inline uint32_t operator&(name a, uint32_t b) \
		{return (static_cast<uint32_t>(a) & (b));}

#endif

#define XPCC_ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))


#endif	// !__DOXYGEN__

#endif	// XPCC_LEGACY_MACROS_HPP
