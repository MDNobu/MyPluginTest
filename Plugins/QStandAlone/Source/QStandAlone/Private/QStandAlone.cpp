// Copyright Epic Games, Inc. All Rights Reserved.

#include "QStandAlone.h"
#include "QStandAloneStyle.h"
#include "QStandAloneCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "SQMainWidget.h"

static const FName QStandAloneTabName("QStandAlone");

#define LOCTEXT_NAMESPACE "FQStandAloneModule"

void FQStandAloneModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FQStandAloneStyle::Initialize();
	FQStandAloneStyle::ReloadTextures();

	FQStandAloneCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FQStandAloneCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FQStandAloneModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FQStandAloneModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(QStandAloneTabName, FOnSpawnTab::CreateRaw(this, &FQStandAloneModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FQStandAloneTabTitle", "QStandAlone"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FQStandAloneModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FQStandAloneStyle::Shutdown();

	FQStandAloneCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(QStandAloneTabName);
}

TSharedRef<SDockTab> FQStandAloneModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FQStandAloneModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("QStandAlone.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SAssignNew(QMainWidget, SQMainWidget)
		];
}

void FQStandAloneModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(QStandAloneTabName);
}

void FQStandAloneModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FQStandAloneCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FQStandAloneCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FQStandAloneModule, QStandAlone)