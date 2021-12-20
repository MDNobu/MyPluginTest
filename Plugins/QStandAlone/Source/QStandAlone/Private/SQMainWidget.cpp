// Fill out your copyright notice in the Description page of Project Settings.


#include "SQMainWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SExpandableArea.h"
#include "Widgets/Layout/SScrollBox.h"
#include "SQInputButton.h"

#define LOCTEXT_NAMESPACE "QMainWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SQMainWidget::Construct(const FArguments& InArgs)
{
	FirstlineCheckboxes.SetNum(4);


	ChildSlot
	[
		SNew(SVerticalBox)

#pragma region Line1
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.Padding(FMargin(250.f, 0, 0, 0))
			.FillWidth(1.0f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Fill)
			[
				//SNew(SCheckBox)
				SAssignNew(FirstlineCheckboxes[0], SCheckBox)
				.IsChecked(ECheckBoxState::Checked)
				.OnCheckStateChanged(this, &SQMainWidget::OnCheckboxChanged<0>)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CellA", "Cell01"))
					.ToolTipText(LOCTEXT("CellDes01", "Descript Cell1"))
				]
			]
			
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(FirstlineCheckboxes[1], SCheckBox)
				.OnCheckStateChanged(this, &SQMainWidget::OnCheckboxChanged<1>)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CellB", "Cell02"))
					.ToolTipText(LOCTEXT("CellDes02", "Descript Cell2"))
				]
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(FirstlineCheckboxes[2], SCheckBox)
				.OnCheckStateChanged(this, &SQMainWidget::OnCheckboxChanged<2>)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CellB", "Cell02"))
					.ToolTipText(LOCTEXT("CellDes02", "Descript Cell2"))
				]
			]

			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(FirstlineCheckboxes[3], SCheckBox)
				.OnCheckStateChanged(this, &SQMainWidget::OnCheckboxChanged<3>)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("CellB", "Cell02"))
					.ToolTipText(LOCTEXT("CellDes02", "Descript Cell2"))
				]
			]
		]
#pragma endregion
		
#pragma region Line2
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			//SAssignNew(QExpandQrea, SExpandableArea)
			SNew(SExpandableArea)
			.AreaTitle(LOCTEXT("MyExpandArea", "Add new Paths"))
			.InitiallyCollapsed(false)
			.Padding(8.0f)
			.HeaderContent()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				[
					SNew(SSpacer)
				]
				+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					.OnClicked(this, &SQMainWidget::OnPlusButtonClicked)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("plus", "+"))
					]
				]
				+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					.OnClicked(this, &SQMainWidget::OnMinusButtonClicked)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("minus", "-"))
					]
				]
				+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					.OnClicked(this, &SQMainWidget::OnMinusAllButtonClicked)
					[
						SNew(STextBlock)
						.Text(LOCTEXT("minusAll", "-All"))
					]
				]
			]
			.BodyContent()
			[
				SNew(SScrollBox)

				+ SScrollBox::Slot()
				[
					//SNew(SQInputButton)
					SAssignNew(QVerticalBox, SVerticalBox)
				]
			]

#pragma endregion

		]
	];

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SQMainWidget::OnPlusButtonClicked()
{
	QVerticalBox->AddSlot()
		[
			SNew(SQInputButton)
		];

	return FReply::Handled();
}

FReply SQMainWidget::OnMinusButtonClicked()
{
	if (QVerticalBox->NumSlots() > 0)
	{
		const int lastIndex = QVerticalBox->NumSlots() - 1;
		TSharedRef<SWidget>  lastWidget = QVerticalBox->GetChildren()->GetChildAt(lastIndex);
		QVerticalBox->RemoveSlot(lastWidget);
	}

	return FReply::Handled();
}

FReply SQMainWidget::OnMinusAllButtonClicked()
{
	QVerticalBox->ClearChildren();
	return FReply::Handled();

}

#undef NSLOCTEXT_NAMESPACE