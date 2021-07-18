/** @file DeviceStatePei.c

  This platform module sets the DEVICE_STATE bits prior to display.

  This driver currently implements the following bits in a standard method:
    DEVICE_STATE_SECUREBOOT_OFF

  This library can either mask those bits (force low) or add other bits.  See the
  MdeModulePkg/Include/Library/DeviceStateLib.h file for bit definitions.

  Copyright (C) Microsoft Corporation.

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <PiDxe.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DeviceStateLib.h>

/**
  Module Entrypoint.
  Check States and Set State

  @param[in]  FileHandle   Handle of the file being invoked.

  @param[in]  PeiServices  General purpose services available to every PEIM.

  @retval     EFI_SUCCESS  Always returns success.
**/
EFI_STATUS
EFIAPI
DeviceStatePeiEntry(
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  DEVICE_STATE                  State;
  State = 0;

  State |= DEVICE_STATE_SECUREBOOT_OFF;
  State |= DEVICE_STATE_MANUFACTURING_MODE;
  State |= DEVICE_STATE_DEVELOPMENT_BUILD_ENABLED;
  State |= DEVICE_STATE_SOURCE_DEBUG_ENABLED;
  State |= DEVICE_STATE_UNDEFINED;
  State |= DEVICE_STATE_UNIT_TEST_MODE;
  State |= DEVICE_STATE_MEM_PROTECTIONS_OFF;

  State |= DEVICE_STATE_PLATFORM_MODE_0;
  State |= DEVICE_STATE_PLATFORM_MODE_1;
  State |= DEVICE_STATE_PLATFORM_MODE_2;
  State |= DEVICE_STATE_PLATFORM_MODE_3;
  State |= DEVICE_STATE_PLATFORM_MODE_4;
  State |= DEVICE_STATE_PLATFORM_MODE_5;
  State |= DEVICE_STATE_PLATFORM_MODE_6;
  State |= DEVICE_STATE_PLATFORM_MODE_7;

  AddDeviceState(State);

  return EFI_SUCCESS;
}