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

void UChartboostFunctions::ShowInterstitial(EChartboost::Location Location) {
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EChartboost"), true);
	if (!EnumPtr) return;
 
	FString LocationString = EnumPtr->GetEnumName(Location);
	
	UE_LOG(LogChartboost, Log, TEXT("Showing interstitial for location: %s"), *LocationString);
	
#if PLATFORM_IOS
	[Chartboost showInterstitial:[NSString stringWithFString:LocationString]];
#endif
}
