#pragma once

#include "Scripthook.h"

namespace Invoker 
{
	template <typename T>
	static inline void NativePush(T val)
	{
		UINT64 val64 = 0;
		if (sizeof(T) > sizeof(UINT64))
		{
			throw "An error has occurred: Value size is over 64 bits.";
		}
		*reinterpret_cast<T*>(&val64) = val; // &val + sizeof(dw) - sizeof(val)
		nativePush64(val64);
	}

	static inline void PushArgs()
	{
	}

	template <typename T>
	static inline void PushArgs(T arg)
	{
		NativePush(arg);
	}

	template <typename T, typename... Ts>
	static inline void PushArgs(T arg, Ts... args)
	{
		NativePush(arg);
		PushArgs(args...);
	}

	template <typename R, typename... Ts>
	static inline R invoke(UINT64 hash, Ts... args)
	{
		nativeInit(hash);
		PushArgs(args...);
		return *reinterpret_cast<R*>(nativeCall());
	}
}

