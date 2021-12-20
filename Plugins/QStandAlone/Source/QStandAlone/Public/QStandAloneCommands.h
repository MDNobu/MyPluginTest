// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "QStandAloneStyle.h"

class FQStandAloneCommands : public TCommands<FQStandAloneCommands>
{
public:

	FQStandAloneCommands()
		: TCommands<FQStandAloneCommands>(TEXT("QStandAlone"), NSLOCTEXT("Contexts", "QStandAlone", "QStandAlone Plugin"), NAME_None, FQStandAloneStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};