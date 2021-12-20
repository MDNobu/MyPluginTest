// Fill out your copyright notice in the Description page of Project Settings.


#include "MaskWidgetStyle.h"

FMaskStyle::FMaskStyle()
{
}

FMaskStyle::~FMaskStyle()
{
}

const FName FMaskStyle::TypeName(TEXT("FMaskStyle"));

const FMaskStyle& FMaskStyle::GetDefault()
{
	static FMaskStyle Default;
	return Default;
}

void FMaskStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

