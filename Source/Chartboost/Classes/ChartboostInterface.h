//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostInterface.generated.h"

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
	void DidDisplayInterstitial(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidCacheInterstitial(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidFailToLoadInterstitial(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidFailToRecordClick(EChartboostLocation::Location Location, EChartboostClickError::ClickError ClickError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidDismissInterstitial(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidCloseInterstitial(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Interstitials")
	void DidClickInterstitial(EChartboostLocation::Location Location);
	
	// more apps
	
//	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
//	bool ShouldDisplayMoreApps(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidDisplayMoreApps(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidCacheMoreApps(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidDismissMoreApps(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidCloseMoreApps(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidClickMoreApps(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|More Apps")
	void DidFailToLoadMoreApps(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError);
	
	// rewarded video
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidPrefetchVideos();
	
//	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
//	bool ShouldDisplayRewardedVideo(ChartboostLocation Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidDisplayRewardedVideo(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidCacheRewardedVideo(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidFailToLoadRewardedVideo(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidDismissRewardedVideo(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidCloseRewardedVideo(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidClickRewardedVideo(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void DidCompleteRewardedVideo(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost|Rewarded Video")
	void WillDisplayVideo(EChartboostLocation::Location Location);
	
	// general
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost")
	void DidCompleteAppStoreSheetFlow();
	
	UFUNCTION(BlueprintImplementableEvent, Category="Chartboost")
	void DidPauseClickForConfirmation();
};

