// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/SLeafWidget.h"
#include "MaskWidgetStyle.h"

/**
 * 
 */
class PLUGINTEST_API SMaskWidget : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SMaskWidget)
		: _MaskPosition(FVector2D(0.0f, 0.0f))
		, _MaskSize(FVector2D(1.f, 1.f))
		, _MaskStyle(&FCoreStyle::Get().GetWidgetStyle<FMaskStyle>("MaskWidget"))
	{
		//_MaskStyle = &FCoreStyle::Get().GetWidgetStyle<FMaskStyle>("MaskWidget");
		_Visibility = EVisibility::Visible;
	}

	//SLATE_STYLE_ARGUMENT(FMaskSlateSlate, Style)
	//SLATE_STYLE_ARGUMENT
	SLATE_ARGUMENT(const FMaskStyle*, MaskStyle)

	SLATE_ATTRIBUTE(FVector2D, MaskPosition)
	SLATE_ATTRIBUTE(FVector2D, MaskSize)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	const FSlateBrush* GetBackgroundImage() const;
	const FSlateBrush* GetMaskImage() const;

private:

	TAttribute<FVector2D> MaskPosition;

	TAttribute<FVector2D> MaskSize;

	const FMaskStyle* MaskStyle;

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

};
