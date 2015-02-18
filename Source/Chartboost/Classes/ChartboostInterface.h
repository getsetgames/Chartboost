//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostInterface.generated.h"

/** Interface for assets which contain gameplay tags */
UINTERFACE(Blueprintable)
class UChartboostInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IChartboostInterface
{
	GENERATED_IINTERFACE_BODY()
	
	// interstitials
	
//	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
//	bool ShouldRequestInterstitial(ChartboostLocation Location);
//	
//	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
//	bool ShouldDisplayInterstitial(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidDisplayInterstitial(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidCacheInterstitial(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidFailToLoadInterstitial(ChartboostLocation Location, ChartboostLoadError LoadError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidFailToRecordClick(ChartboostLocation Location, ChartboostClickError ClickError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidDismissInterstitial(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidCloseInterstitial(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidClickInterstitial(ChartboostLocation Location);
	
	// more apps
	
//	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
//	bool ShouldDisplayMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidDisplayMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidCacheMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidDismissMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidCloseMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidClickMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidFailToLoadMoreApps(ChartboostLocation Location, ChartboostLoadError LoadError);
	
	// rewarded video
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidPrefetchVideos();
	
//	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
//	bool ShouldDisplayRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidDisplayRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidCacheRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidFailToLoadRewardedVideo(ChartboostLocation Location, ChartboostLoadError LoadError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidDismissRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidCloseRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidClickRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidCompleteRewardedVideo(ChartboostLocation Location, ChartboostLoadError LoadError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void WillDisplayVideo(ChartboostLocation Location);
	
	// general
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost")
	void DidCompleteAppStoreSheetFlow();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost")
	void DidPauseClickForConfirmation();
};

