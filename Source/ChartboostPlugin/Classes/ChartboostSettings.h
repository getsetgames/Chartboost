//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UChartboostSettings : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:	
	// General
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Auto Cache Ads"))
	bool AutoCacheAds = true;
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Should Request Interstitials in First Session"))
	bool FirstSessionInterstitials = true;
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Should Display Loading View for More Apps"))
	bool MoreAppsLoadingView = false;
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Should Prefetch Video Content"))
	bool PrefetchVideoContent = true;

	// iOS
	
	UPROPERTY(Config, EditAnywhere, Category=iOS, meta=(DisplayName="App ID"))
	FString AppIDiOS;

	UPROPERTY(Config, EditAnywhere, Category=iOS, meta=(DisplayName="App Signature"))
	FString AppSignatureiOS;
};