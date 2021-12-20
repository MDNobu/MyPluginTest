// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SComboBox.h"



/**
 * 
 */
class QSTANDALONE_API SQInputButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SQInputButton)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	~SQInputButton();
private:
	void OnTextChaged(const FText& newContent);

	void OnTextCommited(const FText& newContent, ETextCommit::Type commitType);

	TSharedRef<SWidget> GenerateWidget(TSharedPtr<FString> newOption);

	void OnSelectionChanged(TSharedPtr<FString> selectedOption, ESelectInfo::Type selectType);
private:
#pragma region ComboBoxSection
	/** The true objects bound to the Slate combobox. */
	TArray< TSharedPtr<FString> > Options;

	/** A shared pointer to the underlying slate combobox */
	TSharedPtr< SComboBox< TSharedPtr<FString> > > MyComboBox;

	/** A shared pointer to a container that holds the combobox content that is selected */
	TSharedPtr<class SBox > ComboBoxContent;

	/** If OnGenerateWidgetEvent is not bound, this will store the default STextBlock generated */
	TWeakPtr<class STextBlock> DefaultComboBoxContent;

	/** A shared pointer to the current selected string */
	TSharedPtr<FString> CurrentOptionPtr;
#pragma endregion


	static int PathsNumber;
};
