// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyHUD.h"

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMyPlayerController::OpenMenu);
	}
}

void AMyPlayerController::OpenMenu()
{
	if (AMyHUD* hud = Cast<AMyHUD>(GetHUD()))
	{
		hud->ShowMenu();
	}
}
