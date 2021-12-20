// Fill out your copyright notice in the Description page of Project Settings.


#include "SQInputButton.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SComboBox.h"
#include "Styling/SlateBrush.h"

#define NSLOCTEXT_NAMESPACE "QInputButton"



int SQInputButton::PathsNumber = 0;

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SQInputButton::Construct(const FArguments& InArgs)
{
	if (Options.Num() <= 0)
	{
		Options.Add(MakeShared<FString>(TEXT("Insert")));
		Options.Add(MakeShared<FString>(TEXT("Delete")));
		Options.Add(MakeShared<FString>(TEXT("Duplicate")));
	}

	FSlateBrush whiteBrush = FSlateBrush();
	//whiteBrush.TintColor = 

	TSharedPtr<SHorizontalBox> ListHorizontalBox = 
		SNew(SHorizontalBox)
		
		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Top)
		.Padding(0.0f, 0.0f, 10.0f, 2.0f)
		[
			SNew(STextBlock)
			.Text(FText::AsNumber(PathsNumber++))
		]
		
		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Fill)
		.Padding(0.0f, 0.0f, 10.0f, 2.0f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.ColorAndOpacity(FSlateColor(FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)))
			]
			
			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(SEditableText)
				.Text(FText::AsNumber(PathsNumber))
				.OnTextCommitted(this, &SQInputButton::OnTextCommited)
			]
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Top)
		.Padding(0.0f, 0.0f, 3.0f, 2.0f)
		[
			SAssignNew(MyComboBox, SComboBox< TSharedPtr<FString> >)
			.OptionsSource(&Options)
			//.OnGenerateWidget(BIND_UOBJECT_DELEGATE(SComboBox< TSharedPtr<FString> >::FOnGenerateWidget, GenerateWidget))
			.OnGenerateWidget(this, &SQInputButton::GenerateWidget)
			//.OnSelectionChanged(BIND_UOBJECT_DELEGATE(SComboBox< TSharedPtr<FString> >::FOnSelectionChanged, OnSelectionChanged))
			.OnSelectionChanged(this, &SQInputButton::OnSelectionChanged)
			.IsFocusable(true)
			[
				SAssignNew(ComboBoxContent, SBox)
			]
		];

	ChildSlot
	[
		ListHorizontalBox.ToSharedRef()
	];
}

SQInputButton::~SQInputButton()
{
	--PathsNumber;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SQInputButton::OnTextChaged(const FText& newContent)
{

}

void SQInputButton::OnTextCommited(const FText& newContent, ETextCommit::Type commitType)
{

}

TSharedRef<SWidget> SQInputButton::GenerateWidget(TSharedPtr<FString> newOption)
{
	return SNew(STextBlock).Text(FText::FromString(*newOption));
}

void SQInputButton::OnSelectionChanged(TSharedPtr<FString> selectedOption, ESelectInfo::Type selectType)
{
	if (ComboBoxContent.IsValid())
	{
		ComboBoxContent->SetContent(SNew(STextBlock).Text(FText::FromString("")));
	}
}

#undef NSLOCTEXT_NAMESPACE