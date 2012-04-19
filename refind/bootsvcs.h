/*
 * File to implement an full version of EFI_BOOT_SERVICES, to go beyond
 * what GNU-EFI provides. Most of the data structures in this file are taken
 * from the Tianocore UDK's UefiSpec.h file or HandleParsingLib.h files.
 * The EFI_DEVICE_PATH_PROTOCOL definition is from
 * http://wiki.phoenix.com/wiki/index.php/EFI_DEVICE_PATH_PROTOCOL.
 * The UefiSpec.h and HandleParsingLib files include the following copyright
 * notice:
 * 
 * Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>
 * This program and the accompanying materials are licensed and made available under
 * the terms and conditions of the BSD License that accompanies this distribution.
 * The full text of the license may be found at
 * http://opensource.org/licenses/bsd-license.php.
 *
 * THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
 * WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
 *
 */

#include <efi/efi.h>
#include <efi/efilib.h>

#ifndef _MY_BOOT_SERVICES_FILE
#define _MY_BOOT_SERVICES_FILE

typedef struct _EFI_DEVICE_PATH_PROTOCOL {
   UINT8 Type;
   UINT8 SubType;
   UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_CONNECT_CONTROLLER)(
  IN  EFI_HANDLE                    ControllerHandle,
  IN  EFI_HANDLE                    *DriverImageHandle,   OPTIONAL
  IN  EFI_DEVICE_PATH_PROTOCOL      *RemainingDevicePath, OPTIONAL
  IN  BOOLEAN                       Recursive
  );

typedef
EFI_STATUS
(EFIAPI *EFI_DISCONNECT_CONTROLLER)(
  IN  EFI_HANDLE                     ControllerHandle,
  IN  EFI_HANDLE                     DriverImageHandle, OPTIONAL
  IN  EFI_HANDLE                     ChildHandle        OPTIONAL
  );

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL) (
   IN EFI_HANDLE                 Handle,
   IN EFI_GUID                   * Protocol,
   OUT VOID                      **Interface,
   IN  EFI_HANDLE                ImageHandle,
   IN  EFI_HANDLE                ControllerHandle, OPTIONAL
     IN  UINT32                    Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_PROTOCOL) (
   IN EFI_HANDLE               Handle,
   IN EFI_GUID                 * Protocol,
   IN EFI_HANDLE               ImageHandle,
   IN EFI_HANDLE               DeviceHandle
);

typedef struct {
   EFI_HANDLE  AgentHandle;
   EFI_HANDLE  ControllerHandle;
   UINT32      Attributes;
   UINT32      OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION) (
   IN  EFI_HANDLE                          UserHandle,
   IN  EFI_GUID                            * Protocol,
   IN  EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
   OUT UINTN                               *EntryCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_PROTOCOLS_PER_HANDLE) (
   IN EFI_HANDLE       UserHandle,
   OUT EFI_GUID        ***ProtocolBuffer,
   OUT UINTN           *ProtocolBufferCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER) (
   IN EFI_LOCATE_SEARCH_TYPE       SearchType,
   IN EFI_GUID                     * Protocol OPTIONAL,
   IN VOID                         *SearchKey OPTIONAL,
   IN OUT UINTN                    *NumberHandles,
   OUT EFI_HANDLE                  **Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_PROTOCOL) (
   EFI_GUID  * Protocol,
   VOID      *Registration, OPTIONAL
   VOID      **Interface
);

///
/// EFI Boot Services Table.
///
typedef struct _MY_BOOT_SERVICES {
  ///
  /// The table header for the EFI Boot Services Table.
  ///
  EFI_TABLE_HEADER                Hdr;

  //
  // Task Priority Services
  //
  EFI_RAISE_TPL                   RaiseTPL;
  EFI_RESTORE_TPL                 RestoreTPL;

  //
  // Memory Services
  //
  EFI_ALLOCATE_PAGES              AllocatePages;
  EFI_FREE_PAGES                  FreePages;
  EFI_GET_MEMORY_MAP              GetMemoryMap;
  EFI_ALLOCATE_POOL               AllocatePool;
  EFI_FREE_POOL                   FreePool;

  //
  // Event & Timer Services
  //
  EFI_CREATE_EVENT                  CreateEvent;
  EFI_SET_TIMER                     SetTimer;
  EFI_WAIT_FOR_EVENT                WaitForEvent;
  EFI_SIGNAL_EVENT                  SignalEvent;
  EFI_CLOSE_EVENT                   CloseEvent;
  EFI_CHECK_EVENT                   CheckEvent;

  //
  // Protocol Handler Services
  //
  EFI_INSTALL_PROTOCOL_INTERFACE    InstallProtocolInterface;
  EFI_REINSTALL_PROTOCOL_INTERFACE  ReinstallProtocolInterface;
  EFI_UNINSTALL_PROTOCOL_INTERFACE  UninstallProtocolInterface;
  EFI_HANDLE_PROTOCOL               HandleProtocol;
  VOID                              *Reserved;
  EFI_REGISTER_PROTOCOL_NOTIFY      RegisterProtocolNotify;
  EFI_LOCATE_HANDLE                 LocateHandle;
  EFI_LOCATE_DEVICE_PATH            LocateDevicePath;
  EFI_INSTALL_CONFIGURATION_TABLE   InstallConfigurationTable;

  //
  // Image Services
  //
  EFI_IMAGE_LOAD                    LoadImage;
  EFI_IMAGE_START                   StartImage;
  EFI_EXIT                          Exit;
  EFI_IMAGE_UNLOAD                  UnloadImage;
  EFI_EXIT_BOOT_SERVICES            ExitBootServices;

  //
  // Miscellaneous Services
  //
  EFI_GET_NEXT_MONOTONIC_COUNT      GetNextMonotonicCount;
  EFI_STALL                         Stall;
  EFI_SET_WATCHDOG_TIMER            SetWatchdogTimer;

  //
  // DriverSupport Services
  //
  EFI_CONNECT_CONTROLLER            ConnectController;
  EFI_DISCONNECT_CONTROLLER         DisconnectController;

  //
  // Open and Close Protocol Services
  //
  EFI_OPEN_PROTOCOL                 OpenProtocol;
  EFI_CLOSE_PROTOCOL                CloseProtocol;
  EFI_OPEN_PROTOCOL_INFORMATION     OpenProtocolInformation;

  //
  // Library Services
  //
  EFI_PROTOCOLS_PER_HANDLE          ProtocolsPerHandle;
  EFI_LOCATE_HANDLE_BUFFER          LocateHandleBuffer;
  EFI_LOCATE_PROTOCOL               LocateProtocol;
//   EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES    InstallMultipleProtocolInterfaces;
//   EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES  UninstallMultipleProtocolInterfaces;
// 
//   //
//   // 32-bit CRC Services
//   //
//   EFI_CALCULATE_CRC32               CalculateCrc32;
// 
//   //
//   // Miscellaneous Services
//   //
//   EFI_COPY_MEM                      CopyMem;
//   EFI_SET_MEM                       SetMem;
//   EFI_CREATE_EVENT_EX               CreateEventEx;
} MY_BOOT_SERVICES;

// Below is from http://git.etherboot.org/?p=mirror/efi/shell/.git;a=commitdiff;h=b1b0c63423cac54dc964c2930e04aebb46a946ec;
// Seems to have been replaced by ParseHandleDatabaseByRelationshipWithType(), but the latter isn't working for me....
EFI_STATUS
LibScanHandleDatabase (
  EFI_HANDLE  DriverBindingHandle, OPTIONAL
  UINT32      *DriverBindingHandleIndex, OPTIONAL
  EFI_HANDLE  ControllerHandle, OPTIONAL
  UINT32      *ControllerHandleIndex, OPTIONAL
  UINTN       *HandleCount,
  EFI_HANDLE  **HandleBuffer,
  UINT32      **HandleType
  );

extern MY_BOOT_SERVICES *gBS;

#define EFI_HANDLE_TYPE_UNKNOWN                     0x000
#define EFI_HANDLE_TYPE_IMAGE_HANDLE                0x001
#define EFI_HANDLE_TYPE_DRIVER_BINDING_HANDLE       0x002
#define EFI_HANDLE_TYPE_DEVICE_DRIVER               0x004
#define EFI_HANDLE_TYPE_BUS_DRIVER                  0x008
#define EFI_HANDLE_TYPE_DRIVER_CONFIGURATION_HANDLE 0x010
#define EFI_HANDLE_TYPE_DRIVER_DIAGNOSTICS_HANDLE   0x020
#define EFI_HANDLE_TYPE_COMPONENT_NAME_HANDLE       0x040
#define EFI_HANDLE_TYPE_DEVICE_HANDLE               0x080
#define EFI_HANDLE_TYPE_PARENT_HANDLE               0x100
#define EFI_HANDLE_TYPE_CONTROLLER_HANDLE           0x200
#define EFI_HANDLE_TYPE_CHILD_HANDLE                0x400


// Below from EfiApi.h
#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL  0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL        0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL       0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER           0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE           0x00000020


#endif
