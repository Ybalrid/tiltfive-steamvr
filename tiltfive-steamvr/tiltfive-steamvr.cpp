﻿#include "tiltfive-steamvr.h"
#include "driver.h"


#define HMD_DLL_EXPORT extern "C" __declspec( dllexport )

TiltFiveSteamVRDriver driverInstance;

HMD_DLL_EXPORT void* HmdDriverFactory(const char* pInterfaceName, int* pReturnCode) {

	if (strcmp(vr::IServerTrackedDeviceProvider_Version, pInterfaceName) == 0) {
		return &driverInstance;
	}

	if (pReturnCode)
		*pReturnCode = vr::VRInitError_Init_InterfaceNotFound;

	return NULL;
}