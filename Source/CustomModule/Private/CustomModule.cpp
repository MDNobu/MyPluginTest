// Copyright Epic Games, Inc. All Rights Reserved.

//#include "QTask.h"
#include "CustomModule.h"

#define LOCTEXT_NAMESPACE "FQTaskModule"
DEFINE_LOG_CATEGORY(CustomModule);


void FCustomModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(CustomModule, Warning, TEXT("Loading CustomModule"));
}


void FCustomModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	//jldsfuioweurnsd
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCustomModule, CustomModule)