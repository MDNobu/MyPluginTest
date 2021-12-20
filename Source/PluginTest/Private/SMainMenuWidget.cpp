// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"
#include "MyHUD.h"
#include "GameFramework/PlayerController.h"

#define  LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	MainMenuHUD = InArgs._MainMenuHUD;

	const FMargin ContenPadding = FMargin(500.0f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	const FText TitleText = LOCTEXT("GameTitle", "MySuperGreateGame");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingText = LOCTEXT("Settings", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit Game");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContenPadding)
		[
			SNew(SVerticalBox)
			//Title Text
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TitleTextStyle)
				.Text(TitleText)
				.Justification(ETextJustify::Center)
			]

			// Play Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnPlayClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(PlayText)
					.Justification(ETextJustify::Center)
				]
			]

			// Setting Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(SettingText)
					.Justification(ETextJustify::Center)
				]
			]

			// Quit Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SMainMenuWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(QuitText)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenuWidget::OnPlayClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("OnPlayClicked"));
	if (MainMenuHUD.IsValid())
	{
		MainMenuHUD->HideMenu();
	}
	return FReply::Handled();
}

FReply SMainMenuWidget::OnQuitClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("OnQuitClicked"));

	if (MainMenuHUD.IsValid())
	{
		if (APlayerController* pc = MainMenuHUD->GetOwningPlayerController())
		{
			pc->ConsoleCommand("quit");
		}
	}

	return FReply::Handled();
}

int32 SMainMenuWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, 
	const FSlateRect& MyCullingRect,
	FSlateWindowElementList& OutDrawElements, 
	int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	//throw std::logic_error("The method or operation is not implemented.");
	SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);

	UE_LOG(LogTemp, Warning, TEXT("test"));

	return LayerId;
}

#undef LOCTEXT_NAMESPACE