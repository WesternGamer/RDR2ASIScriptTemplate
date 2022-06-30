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
	
	/// <summary>
	/// Easier way to get array of all vehicles in the world.
	/// </summary>
	/// <returns>An array of vehicles.</returns>
	Vehicle* GetAllVehicles();

	/// <summary>
	/// Easier way to get array of all peds in the world.
	/// </summary>
	/// <returns>An array of peds.</returns>
	Ped* GetAllPeds();

	/// <summary>
	/// Easier way to get array of all objects in the world.
	/// </summary>
	/// <returns>An array of objects.</returns>
	Object* GetAllObjects();

	/// <summary>
	/// Easier way to get array of all pickups in the world.
	/// </summary>
	/// <returns>An array of pickups.</returns>
	Pickup* GetAllPickups();
}