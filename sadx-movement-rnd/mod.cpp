#include <SADXModLoader.h>
#include "HandleGroundVelocity.h"

#define EXPORT __declspec(dllexport)

extern "C"
{
	EXPORT ModInfo SADXModInfo = { ModLoaderVer, nullptr, nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0 };

	EXPORT void Init(const char* /*path*/, const HelperFunctions& /*helperFunctions*/)
	{
		// use our cleaned version of this function for ease of debugging
		WriteJump(reinterpret_cast<void*>(0x0044C270), HandleGroundVelocity);
	}

	EXPORT void OnInput()
	{
		// simulate inputs here for plotting values.
		// will be useful for: turning, braking
	}

	EXPORT void OnFrame()
	{
		// here is where we would export data for plotting.
	}
}
