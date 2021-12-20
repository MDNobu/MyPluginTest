// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CustomModule : ModuleRules
{
	public CustomModule(ReadOnlyTargetRules Target) : base(Target)
	{
		//bUsePrecompiled = true;

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				 "Core", "CoreUObject", "Engine"
			}
			);


		//PrivateDependencyModuleNames.AddRange(
		//	new string[]
		//	{
		//		"CoreUObject",
		//		"Engine",
		//		"Slate",
		//		"SlateCore",
		//		// ... add private dependencies that you statically link with here ...	
		//	}
		//	);

		//PublicIncludePaths.AddRange(new string[] { ""})
		PublicIncludePaths.AddRange(new string[] { "CustomModule/Public" });

		PrivateIncludePaths.AddRange(new string[] { "CustomModule/Private" });


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
