//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"

#if PLATFORM_IOS

@interface CBDelegate : NSObject <ChartboostDelegate>

@end

static CBDelegate *CBDelegateSingleton = [[CBDelegate alloc] init];

#endif

void UChartboostFunctions::ChartboostStart(FString AppId, FString AppSignature)
{
	const UChartboostSettings* DefaultSettings = GetDefault<UChartboostSettings>();
	
	// initialize iOS
#if PLATFORM_IOS
	if (!AppId.IsEmpty() && !AppSignature.IsEmpty()) {
		dispatch_sync(dispatch_get_main_queue(), ^{
			[Chartboost startWithAppId:AppId.GetNSString()
						  appSignature:AppSignature.GetNSString()
							  delegate:CBDelegateSingleton];
			
			[Chartboost setAutoCacheAds:DefaultSettings->AutoCacheAds];
			[Chartboost setShouldRequestInterstitialsInFirstSession:DefaultSettings->FirstSessionInterstitials];
			[Chartboost setShouldDisplayLoadingViewForMoreApps:DefaultSettings->MoreAppsLoadingView];
			[Chartboost setShouldPrefetchVideoContent:DefaultSettings->PrefetchVideoContent];
			[Chartboost setShouldPauseClickForConfirmation:DefaultSettings->PauseForAgeGate];
		});
	}
#endif
}

bool UChartboostFunctions::ChartboostAdIsVisible() {
#if PLATFORM_IOS
	__block bool Result = false;
	dispatch_sync(dispatch_get_main_queue(), ^{
		Result = [Chartboost isAnyViewVisible];
	});
	return Result;
#endif

	return false;
}

void UChartboostFunctions::ChartboostSetAgeGatePassed(bool pass) {
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost didPassAgeGate:pass];
	});
#endif
}

void UChartboostFunctions::ChartboostSetCustomId(FString customId) {
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost setCustomId:customId.GetNSString()];
	});
#endif
}

FString UChartboostFunctions::ChartboostGetCustomId() {
#if PLATFORM_IOS
	__block NSString* CustomId = @"";
	dispatch_sync(dispatch_get_main_queue(), ^{
		CustomId = [Chartboost getCustomId];
	});
	return FString(CustomId);
#endif
	
	return FString();
}

bool UChartboostFunctions::ChartboostHasInterstitial(FString Location) {
	if (Location.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	__block bool Result = false;
	dispatch_sync(dispatch_get_main_queue(), ^{
		Result = [Chartboost hasInterstitial:Location.GetNSString()];
	});
	return Result;
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowInterstitial(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *Location);
	
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost showInterstitial:Location.GetNSString()];
	});
#endif
}

void UChartboostFunctions::ChartboostCacheInterstitial(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching interstitial for location: %s"), *Location);
	
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost cacheInterstitial:Location.GetNSString()];
	});
#endif
}

bool UChartboostFunctions::ChartboostHasMoreApps(FString Location) {
	if (Location.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	__block bool Result = false;
	dispatch_sync(dispatch_get_main_queue(), ^{
		Result = [Chartboost hasMoreApps:Location.GetNSString()];
	});
	return Result;
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowMoreApps(FString Location) {
	if (Location.IsEmpty())
	{
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Showing more apps for location: %s"), *Location);
	
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost showMoreApps:Location.GetNSString()];
	});
#endif
}

void UChartboostFunctions::ChartboostCacheMoreApps(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching more apps for location: %s"), *Location);
	
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost cacheMoreApps:Location.GetNSString()];
	});
#endif
}

bool UChartboostFunctions::ChartboostHasRewardedVideo(FString Location) {
	if (Location.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	__block bool Result = false;
	dispatch_sync(dispatch_get_main_queue(), ^{
		Result = [Chartboost hasRewardedVideo:Location.GetNSString()];
	});
	return Result;
#endif
	
	return false;
}

void UChartboostFunctions::ChartboostShowRewardedVideo(FString Location) {
	if (Location.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing rewarded video for location: %s"), *Location);
	
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost showRewardedVideo:Location.GetNSString()];
	});
#endif
}

void UChartboostFunctions::ChartboostCacheRewardedVideo(FString Location) {
	if (Location.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching rewarded video for location: %s"), *Location);
	
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[Chartboost cacheRewardedVideo:Location.GetNSString()];
	});
#endif
}

#if PLATFORM_IOS
@implementation CBDelegate

// interstitials

- (void)didDisplayInterstitial:(CBLocation)location {
	UChartboostComponent::DidDisplayInterstitialDelegate.Broadcast(FString(location));
}

- (void)didCacheInterstitial:(CBLocation)location {
	UChartboostComponent::DidCacheInterstitialDelegate.Broadcast(FString(location));
}

- (void)didFailToLoadInterstitial:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadInterstitialDelegate.Broadcast(FString(location), (EChartboostLoadError::LoadError)error);
}

- (void)didFailToRecordClick:(CBLocation)location withError:(CBClickError)error {
	UChartboostComponent::DidFailToRecordClickDelegate.Broadcast(FString(location), (EChartboostClickError::ClickError)error);
}

- (void)didDismissInterstitial:(CBLocation)location {
	UChartboostComponent::DidDismissInterstitialDelegate.Broadcast(FString(location));
}

- (void)didCloseInterstitial:(CBLocation)location {
	UChartboostComponent::DidCloseInterstitialDelegate.Broadcast(FString(location));
}

- (void)didClickInterstitial:(CBLocation)location {
	UChartboostComponent::DidClickInterstitialDelegate.Broadcast(FString(location));
}

// more apps

- (void)didDisplayMoreApps:(CBLocation)location {
	UChartboostComponent::DidDisplayMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didCacheMoreApps:(CBLocation)location {
	UChartboostComponent::DidCacheMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didDismissMoreApps:(CBLocation)location {
	UChartboostComponent::DidDismissMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didCloseMoreApps:(CBLocation)location {
	UChartboostComponent::DidCloseMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didClickMoreApps:(CBLocation)location {
	UChartboostComponent::DidClickMoreAppsDelegate.Broadcast(FString(location));
}

- (void)didFailToLoadMoreApps:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadMoreAppsDelegate.Broadcast(FString(location), (EChartboostLoadError::LoadError)error);
}

// rewarded videos

- (void)didPrefetchVideos {
	UChartboostComponent::DidPrefetchVideosDelegate.Broadcast();
}

- (void)didDisplayRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidDisplayRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didCacheRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidCacheRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didFailToLoadRewardedVideo:(CBLocation)location withError:(CBLoadError)error {
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.Broadcast(FString(location), (EChartboostLoadError::LoadError)error);
}

- (void)didDismissRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidDismissRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didCloseRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidCloseRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didClickRewardedVideo:(CBLocation)location {
	UChartboostComponent::DidClickRewardedVideoDelegate.Broadcast(FString(location));
}

- (void)didCompleteRewardedVideo:(CBLocation)location withReward:(int)reward {
	UChartboostComponent::DidCompleteRewardedVideoDelegate.Broadcast(FString(location), reward);
}

- (void)willDisplayVideo:(CBLocation)location {
	UChartboostComponent::WillDisplayVideoDelegate.Broadcast(FString(location));
}

- (void)didCompleteAppStoreSheetFlow {
	UChartboostComponent::DidCompleteAppStoreSheetFlowDelegate.Broadcast();
}

- (void)didPauseClickForConfirmation {
	UChartboostComponent::DidPauseClickForConfirmationDelegate.Broadcast();
}

@end
#endif
