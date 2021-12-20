// Copyright Epic Games, Inc. All Rights Reserved.

#include "QStandAloneCommands.h"

#define LOCTEXT_NAMESPACE "FQStandAloneModule"

void FQStandAloneCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "QStandAlone", "Bring up QStandAlone window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
