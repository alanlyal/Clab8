// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class lab8 : ModuleRules
{
	public lab8(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"lab8",
			"lab8/Variant_Platforming",
			"lab8/Variant_Platforming/Animation",
			"lab8/Variant_Combat",
			"lab8/Variant_Combat/AI",
			"lab8/Variant_Combat/Animation",
			"lab8/Variant_Combat/Gameplay",
			"lab8/Variant_Combat/Interfaces",
			"lab8/Variant_Combat/UI",
			"lab8/Variant_SideScrolling",
			"lab8/Variant_SideScrolling/AI",
			"lab8/Variant_SideScrolling/Gameplay",
			"lab8/Variant_SideScrolling/Interfaces",
			"lab8/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
