#pragma once

#include "Pools.h"

namespace Pools
{
	const int ArraySize = 1024;

	Vehicle* GetAllVehicles() 
	{
		Vehicle vehicles[ArraySize];
		VehicleCount = worldGetAllVehicles(vehicles, ArraySize);
		return vehicles;
	}

	Ped* GetAllPeds()
	{
		Ped peds[ArraySize];
		PedCount = worldGetAllPeds(peds, ArraySize);
		return peds;
	}

	Object* GetAllObjects()
	{
		Object objects[ArraySize];
		ObjectCount = worldGetAllObjects(objects, ArraySize);
		return objects;
	}

	Pickup* GetAllPickups() 
	{
		Pickup pickups[ArraySize];
		PickupCount = worldGetAllPickups(pickups, ArraySize);
		return pickups;
	}
}