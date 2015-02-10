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
#endif

FString UChartboostFunctions::GetLocationString(EChartboost::Location Location) {
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EChartboost"), true);
	if (!EnumPtr) {
		return TEXT("");
	}
 
	FString LocationString = EnumPtr->GetEnumName(Location);
	
	return LocationString;
}

#pragma mark Interstitials

bool UChartboostFunctions::HasInterstitial(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasInterstitial:[NSString stringWithFString:LocationString]];
#endif
	
	return false;
}

void UChartboostFunctions::ShowInterstitial(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showInterstitial:[NSString stringWithFString:LocationString]];
#endif
}

void UChartboostFunctions::CacheInterstitial(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheInterstitial:[NSString stringWithFString:LocationString]];
#endif
}

#pragma mark More Apps

bool UChartboostFunctions::HasMoreApps(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasMoreApps:[NSString stringWithFString:LocationString]];
#endif
	
	return false;
}

void UChartboostFunctions::ShowMoreApps(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing more apps for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showMoreApps:[NSString stringWithFString:LocationString]];
#endif
}

void UChartboostFunctions::CacheMoreApps(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing more apps for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheMoreApps:[NSString stringWithFString:LocationString]];
#endif
}

#pragma mark Rewarded Video

bool UChartboostFunctions::HasRewardedVideo(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) {
		return false;
	}
	
#if PLATFORM_IOS
	return [Chartboost hasRewardedVideo:[NSString stringWithFString:LocationString]];
#endif
	
	return false;
}

void UChartboostFunctions::ShowRewardedVideo(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing rewarded video for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showRewardedVideo:[NSString stringWithFString:LocationString]];
#endif
}

void UChartboostFunctions::CacheRewardedVideo(EChartboost::Location Location) {
	FString LocationString = UChartboostFunctions::GetLocationString(Location);
	if (LocationString.IsEmpty()) return;
	
	UE_LOG(LogChartboost, Log, TEXT("Showing rewarded video for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost cacheRewardedVideo:[NSString stringWithFString:LocationString]];
#endif
}