// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SComboBox.h"

class SBox;
class STextBlock;

/**
 * 
 */
class QSTANDALONE_API SQMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SQMainWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	template <int32 CheckIndex>
	void OnCheckboxChanged(ECheckBoxState newCheckState)
	{
		if (!FirstlineCheckboxes.IsValidIndex(CheckIndex))
		{
			return;
		}

		//所有checkbox重置一遍
		for (int i = 0; i < FirstlineCheckboxes.Num(); i++)
		{
			if (FirstlineCheckboxes[i].IsValid())
			{
				if (CheckIndex == i)
				{
					FirstlineCheckboxes[i]->SetIsChecked(ECheckBoxState::Checked);
				}
				else
				{
					FirstlineCheckboxes[i]->SetIsChecked(ECheckBoxState::Unchecked);
				}
			}
		}
	}

	FReply OnPlusButtonClicked();

	FReply OnMinusButtonClicked();

	FReply OnMinusAllButtonClicked();

private:

	TArray< TSharedPtr<SCheckBox> > FirstlineCheckboxes;

	TSharedPtr<class SVerticalBox> QVerticalBox;



};
