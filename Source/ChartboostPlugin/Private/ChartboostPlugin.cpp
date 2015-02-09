//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPluginPrivatePCH.h"

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
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FChartboostPlugin, ChartboostPlugin )

static FString AppIDString( TEXT( "" ) );
static FString AppSignatureString( TEXT( "" ) );

void FChartboostPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
#if PLATFORM_IOS
	GConfig->GetString(TEXT("Chartboost"), TEXT("AppIDiOS"), AppIDString, GEngineIni);
	GConfig->GetString(TEXT("Chartboost"), TEXT("AppSignatureiOS"), AppSignatureString, GEngineIni);
	
	if (!AppIDString.IsEmpty() && !AppSignatureString.IsEmpty()) {
		[Chartboost startWithAppId:[NSString stringWithFString:AppIDString]
					  appSignature:[NSString stringWithFString:AppSignatureString]
						  delegate:CBDelegateSingleton];
	}
#endif
}


void FChartboostPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

DEFINE_LOG_CATEGORY(LogChartboost);