#pragma once

#include <windows.h>
#include <cstdint>

using Any = uint64_t;
using Void = uint64_t;
using ScrHandle = int;

using AnimScene = int;
using Blip = int;
using Cam = int;
using Entity = ScrHandle;
using FireId = int;
using Hash = unsigned int;
using Interior = int;
using ItemSet = ScrHandle;
using Object = ScrHandle;
using Ped = ScrHandle;
using PersChar = ScrHandle;
using Pickup = int;
using Player = unsigned int;
using PopZone = int;
using Prompt = int;
using PropSet = int;
using Vehicle = ScrHandle;
using Volume = ScrHandle;


#define ALIGN8 __declspec(align(8))

struct Vector2
{
	ALIGN8 float x;
	ALIGN8 float y;
};

struct Vector3
{
	ALIGN8 float x;
	ALIGN8 float y;
	ALIGN8 float z;
};

struct Vector4
{
	ALIGN8 float x;
	ALIGN8 float y;
	ALIGN8 float z;
	ALIGN8 float w;
};

static_assert(sizeof(Vector2) == 16, "");

static_assert(sizeof(Vector3) == 24, "");

static_assert(sizeof(Vector4) == 32, "");