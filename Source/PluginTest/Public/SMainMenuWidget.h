// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class AMyHUD;
/**
 * 
 */
class PLUGINTEST_API SMainMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<AMyHUD>, MainMenuHUD )
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AMyHUD> MainMenuHUD;

	bool SupportsKeyboardFocus() const override { return true; };

	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

};
