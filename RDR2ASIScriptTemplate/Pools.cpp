

#include "Pools.h"

namespace Pools
{
	const int ArraySize = 1024;

	void GetAllVehicles()
	{
		VehicleCount = worldGetAllVehicles(AllVehicles, ArraySize);
	}

	void GetAllPeds()
	{
		PedCount = worldGetAllPeds(AllPeds, ArraySize);
	}

	void GetAllObjects()
	{
		ObjectCount = worldGetAllObjects(AllObjects, ArraySize);
	}

	void GetAllPickups()
	{
		PickupCount = worldGetAllPickups(AllPickups, ArraySize);
	}

	void Update()
	{
		GetAllVehicles();
		GetAllPeds();
		GetAllObjects();
		GetAllPickups();
	}
}