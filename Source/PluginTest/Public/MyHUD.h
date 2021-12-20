// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

class SMainMenuWidget;
class SWidget;
/**
 * 
 */
UCLASS()
class PLUGINTEST_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	

public:

	void ShowMenu();
	void HideMenu();

protected:
	void BeginPlay() override;


private:
	
protected:

	TSharedPtr<SMainMenuWidget> MainMenuWidget;
	TSharedPtr<SWidget> MenuWidgetContainer;

};
