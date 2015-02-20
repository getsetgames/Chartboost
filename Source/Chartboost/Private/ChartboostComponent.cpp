//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "ChartboostPrivatePCH.h"

void UChartboostComponent::OnRegister()
{
	Super::OnRegister();
	
	// interstitials
	
	UChartboostComponent::DidDisplayInterstitialDelegate.AddUObject(this, &UChartboostComponent::DidDisplayInterstitial_Handler);
	UChartboostComponent::DidCacheInterstitialDelegate.AddUObject(this, &UChartboostComponent::DidCacheInterstitial_Handler);
	UChartboostComponent::DidFailToLoadInterstitialDelegate.AddUObject(this, &UChartboostComponent::DidFailToLoadInterstitial_Handler);
	UChartboostComponent::DidFailToRecordClickDelegate.AddUObject(this, &UChartboostComponent::DidFailToRecordClick_Handler);
	UChartboostComponent::DidDismissInterstitialDelegate.AddUObject(this, &UChartboostComponent::DidDismissInterstitial_Handler);
	UChartboostComponent::DidCloseInterstitialDelegate.AddUObject(this, &UChartboostComponent::DidCloseInterstitial_Handler);
	UChartboostComponent::DidClickInterstitialDelegate.AddUObject(this, &UChartboostComponent::DidClickInterstitial_Handler);
	
	//  more apps
	
	UChartboostComponent::DidDisplayMoreAppsDelegate.AddUObject(this, &UChartboostComponent::DidDisplayMoreApps_Handler);
	UChartboostComponent::DidCacheMoreAppsDelegate.AddUObject(this, &UChartboostComponent::DidCacheMoreApps_Handler);
	UChartboostComponent::DidDismissMoreAppsDelegate.AddUObject(this, &UChartboostComponent::DidDismissMoreApps_Handler);
	UChartboostComponent::DidCloseMoreAppsDelegate.AddUObject(this, &UChartboostComponent::DidCloseMoreApps_Handler);
	UChartboostComponent::DidClickMoreAppsDelegate.AddUObject(this, &UChartboostComponent::DidClickMoreApps_Handler);
	UChartboostComponent::DidFailToLoadMoreAppsDelegate.AddUObject(this, &UChartboostComponent::DidFailToLoadMoreApps_Handler);
	
	// rewarded videos
	
	UChartboostComponent::DidPrefetchVideosDelegate.AddUObject(this, &UChartboostComponent::DidPrefetchVideos_Handler);
	UChartboostComponent::DidDisplayRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidDisplayRewardedVideo_Handler);
	UChartboostComponent::DidCacheRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidCacheRewardedVideo_Handler);
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidFailToLoadRewardedVideo_Handler);
	UChartboostComponent::DidDismissRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidDismissRewardedVideo_Handler);
	UChartboostComponent::DidCloseRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidCloseRewardedVideo_Handler);
	UChartboostComponent::DidClickRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidClickRewardedVideo_Handler);
	UChartboostComponent::DidCompleteRewardedVideoDelegate.AddUObject(this, &UChartboostComponent::DidCompleteRewardedVideo_Handler);
	UChartboostComponent::WillDisplayVideoDelegate.AddUObject(this, &UChartboostComponent::WillDisplayVideo_Handler);
	
	// general
	
	UChartboostComponent::DidCompleteAppStoreSheetFlowDelegate.AddUObject(this, &UChartboostComponent::DidCompleteAppStoreSheetFlow_Handler);
	UChartboostComponent::DidPauseClickForConfirmationDelegate.AddUObject(this, &UChartboostComponent::DidPauseClickForConfirmation_Handler);
}

void UChartboostComponent::OnUnregister()
{
	Super::OnUnregister();
	
	// interstitials
	
	UChartboostComponent::DidDisplayInterstitialDelegate.RemoveAll(this);
	UChartboostComponent::DidCacheInterstitialDelegate.RemoveAll(this);
	UChartboostComponent::DidFailToLoadInterstitialDelegate.RemoveAll(this);
	UChartboostComponent::DidFailToRecordClickDelegate.RemoveAll(this);
	UChartboostComponent::DidDismissInterstitialDelegate.RemoveAll(this);
	UChartboostComponent::DidCloseInterstitialDelegate.RemoveAll(this);
	UChartboostComponent::DidClickInterstitialDelegate.RemoveAll(this);
	
	//  more apps
	
	UChartboostComponent::DidDisplayMoreAppsDelegate.RemoveAll(this);
	UChartboostComponent::DidCacheMoreAppsDelegate.RemoveAll(this);
	UChartboostComponent::DidDismissMoreAppsDelegate.RemoveAll(this);
	UChartboostComponent::DidCloseMoreAppsDelegate.RemoveAll(this);
	UChartboostComponent::DidClickMoreAppsDelegate.RemoveAll(this);
	UChartboostComponent::DidFailToLoadMoreAppsDelegate.RemoveAll(this);
	
	// rewarded videos
	
	UChartboostComponent::DidPrefetchVideosDelegate.RemoveAll(this);
	UChartboostComponent::DidDisplayRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidCacheRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidFailToLoadRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidDismissRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidCloseRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidClickRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::DidCompleteRewardedVideoDelegate.RemoveAll(this);
	UChartboostComponent::WillDisplayVideoDelegate.RemoveAll(this);
	
	// general
	
	UChartboostComponent::DidCompleteAppStoreSheetFlowDelegate.RemoveAll(this);
	UChartboostComponent::DidPauseClickForConfirmationDelegate.RemoveAll(this);
}

// interstitials

UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidDisplayInterstitialDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidCacheInterstitialDelegate;
UChartboostComponent::FChartboostLocationLoadErrorDelegate UChartboostComponent::DidFailToLoadInterstitialDelegate;
UChartboostComponent::FChartboostLocationClickErrorDelegate UChartboostComponent::DidFailToRecordClickDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidDismissInterstitialDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidCloseInterstitialDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidClickInterstitialDelegate;

//  more apps

UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidDisplayMoreAppsDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidCacheMoreAppsDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidDismissMoreAppsDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidCloseMoreAppsDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidClickMoreAppsDelegate;
UChartboostComponent::FChartboostLocationLoadErrorDelegate UChartboostComponent::DidFailToLoadMoreAppsDelegate;

// rewarded videos

UChartboostComponent::FChartboostDelegate UChartboostComponent::DidPrefetchVideosDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidDisplayRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidCacheRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationLoadErrorDelegate UChartboostComponent::DidFailToLoadRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidDismissRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidCloseRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::DidClickRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationRewardDelegate UChartboostComponent::DidCompleteRewardedVideoDelegate;
UChartboostComponent::FChartboostLocationDelegate UChartboostComponent::WillDisplayVideoDelegate;

// general

UChartboostComponent::FChartboostDelegate UChartboostComponent::DidCompleteAppStoreSheetFlowDelegate;
UChartboostComponent::FChartboostDelegate UChartboostComponent::DidPauseClickForConfirmationDelegate;
