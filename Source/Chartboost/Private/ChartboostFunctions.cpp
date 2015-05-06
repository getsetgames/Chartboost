//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"

#if PLATFORM_IOS

#define CHARTBOOST_LOCATION(LOC) UChartboostFunctions::GetLocationFromString(FString(LOC))

@interface CBDelegate : NSObject <ChartboostDelegate>

@end

static CBDelegate *CBDelegateSingleton = [[CBDelegate alloc] init];

#endif

FString UChartboostFunctions::GetLocationString(EChartboostLocation::Location Location) {
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EChartboostLocation"), true);
	if (!EnumPtr) {
		return TEXT("");
	}
 
	FString LocationString = EnumPtr->GetEnumName(Location);
	
	return LocationString;
}

EChartboostLocation::Location UChartboostFunctions::GetLocationFromString(FString Location) {
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EChartboostLocation"), true);
	if (!EnumPtr) {
		return EChartboostLocation::Location::CBLocationDefault;
	}
	
	int32 Index = EnumPtr->FindEnumIndex(FName(*Location));
	
	if (Index == INDEX_NONE) {
		return EChartboostLocation::Location::CBLocationDefault;
	}
	
	return (EChartboostLocation::Location)Index;
}

void UChartboostFunctions::ChartboostStart(FString AppId, FString AppSignature)
{
	const UChartboostSettings* DefaultSettings = GetDefault<UChartboostSettings>();
	
	// initialize iOS
#if PLATFORM_IOS
	if (!AppId.IsEmpty() && !AppSignature.IsEmpty()) {
		[Chartboost startWithAppId:AppId.GetNSString()
					  appSignature:AppSignature.GetNSString()
						  delegate:CBDelegateSingleton];
		
		[Chartboost setAutoCacheAds:DefaultSettings->AutoCacheAds];
		[Chartboost setShouldRequestInterstitialsInFirstSession:DefaultSettings->FirstSessionInterstitials];
		[Chartboost setShouldDisplayLoadingViewForMoreApps:DefaultSettings->MoreAppsLoadingView];
		[Chartboost setShouldPrefetchVideoContent:DefaultSettings->PrefetchVideoContent];
		[Chartboost setShouldPauseClickForConfirmation:DefaultSettings->PauseForAgeGate];
	}
#endif
}

bool UChartboostFunctions::ChartboostAdIsVisible() {
#if PLATFORM_IOS
	return [Chartboost isAnyViewVisible];
#endif

	return false;
}

void UChartboostFunctions::ChartboostSetAgeGatePassed(bool pass) {
#if PLATFORM_IOS
	[Chartboost didPassAgeGate:pass];
#endif
}

void UChartboostFunctions::ChartboostSetCustomId(FString customId) {
#if PLATFORM_IOS
	[Chartboost setCustomId:customId.GetNSString()];
#endif
}

FString UChartboostFunctions::ChartboostGetCustomId() {
#if PLATFORM_IOS
	return FString([Chartboost getCustomId]);
#endif
	
	return FString();
}

bool UChartboostFunctions::ChartboostHasInterstitial(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasInterstitial:LocationString.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowInterstitial(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showInterstitial:LocationString.GetNSString()];
#endif
}

void UChartboostFunctions::ChartboostCacheInterstitial(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheInterstitial:LocationString.GetNSString()];
#endif
}

bool UChartboostFunctions::ChartboostHasMoreApps(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasMoreApps:LocationString.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowMoreApps(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing more apps for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showMoreApps:LocationString.GetNSString()];
#endif
}

void UChartboostFunctions::ChartboostCacheMoreApps(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching more apps for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheMoreApps:LocationString.GetNSString()];
#endif
}

bool UChartboostFunctions::ChartboostHasRewardedVideo(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasRewardedVideo:LocationString.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowRewardedVideo(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing rewarded video for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showRewardedVideo:LocationString.GetNSString()];
#endif
}

void UChartboostFunctions::ChartboostCacheRewardedVideo(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching rewarded video for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheRewardedVideo:LocationString.GetNSString()];
#endif
}

#if PLATFORM_IOS
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
#endif
