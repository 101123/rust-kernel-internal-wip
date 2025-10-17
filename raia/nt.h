#pragma once

#define NOMINMAX

#include <cstdint>
#include <ntifs.h>
#include <ntimage.h>

typedef struct _KLDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	PVOID ExceptionTable;
	ULONG ExceptionTableSize;
	PVOID GpValue;
	PVOID NonPagedDebugInfo;
	PVOID DllBase;
	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	// ...
} KLDR_DATA_TABLE_ENTRY, * PKLDR_DATA_TABLE_ENTRY;

typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY InLoadOrderLinks;
	LIST_ENTRY InMemoryOrderLinks;
	LIST_ENTRY InInitializationOrderLinks;
	PVOID DllBase;
	PVOID EntryPoint;
	ULONG SizeOfImage;
	UNICODE_STRING FullDllName;
	UNICODE_STRING BaseDllName;
	ULONG Flags;
	SHORT LoadCount;
	SHORT TlsIndex;
	union {
		LIST_ENTRY HashLinks;
		struct {
			PVOID SectionPointer;
			ULONG CheckSum;
		};
	};
	union {
		ULONG TimeDateStamp;
		PVOID LoadedImports;
	};
	void* EntryPointActivationContext;
	PVOID PatchInformation;
	LIST_ENTRY ForwarderLinks;
	LIST_ENTRY ServiceTagLinks;
	LIST_ENTRY StaticLinks;
} LDR_DATA_TABLE_ENTRY, * PLDR_DATA_TABLE_ENTRY;

typedef struct _PEB_LDR_DATA {
	ULONG Length;
	uint8_t Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
	PVOID EntryInProgress;
} PEB_LDR_DATA, * PPEB_LDR_DATA;

typedef struct _PEB {
	uint8_t InheritedAddressSpace;
	uint8_t ReadImageFileExecOptions;
	uint8_t BeingDebugged;
	uint8_t BitField;
	ULONG ImageUsesLargePages : 1;
	ULONG IsProtectedProcess : 1;
	ULONG IsLegacyProcess : 1;
	ULONG IsImageDynamicallyRelocated : 1;
	ULONG SpareBits : 4;
	PVOID Mutant;
	PVOID ImageBaseAddress;
	PPEB_LDR_DATA Ldr;
	void* ProcessParameters;
	PVOID SubSystemData;
	PVOID ProcessHeap;
	PVOID FastPebLock;
	PVOID AtlThunkSListPtr;
	PVOID IFEOKey;
	ULONG CrossProcessFlags;
	ULONG ProcessInJob : 1;
	ULONG ProcessInitializing : 1;
	ULONG ReservedBits0 : 30;
	union {
		PVOID KernelCallbackTable;
		PVOID UserSharedInfoPtr;
	};
	ULONG SystemReserved[1];
	ULONG SpareUlong;
	void* FreeList;
	ULONG TlsExpansionCounter;
	PVOID TlsBitmap;
	ULONG TlsBitmapBits[2];
	PVOID ReadOnlySharedMemoryBase;
	PVOID HotpatchInformation;
	void** ReadOnlyStaticServerData;
	PVOID AnsiCodePageData;
	PVOID OemCodePageData;
	PVOID UnicodeCaseTableData;
	ULONG NumberOfProcessors;
	ULONG NtGlobalFlag;
	LARGE_INTEGER CriticalSectionTimeout;
	ULONG HeapSegmentReserve;
	ULONG HeapSegmentCommit;
	ULONG HeapDeCommitTotalFreeThreshold;
	ULONG HeapDeCommitFreeBlockThreshold;
	ULONG NumberOfHeaps;
	ULONG MaximumNumberOfHeaps;
	void** ProcessHeaps;
	PVOID GdiSharedHandleTable;
	PVOID ProcessStarterHelper;
	ULONG GdiDCAttributeList;
	PVOID LoaderLock;
	ULONG OSMajorVersion;
	ULONG OSMinorVersion;
	SHORT OSBuildNumber;
	SHORT OSCSDVersion;
	ULONG OSPlatformId;
	ULONG ImageSubsystem;
	ULONG ImageSubsystemMajorVersion;
	ULONG ImageSubsystemMinorVersion;
	ULONG ImageProcessAffinityMask;
	ULONG GdiHandleBuffer[34];
	PVOID PostProcessInitRoutine;
	PVOID TlsExpansionBitmap;
	ULONG TlsExpansionBitmapBits[32];
	ULONG SessionId;
	ULARGE_INTEGER AppCompatFlags;
	ULARGE_INTEGER AppCompatFlagsUser;
	PVOID pShimData;
	PVOID AppCompatInfo;
	UNICODE_STRING CSDVersion;
	void* ActivationContextData;
	void* ProcessAssemblyStorageMap;
	void* SystemDefaultActivationContextData;
	void* SystemAssemblyStorageMap;
	ULONG MinimumStackCommit;
	void* FlsCallback;
	LIST_ENTRY FlsListHead;
	PVOID FlsBitmap;
	ULONG FlsBitmapBits[4];
	ULONG FlsHighIndex;
	PVOID WerRegistrationData;
	PVOID WerShipAssertPtr;
} PEB, * PPEB;

typedef struct _MEMORY_WORKING_SET_BLOCK {
	ULONG_PTR Protection : 5;
	ULONG_PTR ShareCount : 3;
	ULONG_PTR Shared : 1;
	ULONG_PTR Node : 3;
#ifdef _WIN64
	ULONG_PTR VirtualPage : 52;
#else
	ULONG VirtualPage : 20;
#endif
} MEMORY_WORKING_SET_BLOCK, * PMEMORY_WORKING_SET_BLOCK;

typedef struct _MEMORY_WORKING_SET_INFORMATION {
	ULONG_PTR NumberOfEntries;

	MEMORY_WORKING_SET_BLOCK WorkingSetInfo[1];
} MEMORY_WORKING_SET_INFORMATION, * PMEMORY_WORKING_SET_INFORMATION;

#define UNWIND_HISTORY_TABLE_SIZE 12

typedef struct {
	ULONG BeginAddress;
	ULONG EndAddress;
	union {
		ULONG UnwindInfoAddress;
		ULONG UnwindData;
	} DUMMYUNIONNAME;
} RUNTIME_FUNCTION, * PRUNTIME_FUNCTION;

typedef struct _UNWIND_HISTORY_TABLE_ENTRY {
	DWORD64 ImageBase;
	PRUNTIME_FUNCTION FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY, * PUNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE {
	ULONG Count;
	uint8_t LocalHint;
	uint8_t GlobalHint;
	uint8_t Search;
	uint8_t Once;
	DWORD64 LowAddress;
	DWORD64 HighAddress;
	UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE, * PUNWIND_HISTORY_TABLE;

// 0x190 bytes (sizeof)
struct _KTRAP_FRAME_20H2 {
	ULONGLONG P1Home; // 0x0
	ULONGLONG P2Home; // 0x8
	ULONGLONG P3Home; // 0x10
	ULONGLONG P4Home; // 0x18
	ULONGLONG P5;	  // 0x20
	union {
		CHAR PreviousMode;		 // 0x28
		uint8_t InterruptRetpolineState; // 0x28
	};
	uint8_t PreviousIrql; // 0x29
	union {
		uint8_t FaultIndicator; // 0x2a
		uint8_t NmiMsrIbrs;	// 0x2a
	};
	uint8_t ExceptionActive; // 0x2b
	ULONG MxCsr;		 // 0x2c
	ULONGLONG Rax;		 // 0x30
	ULONGLONG Rcx;		 // 0x38
	ULONGLONG Rdx;		 // 0x40
	ULONGLONG R8;		 // 0x48
	ULONGLONG R9;		 // 0x50
	ULONGLONG R10;		 // 0x58
	ULONGLONG R11;		 // 0x60
	union {
		ULONGLONG GsBase; // 0x68
		ULONGLONG GsSwap; // 0x68
	};
	struct _M128A Xmm0; // 0x70
	struct _M128A Xmm1; // 0x80
	struct _M128A Xmm2; // 0x90
	struct _M128A Xmm3; // 0xa0
	struct _M128A Xmm4; // 0xb0
	struct _M128A Xmm5; // 0xc0
	union {
		ULONGLONG FaultAddress;	 // 0xd0
		ULONGLONG ContextRecord; // 0xd0
	};
	ULONGLONG Dr0;			// 0xd8
	ULONGLONG Dr1;			// 0xe0
	ULONGLONG Dr2;			// 0xe8
	ULONGLONG Dr3;			// 0xf0
	ULONGLONG Dr6;			// 0xf8
	ULONGLONG Dr7;			// 0x100
	ULONGLONG DebugControl;		// 0x108
	ULONGLONG LastBranchToRip;	// 0x110
	ULONGLONG LastBranchFromRip;	// 0x118
	ULONGLONG LastExceptionToRip;	// 0x120
	ULONGLONG LastExceptionFromRip; // 0x128
	USHORT SegDs;			// 0x130
	USHORT SegEs;			// 0x132
	USHORT SegFs;			// 0x134
	USHORT SegGs;			// 0x136
	ULONGLONG TrapFrame;		// 0x138
	ULONGLONG Rbx;			// 0x140
	ULONGLONG Rdi;			// 0x148
	ULONGLONG Rsi;			// 0x150
	ULONGLONG Rbp;			// 0x158
	union {
		ULONGLONG ErrorCode;	  // 0x160
		ULONGLONG ExceptionFrame; // 0x160
	};
	ULONGLONG Rip;	   // 0x168
	USHORT SegCs;	   // 0x170
	uint8_t Fill0;	   // 0x172
	uint8_t Logging;   // 0x173
	USHORT Fill1[2]; // 0x174
	ULONG EFlags;	   // 0x178
	ULONG Fill2;	   // 0x17c
	ULONGLONG Rsp;	   // 0x180
	USHORT SegSs;	   // 0x188
	USHORT Fill3;	   // 0x18a
	ULONG Fill4;	   // 0x18c
};

typedef enum _SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation = 0x0,
	SystemProcessorInformation = 0x1,
	SystemPerformanceInformation = 0x2,
	SystemTimeOfDayInformation = 0x3,
	SystemPathInformation = 0x4,
	SystemProcessInformation = 0x5,
	SystemCallCountInformation = 0x6,
	SystemDeviceInformation = 0x7,
	SystemProcessorPerformanceInformation = 0x8,
	SystemFlagsInformation = 0x9,
	SystemCallTimeInformation = 0xa,
	SystemModuleInformation = 0xb,
	SystemLocksInformation = 0xc,
	SystemStackTraceInformation = 0xd,
	SystemPagedPoolInformation = 0xe,
	SystemNonPagedPoolInformation = 0xf,
	SystemHandleInformation = 0x10,
	SystemObjectInformation = 0x11,
	SystemPageFileInformation = 0x12,
	SystemVdmInstemulInformation = 0x13,
	SystemVdmBopInformation = 0x14,
	SystemFileCacheInformation = 0x15,
	SystemPoolTagInformation = 0x16,
	SystemInterruptInformation = 0x17,
	SystemDpcBehaviorInformation = 0x18,
	SystemFullMemoryInformation = 0x19,
	SystemLoadGdiDriverInformation = 0x1a,
	SystemUnloadGdiDriverInformation = 0x1b,
	SystemTimeAdjustmentInformation = 0x1c,
	SystemSummaryMemoryInformation = 0x1d,
	SystemMirrorMemoryInformation = 0x1e,
	SystemPerformanceTraceInformation = 0x1f,
	SystemObsolete0 = 0x20,
	SystemExceptionInformation = 0x21,
	SystemCrashDumpStateInformation = 0x22,
	SystemKernelDebuggerInformation = 0x23,
	SystemContextSwitchInformation = 0x24,
	SystemRegistryQuotaInformation = 0x25,
	SystemExtendServiceTableInformation = 0x26,
	SystemPrioritySeperation = 0x27,
	SystemVerifierAddDriverInformation = 0x28,
	SystemVerifierRemoveDriverInformation = 0x29,
	SystemProcessorIdleInformation = 0x2a,
	SystemLegacyDriverInformation = 0x2b,
	SystemCurrentTimeZoneInformation = 0x2c,
	SystemLookasideInformation = 0x2d,
	SystemTimeSlipNotification = 0x2e,
	SystemSessionCreate = 0x2f,
	SystemSessionDetach = 0x30,
	SystemSessionInformation = 0x31,
	SystemRangeStartInformation = 0x32,
	SystemVerifierInformation = 0x33,
	SystemVerifierThunkExtend = 0x34,
	SystemSessionProcessInformation = 0x35,
	SystemLoadGdiDriverInSystemSpace = 0x36,
	SystemNumaProcessorMap = 0x37,
	SystemPrefetcherInformation = 0x38,
	SystemExtendedProcessInformation = 0x39,
	SystemRecommendedSharedDataAlignment = 0x3a,
	SystemComPlusPackage = 0x3b,
	SystemNumaAvailableMemory = 0x3c,
	SystemProcessorPowerInformation = 0x3d,
	SystemEmulationBasicInformation = 0x3e,
	SystemEmulationProcessorInformation = 0x3f,
	SystemExtendedHandleInformation = 0x40,
	SystemLostDelayedWriteInformation = 0x41,
	SystemBigPoolInformation = 0x42,
	SystemSessionPoolTagInformation = 0x43,
	SystemSessionMappedViewInformation = 0x44,
	SystemHotpatchInformation = 0x45,
	SystemObjectSecurityMode = 0x46,
	SystemWatchdogTimerHandler = 0x47,
	SystemWatchdogTimerInformation = 0x48,
	SystemLogicalProcessorInformation = 0x49,
	SystemWow64SharedInformationObsolete = 0x4a,
	SystemRegisterFirmwareTableInformationHandler = 0x4b,
	SystemFirmwareTableInformation = 0x4c,
	SystemModuleInformationEx = 0x4d,
	SystemVerifierTriageInformation = 0x4e,
	SystemSuperfetchInformation = 0x4f,
	SystemMemoryListInformation = 0x50,
	SystemFileCacheInformationEx = 0x51,
	SystemThreadPriorityClientIdInformation = 0x52,
	SystemProcessorIdleCycleTimeInformation = 0x53,
	SystemVerifierCancellationInformation = 0x54,
	SystemProcessorPowerInformationEx = 0x55,
	SystemRefTraceInformation = 0x56,
	SystemSpecialPoolInformation = 0x57,
	SystemProcessIdInformation = 0x58,
	SystemErrorPortInformation = 0x59,
	SystemBootEnvironmentInformation = 0x5a,
	SystemHypervisorInformation = 0x5b,
	SystemVerifierInformationEx = 0x5c,
	SystemTimeZoneInformation = 0x5d,
	SystemImageFileExecutionOptionsInformation = 0x5e,
	SystemCoverageInformation = 0x5f,
	SystemPrefetchPatchInformation = 0x60,
	SystemVerifierFaultsInformation = 0x61,
	SystemSystemPartitionInformation = 0x62,
	SystemSystemDiskInformation = 0x63,
	SystemProcessorPerformanceDistribution = 0x64,
	SystemNumaProximityNodeInformation = 0x65,
	SystemDynamicTimeZoneInformation = 0x66,
	SystemCodeIntegrityInformation = 0x67,
	SystemProcessorMicrocodeUpdateInformation = 0x68,
	SystemProcessorBrandString = 0x69,
	SystemVirtualAddressInformation = 0x6a,
	SystemLogicalProcessorAndGroupInformation = 0x6b,
	SystemProcessorCycleTimeInformation = 0x6c,
	SystemStoreInformation = 0x6d,
	SystemRegistryAppendString = 0x6e,
	SystemAitSamplingValue = 0x6f,
	SystemVhdBootInformation = 0x70,
	SystemCpuQuotaInformation = 0x71,
	SystemNativeBasicInformation = 0x72,
	SystemErrorPortTimeouts = 0x73,
	SystemLowPriorityIoInformation = 0x74,
	SystemBootEntropyInformation = 0x75,
	SystemVerifierCountersInformation = 0x76,
	SystemPagedPoolInformationEx = 0x77,
	SystemSystemPtesInformationEx = 0x78,
	SystemNodeDistanceInformation = 0x79,
	SystemAcpiAuditInformation = 0x7a,
	SystemBasicPerformanceInformation = 0x7b,
	SystemQueryPerformanceCounterInformation = 0x7c,
	SystemSessionBigPoolInformation = 0x7d,
	SystemBootGraphicsInformation = 0x7e,
	SystemScrubPhysicalMemoryInformation = 0x7f,
	SystemBadPageInformation = 0x80,
	SystemProcessorProfileControlArea = 0x81,
	SystemCombinePhysicalMemoryInformation = 0x82,
	SystemEntropyInterruptTimingInformation = 0x83,
	SystemConsoleInformation = 0x84,
	SystemPlatformBinaryInformation = 0x85,
	SystemThrottleNotificationInformation = 0x86,
	SystemHypervisorProcessorCountInformation = 0x87,
	SystemDeviceDataInformation = 0x88,
	SystemDeviceDataEnumerationInformation = 0x89,
	SystemMemoryTopologyInformation = 0x8a,
	SystemMemoryChannelInformation = 0x8b,
	SystemBootLogoInformation = 0x8c,
	SystemProcessorPerformanceInformationEx = 0x8d,
	SystemSpare0 = 0x8e,
	SystemSecureBootPolicyInformation = 0x8f,
	SystemPageFileInformationEx = 0x90,
	SystemSecureBootInformation = 0x91,
	SystemEntropyInterruptTimingRawInformation = 0x92,
	SystemPortableWorkspaceEfiLauncherInformation = 0x93,
	SystemFullProcessInformation = 0x94,
	SystemKernelDebuggerInformationEx = 0x95,
	SystemBootMetadataInformation = 0x96,
	SystemSoftRebootInformation = 0x97,
	SystemElamCertificateInformation = 0x98,
	SystemOfflineDumpConfigInformation = 0x99,
	SystemProcessorFeaturesInformation = 0x9a,
	SystemRegistryReconciliationInformation = 0x9b,
	MaxSystemInfoClass = 0x9c,
} SYSTEM_INFORMATION_CLASS;

typedef struct _SYSTEM_THREADS {
	LARGE_INTEGER KernelTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER CreateTime;
	ULONG WaitTime;
	PVOID StartAddress;
	CLIENT_ID ClientId;
	KPRIORITY Priority;
	KPRIORITY BasePriority;
	ULONG ContextSwitchCount;
	LONG State;
	LONG WaitReason;
} SYSTEM_THREADS, * PSYSTEM_THREADS;

typedef struct _SYSTEM_PROCESSES {
	ULONG NextEntryDelta;
	ULONG ThreadCount;
	ULONG Reserved1[6];
	LARGE_INTEGER CreateTime;
	LARGE_INTEGER UserTime;
	LARGE_INTEGER KernelTime;
	UNICODE_STRING ProcessName;
	KPRIORITY BasePriority;
	SIZE_T ProcessId;
	SIZE_T InheritedFromProcessId;
	ULONG HandleCount;
	ULONG Reserved2[2];
	VM_COUNTERS VmCounters;
	IO_COUNTERS IoCounters;
	SYSTEM_THREADS Threads[1];
} SYSTEM_PROCESSES, * PSYSTEM_PROCESSES;

typedef struct _SYSTEM_PROCESS_INFORMATION {
	ULONG NextEntryOffset;
	ULONG NumberOfThreads;
	uint8_t Reserved1[ 48 ];
	PVOID Reserved2[ 3 ];
	HANDLE UniqueProcessId;
	PVOID Reserved3;
	ULONG HandleCount;
	uint8_t Reserved4[ 4 ];
	PVOID Reserved5[ 11 ];
	SIZE_T PeakPagefileUsage;
	SIZE_T PrivatePageCount;
	LARGE_INTEGER Reserved6[ 6 ];
} SYSTEM_PROCESS_INFORMATION;

extern "C" NTSYSAPI ULONG RtlWalkFrameChain(PVOID* Callers, ULONG Count, ULONG Flags);

extern "C" NTSYSAPI PRUNTIME_FUNCTION RtlLookupFunctionEntry(DWORD64 ControlPc,
	PDWORD64 ImageBase,
	PUNWIND_HISTORY_TABLE HistoryTable);

extern "C" NTSYSAPI PEXCEPTION_ROUTINE RtlVirtualUnwind(ULONG HandlerType,
	DWORD64 ImageBase,
	DWORD64 ControlPc,
	PRUNTIME_FUNCTION FunctionEntry,
	PCONTEXT ContextRecord,
	PVOID* HandlerData,
	PDWORD64 EstablisherFrame,
	void* ContextPointers);

extern "C" NTSYSAPI PPEB NTAPI PsGetProcessPeb(PEPROCESS Process);

extern "C" NTSYSAPI UCHAR PsGetProcessProtection(PEPROCESS Process);

extern "C" NTSYSAPI char* NTAPI PsGetProcessImageFileName(PEPROCESS Process);

extern "C" NTSYSAPI NTSTATUS NTAPI ZwQueryInformationProcess(_In_ HANDLE ProcessHandle,
	_In_ PROCESSINFOCLASS ProcessInformationClass,
	_Out_ PVOID ProcessInformation,
	_In_ ULONG ProcessInformationLength,
	_Out_opt_ PULONG ReturnLength);

extern "C" NTSYSAPI NTSTATUS NTAPI ZwProtectVirtualMemory(HANDLE ProcessHandle,
	PVOID* BaseAddress,
	SIZE_T* NumberOfBytesToProtect,
	ULONG NewAccessProtection,
	PULONG OldAccessProtection);

extern "C" NTSYSAPI PVOID PsGetProcessSectionBaseAddress(PEPROCESS Process);

extern "C" NTSYSAPI PVOID PsGetThreadWin32Thread(PETHREAD Thread);

extern "C" NTSYSAPI NTSTATUS NTAPI ZwQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass,
	PVOID SystemInformation,
	ULONG SystemInformationLength,
	PULONG ReturnLength);

extern "C" NTSYSAPI PLIST_ENTRY PsLoadedModuleList;

extern "C" NTSYSAPI NTSTATUS NTAPI ObReferenceObjectByName(IN PUNICODE_STRING ObjectPath,
	IN ULONG Attributes,
	IN PACCESS_STATE PassedAccessState OPTIONAL,
	IN ACCESS_MASK DesiredAccess OPTIONAL,
	IN POBJECT_TYPE ObjectType,
	IN KPROCESSOR_MODE AccessMode,
	IN OUT PVOID ParseContext OPTIONAL,
	OUT PVOID* ObjectPtr);
extern "C" NTSYSAPI POBJECT_TYPE* IoDriverObjectType;

extern "C" NTSYSAPI HANDLE PsGetProcessInheritedFromUniqueProcessId(__in PEPROCESS Process);

extern "C" NTSYSAPI UINT16 NtBuildNumber;

extern "C" NTSYSAPI NTSTATUS ObOpenObjectByName(__in POBJECT_ATTRIBUTES ObjectAttributes,
	__in_opt POBJECT_TYPE ObjectType,
	__in KPROCESSOR_MODE AccessMode,
	__inout_opt PACCESS_STATE AccessState,
	__in_opt ACCESS_MASK DesiredAccess,
	__inout_opt PVOID ParseContext,
	__out PHANDLE Handle);

extern "C" NTSTATUS NTAPI RtlCreateUserThread(HANDLE ProcessHandle, PSECURITY_DESCRIPTOR SecurityDescriptor,
	BOOLEAN CreateSuspended, ULONG StackZeroBits, PULONG StackReserved,
	PULONG StackCommit, PVOID StartAddress, PVOID StartParameter,
	PHANDLE ThreadHandle, PCLIENT_ID ClientID);

extern "C" NTSYSAPI PEPROCESS PsInitialSystemProcess;

extern "C" PVOID RtlImageDirectoryEntryToData(PVOID BaseOfImage, BOOLEAN MappedAsImage,
	USHORT DirectoryEntry, PULONG Size);

extern "C" BOOLEAN KeSignalCallDpcSynchronize(PVOID SystemArgument2);

extern "C" void KeSignalCallDpcDone(PVOID SystemArgument1);

extern "C" void KeGenericCallDpc(PKDEFERRED_ROUTINE Routine, PVOID Context);

extern "C" PVOID RtlFindExportedRoutineByName(_In_ PVOID ImageBase, _In_ PCCH RoutineNam);

extern "C" NTSTATUS KeUserModeCallback(ULONG ApiNumber,
	PVOID InputBuffer,
	ULONG InputLength,
	PVOID* OutputBuffer,
	PULONG OutputLength);