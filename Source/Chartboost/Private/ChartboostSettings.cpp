//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostSettings.h"
#include "ChartboostPrivatePCH.h"

UChartboostSettings::UChartboostSettings(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, AutoCacheAds(true)
, FirstSessionInterstitials(true)
, MoreAppsLoadingView(false)
, PrefetchVideoContent(true)
, PauseForAgeGate(false)
{
}
