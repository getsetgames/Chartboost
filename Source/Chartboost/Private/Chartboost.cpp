//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"
#include "ChartboostSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogChartboost);

#define LOCTEXT_NAMESPACE "Chartboost"

class FChartboost : public IChartboost
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FChartboost, Chartboost )

void FChartboost::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Chartboost",
										 LOCTEXT("RuntimeSettingsName", "Chartboost"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Chartboost plugin"),
										 GetMutableDefault<UChartboostSettings>()
										 );
	}
}


void FChartboost::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
