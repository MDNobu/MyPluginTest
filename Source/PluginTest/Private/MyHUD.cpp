// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "SMainMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"
#include <GameFramework/PlayerController.h>



void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMenu();
}


void AMyHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		MainMenuWidget = SNew(SMainMenuWidget).MainMenuHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(
			SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MainMenuWidget));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMyHUD::HideMenu()
{
	if (GEngine && GEngine->GameViewport &&  MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}