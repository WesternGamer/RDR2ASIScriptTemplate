#pragma once

#include "types.h"
#include "Scripthook.h"

namespace Pools
{
	/// <summary>
	/// Total count of vehicles in the world. Call GetAllVehicles() to update count.
	/// </summary>
	static int VehicleCount;

	/// <summary>
	/// Total count of peds in the world. Call GetAllPeds() to update count.
	/// </summary>
	static int PedCount;

	/// <summary>
	/// Total count of objects in the world. Call GetAllObjects() to update count.
	/// </summary>
	static int ObjectCount;

	/// <summary>
	/// Total count of pickups in the world. Call GetAllPickups() to update count.
	/// </summary>
	static int PickupCount;

	static Ped AllVehicles[1024];

	static Ped AllPeds[1024];

	static Ped AllObjects[1024];

	static Ped AllPickups[1024];

	void Update();
}