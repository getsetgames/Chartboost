//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPluginPrivatePCH.h"
#include "ChartboostSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogChartboost);

#define LOCTEXT_NAMESPACE "ChartboostPlugin"

#if PLATFORM_IOS
#import <Chartboost/Chartboost.h>
#import <Chartboost/CBNewsfeed.h>
#import <CommonCrypto/CommonDigest.h>
#import <AdSupport/AdSupport.h>

@interface CBDelegate : NSObject <ChartboostDelegate>

@end

@implementation CBDelegate

@end

static CBDelegate *CBDelegateSingleton = [[CBDelegate alloc] init];

#endif

class FChartboostPlugin : public IChartboostPlugin
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FChartboostPlugin, ChartboostPlugin )

void FChartboostPlugin::StartupModule()
{
	const UChartboostSettings* DefaultSettings = GetDefault<UChartboostSettings>();

	// initialize iOS
#if PLATFORM_IOS
	if (!DefaultSettings->AppIDiOS.IsEmpty() && !DefaultSettings->AppSignatureiOS.IsEmpty()) {
		[Chartboost startWithAppId:[NSString stringWithFString:DefaultSettings->AppIDiOS]
					  appSignature:[NSString stringWithFString:DefaultSettings->AppSignatureiOS]
						  delegate:CBDelegateSingleton];
	}
#endif
	
	
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


void FChartboostPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE