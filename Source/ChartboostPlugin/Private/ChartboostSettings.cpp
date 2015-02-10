//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPluginPrivatePCH.h"
#include "ChartboostSettings.h"

UChartboostSettings::UChartboostSettings(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, AutoCacheAds(true)
, FirstSessionInterstitials(true)
, MoreAppsLoadingView(false)
, PrefetchVideoContent(true)
{
}
