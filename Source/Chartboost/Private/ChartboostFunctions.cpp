//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"

#if PLATFORM_IOS
#import <Chartboost/Chartboost.h>
#import <Chartboost/CBNewsfeed.h>
#import <CommonCrypto/CommonDigest.h>
#import <AdSupport/AdSupport.h>
#endif

FString UChartboostFunctions::GetLocationString(EChartboostLocation::Location Location) {
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EChartboostLocation"), true);
	if (!EnumPtr) {
		return TEXT("");
	}
 
	FString LocationString = EnumPtr->GetEnumName(Location);
	
	return LocationString;
}

bool UChartboostFunctions::ChartboostAdIsVisible() {
#if PLATFORM_IOS
	return [Chartboost isAnyViewVisible];
#endif

	return false;
}

void UChartboostFunctions::SetAgeGatePassed(bool pass) {
#if PLATFORM_IOS
	[Chartboost didPassAgeGate:pass];
#endif
}

void UChartboostFunctions::SetCustomId(FString customId) {
#if PLATFORM_IOS
	[Chartboost setCustomId:customId.GetNSString()];
#endif
}

FString UChartboostFunctions::GetCustomId() {
#if PLATFORM_IOS
	return FString([Chartboost getCustomId]);
#endif
	
	return FString();
}

bool UChartboostFunctions::HasInterstitial(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasInterstitial:LocationString.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ShowInterstitial(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showInterstitial:LocationString.GetNSString()];
#endif
}

void UChartboostFunctions::CacheInterstitial(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheInterstitial:LocationString.GetNSString()];
#endif
}

bool UChartboostFunctions::HasMoreApps(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasMoreApps:LocationString.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ShowMoreApps(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing more apps for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showMoreApps:LocationString.GetNSString()];
#endif
}

void UChartboostFunctions::CacheMoreApps(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching more apps for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheMoreApps:LocationString.GetNSString()];
#endif
}

bool UChartboostFunctions::HasRewardedVideo(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasRewardedVideo:LocationString.GetNSString()];
#endif
	
	return false;
}

void UChartboostFunctions::ShowRewardedVideo(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing rewarded video for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showRewardedVideo:LocationString.GetNSString()];
#endif
}

void UChartboostFunctions::CacheRewardedVideo(EChartboostLocation::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return;
	}
	
	UE_LOG(LogChartboost, Log, TEXT("Caching rewarded video for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheRewardedVideo:LocationString.GetNSString()];
#endif
}