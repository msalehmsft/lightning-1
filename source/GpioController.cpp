// Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.  
// Licensed under the BSD 2-Clause License.  
// See License.txt in the project root for license information.

#include "ErrorCodes.h"

#include "GpioController.h"

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)   // If building a Win32 app:
/**
\return HRESULT error or success code.
*/
HRESULT QuarkFabricGpioControllerClass::_mapController()
{
    HRESULT hr = S_OK;
    PVOID baseAddress = nullptr;

    hr = GetControllerBaseAddress(
        galileoGpioDeviceName,
        m_hController,
        baseAddress,
        FILE_SHARE_READ | FILE_SHARE_WRITE);

    if (SUCCEEDED(hr))
    {
        m_controller = (PFABRIC_GPIO)baseAddress;
    }

    return hr;
}
#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

/**
\return HRESULT success or error code.
*/
HRESULT BtFabricGpioControllerClass::_mapS0Controller()
{
    HRESULT hr = S_OK;
	PVOID baseAddress = nullptr;

    hr = GetControllerBaseAddress(
        mbmGpioS0DeviceName,
        m_hS0Controller,
        baseAddress,
        FILE_SHARE_READ | FILE_SHARE_WRITE);

	if (SUCCEEDED(hr))
    {
        m_s0Controller = (PGPIO_PAD)baseAddress;
    }

    return hr;
}

/**
\return HRESULT success or error code.
*/
HRESULT BtFabricGpioControllerClass::_mapS5Controller()
{
    HRESULT hr = S_OK;
    
    PVOID baseAddress = nullptr;

    hr = GetControllerBaseAddress(
        mbmGpioS5DeviceName,
        m_hS5Controller,
        baseAddress,
        FILE_SHARE_READ | FILE_SHARE_WRITE);

	if (SUCCEEDED(hr))
	{
        m_s5Controller = (PGPIO_PAD)baseAddress;
    }

    return hr;
}

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)   // If building a Win32 app:
/**
\return HRESULT success or error code.
*/
HRESULT QuarkLegacyGpioControllerClass::_openController()
{
    HRESULT hr = S_OK;
    
    hr = OpenControllerDevice(
        galileoLegacyGpioDeviceName,
        m_hController,
        FILE_SHARE_READ | FILE_SHARE_WRITE);

    return hr;
}
#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
