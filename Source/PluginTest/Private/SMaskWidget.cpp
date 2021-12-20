// Fill out your copyright notice in the Description page of Project Settings.


#include "SMaskWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMaskWidget::Construct(const FArguments& InArgs)
{
	//check(InArgs._MaskStyle)

	MaskPosition = InArgs._MaskPosition;
	MaskSize = InArgs._MaskSize;
	MaskStyle = InArgs._MaskStyle;
	SetCanTick(false);
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

int32 SMaskWidget::OnPaint(const FPaintArgs& Args, 
	const FGeometry& AllottedGeometry, 
	const FSlateRect& MyCullingRect, 
	FSlateWindowElementList& OutDrawElements, 
	int32 LayerId, 
	const FWidgetStyle& InWidgetStyle, 
	bool bParentEnabled) const
{
	int32 RetLayerId = LayerId;

	//GetBackground
	const FSlateBrush* BgImage = GetBackgroundImage();
	if (BgImage)
	{
		FLinearColor bgTint = BgImage->GetTint(InWidgetStyle) * InWidgetStyle.GetColorAndOpacityTint();
		FSlateDrawElement::MakeBox(OutDrawElements,
			RetLayerId++,
			AllottedGeometry.ToPaintGeometry(), 
			BgImage, 
			ESlateDrawEffect::None, 
			bgTint);
	}

	const FSlateBrush* MaskImage = GetMaskImage();
	if (MaskImage)
	{
		FVector2D lMaskSize = MaskSize.Get();
		FVector2D lMaskPostion = MaskPosition.Get();
		FLinearColor lMaskTint = InWidgetStyle.GetColorAndOpacityTint();

		FSlateDrawElement::MakeBox(OutDrawElements,
			RetLayerId++,
			AllottedGeometry.ToPaintGeometry(),
			MaskImage, 
			ESlateDrawEffect::None, 
			lMaskTint);
	}

	return RetLayerId;
}



const FSlateBrush* SMaskWidget::GetBackgroundImage() const
{
	//#TODO
	return nullptr;
}

const FSlateBrush* SMaskWidget::GetMaskImage() const
{
	//#TODO
	return nullptr;
}

