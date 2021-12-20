// Copyright Epic Games, Inc. All Rights Reserved.


#include "PluginTestGameModeBase.h"
#include "MyHUD.h"
#include "MyPlayerController.h"

APluginTestGameModeBase::APluginTestGameModeBase()
{
	
	PlayerControllerClass = AMyPlayerController::StaticClass();
	HUDClass = AMyHUD::StaticClass();
}
