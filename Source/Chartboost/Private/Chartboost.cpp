//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"
#include "ChartboostSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogChartboost);

#define LOCTEXT_NAMESPACE "Chartboost"

#if PLATFORM_IOS
#import <Chartboost/Chartboost.h>
#import <Chartboost/CBNewsfeed.h>
#import <CommonCrypto/CommonDigest.h>
#import <AdSupport/AdSupport.h>

#define CHARTBOOST_LOCATION(LOC) UChartboostFunctions::GetLocationFromString(FString(LOC))

@interface CBDelegate : NSObject <ChartboostDelegate>

@end

@implementation CBDelegate

// interstitials

- (void)didDisplayInterstitial:(CBLocation)location {
	UChartboostComponent::DidDisplayInterstitialDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCacheInterstitial:(CBLocation)location {
	UChartboostComponent::DidCacheInterstitialDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didFailToLoadInterstitial:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadInterstitialDelegate.Broadcast(CHARTBOOST_LOCATION(location), (EChartboostLoadError::LoadError)error);
}

- (void)didFailToRecordClick:(CBLocation)location withError:(CBClickError)error {
	UChartboostComponent::DidFailToRecordClickDelegate.Broadcast(CHARTBOOST_LOCATION(location), (EChartboostClickError::ClickError)error);
}

- (void)didDismissInterstitial:(CBLocation)location {
	UChartboostComponent::DidDismissInterstitialDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCloseInterstitial:(CBLocation)location {
	UChartboostComponent::DidCloseInterstitialDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didClickInterstitial:(CBLocation)location {
	UChartboostComponent::DidClickInterstitialDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

// more apps

- (void)didDisplayMoreApps:(CBLocation)location {
	UChartboostComponent::DidDisplayMoreAppsDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCacheMoreApps:(CBLocation)location {
	UChartboostComponent::DidCacheMoreAppsDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didDismissMoreApps:(CBLocation)location {
	UChartboostComponent::DidDismissMoreAppsDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCloseMoreApps:(CBLocation)location {
	UChartboostComponent::DidCloseMoreAppsDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didClickMoreApps:(CBLocation)location {
	UChartboostComponent::DidClickMoreAppsDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didFailToLoadMoreApps:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadMoreAppsDelegate.Broadcast(CHARTBOOST_LOCATION(location), (EChartboostLoadError::LoadError)error);
}

// rewarded videos

- (void)didPrefetchVideos {
	UChartboostComponent::DidPrefetchVideosDelegate.Broadcast();
}

- (void)didDisplayRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidDisplayRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCacheRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidCacheRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didFailToLoadRewardedVideo:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location), (EChartboostLoadError::LoadError)error);
}

- (void)didDismissRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidDismissRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCloseRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidCloseRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didClickRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidClickRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCompleteRewardedVideo:(CBLocation)location withReward:(int)reward {
	UChartboostComponent::DidCompleteRewardedVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location), reward);
}

- (void)willDisplayVideo:(CBLocation)location {
	UChartboostComponent::WillDisplayVideoDelegate.Broadcast(CHARTBOOST_LOCATION(location));
}

- (void)didCompleteAppStoreSheetFlow {
	UChartboostComponent::DidCompleteAppStoreSheetFlowDelegate.Broadcast();
}

- (void)didPauseClickForConfirmation {
	UChartboostComponent::DidPauseClickForConfirmationDelegate.Broadcast();
}

@end

static CBDelegate *CBDelegateSingleton = [[CBDelegate alloc] init];

#endif

class FChartboost : public IChartboost
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FChartboost, Chartboost )

void FChartboost::StartupModule()
{
	const UChartboostSettings* DefaultSettings = GetDefault<UChartboostSettings>();

	// initialize iOS
#if PLATFORM_IOS
	if (!DefaultSettings->AppIDiOS.IsEmpty() && !DefaultSettings->AppSignatureiOS.IsEmpty()) {
		[Chartboost startWithAppId:DefaultSettings->AppIDiOS.GetNSString()
					  appSignature:DefaultSettings->AppSignatureiOS.GetNSString()
						  delegate:CBDelegateSingleton];
		
		[Chartboost setAutoCacheAds:DefaultSettings->AutoCacheAds];
		[Chartboost setShouldRequestInterstitialsInFirstSession:DefaultSettings->FirstSessionInterstitials];
		[Chartboost setShouldDisplayLoadingViewForMoreApps:DefaultSettings->MoreAppsLoadingView];
		[Chartboost setShouldPrefetchVideoContent:DefaultSettings->PrefetchVideoContent];
		[Chartboost setShouldPauseClickForConfirmation:DefaultSettings->PauseForAgeGate];
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


void FChartboost::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE