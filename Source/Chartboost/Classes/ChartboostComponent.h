//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostFunctions.h"
#include "ChartboostComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UChartboostComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	DECLARE_MULTICAST_DELEGATE(FChartboostDelegate);
	DECLARE_MULTICAST_DELEGATE_OneParam(FChartboostLocationDelegate, EChartboostLocation::Location);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostLocationLoadErrorDelegate, EChartboostLocation::Location, EChartboostLoadError::LoadError);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostLocationRewardDelegate, EChartboostLocation::Location, int32);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostLocationClickErrorDelegate, EChartboostLocation::Location, EChartboostClickError::ClickError);
	
	// interstitials
	
	static FChartboostLocationDelegate DidDisplayInterstitialDelegate;
	static FChartboostLocationDelegate DidCacheInterstitialDelegate;
	static FChartboostLocationLoadErrorDelegate DidFailToLoadInterstitialDelegate;
	static FChartboostLocationClickErrorDelegate DidFailToRecordClickDelegate;
	static FChartboostLocationDelegate DidDismissInterstitialDelegate;
	static FChartboostLocationDelegate DidCloseInterstitialDelegate;
	static FChartboostLocationDelegate DidClickInterstitialDelegate;
	
	//  more apps
	
	static FChartboostLocationDelegate DidDisplayMoreAppsDelegate;
	static FChartboostLocationDelegate DidCacheMoreAppsDelegate;
	static FChartboostLocationDelegate DidDismissMoreAppsDelegate;
	static FChartboostLocationDelegate DidCloseMoreAppsDelegate;
	static FChartboostLocationDelegate DidClickMoreAppsDelegate;
	static FChartboostLocationLoadErrorDelegate DidFailToLoadMoreAppsDelegate;
	
	// rewarded videos
	
	static FChartboostDelegate DidPrefetchVideosDelegate;
	static FChartboostLocationDelegate DidDisplayRewardedVideoDelegate;
	static FChartboostLocationDelegate DidCacheRewardedVideoDelegate;
	static FChartboostLocationLoadErrorDelegate DidFailToLoadRewardedVideoDelegate;
	static FChartboostLocationDelegate DidDismissRewardedVideoDelegate;
	static FChartboostLocationDelegate DidCloseRewardedVideoDelegate;
	static FChartboostLocationDelegate DidClickRewardedVideoDelegate;
	static FChartboostLocationRewardDelegate DidCompleteRewardedVideoDelegate;
	static FChartboostLocationDelegate WillDisplayVideoDelegate;
	
	// general
	
	static FChartboostDelegate DidCompleteAppStoreSheetFlowDelegate;
	static FChartboostDelegate DidPauseClickForConfirmationDelegate;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChartboostDynDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChartboostLocationDynDelegate, EChartboostLocation::Location, Location);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostLocationLoadErrorDynDelegate, EChartboostLocation::Location, Location, EChartboostLoadError::LoadError, LoadError);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostLocationClickErrorDynDelegate, EChartboostLocation::Location, Location, EChartboostClickError::ClickError, ClickError);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostLocationRewardDynDelegate, EChartboostLocation::Location, Location, int32, Reward);
	
	// interstitials
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidDisplayInterstitial;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidCacheInterstitial;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationLoadErrorDynDelegate DidFailToLoadInterstitial;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationClickErrorDynDelegate DidFailToRecordClick;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidDismissInterstitial;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidCloseInterstitial;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidClickInterstitial;
	
	//  more apps
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidDisplayMoreApps;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidCacheMoreApps;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidDismissMoreApps;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidCloseMoreApps;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidClickMoreApps;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationLoadErrorDynDelegate DidFailToLoadMoreApps;
	
	// rewarded videos
	
	UPROPERTY(BlueprintAssignable)
	FChartboostDynDelegate DidPrefetchVideos;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidDisplayRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidCacheRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationLoadErrorDynDelegate DidFailToLoadRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidDismissRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidCloseRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate DidClickRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationRewardDynDelegate DidCompleteRewardedVideo;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostLocationDynDelegate WillDisplayVideo;
	
	// general
	
	UPROPERTY(BlueprintAssignable)
	FChartboostDynDelegate DidCompleteAppStoreSheetFlow;
	
	UPROPERTY(BlueprintAssignable)
	FChartboostDynDelegate DidPauseClickForConfirmation;
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:	
	// interstitials

	void DidDisplayInterstitial_Handler(EChartboostLocation::Location Location) { DidDisplayInterstitial.Broadcast(Location); }
	void DidCacheInterstitial_Handler(EChartboostLocation::Location Location) { DidCacheInterstitial.Broadcast(Location); }
	void DidFailToLoadInterstitial_Handler(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError) { DidFailToLoadInterstitial.Broadcast(Location, LoadError); }
	void DidFailToRecordClick_Handler(EChartboostLocation::Location Location, EChartboostClickError::ClickError ClickError) { DidFailToRecordClick.Broadcast(Location, ClickError); }
	void DidDismissInterstitial_Handler(EChartboostLocation::Location Location) { DidDismissInterstitial.Broadcast(Location); }
	void DidCloseInterstitial_Handler(EChartboostLocation::Location Location) { DidCloseInterstitial.Broadcast(Location); }
	void DidClickInterstitial_Handler(EChartboostLocation::Location Location) { DidClickInterstitial.Broadcast(Location); }
	
	//  more apps
	
	void DidDisplayMoreApps_Handler(EChartboostLocation::Location Location) { DidDisplayMoreApps.Broadcast(Location); }
	void DidCacheMoreApps_Handler(EChartboostLocation::Location Location) { DidCacheMoreApps.Broadcast(Location); }
	void DidDismissMoreApps_Handler(EChartboostLocation::Location Location) { DidDismissMoreApps.Broadcast(Location); }
	void DidCloseMoreApps_Handler(EChartboostLocation::Location Location) { DidCloseMoreApps.Broadcast(Location); }
	void DidClickMoreApps_Handler(EChartboostLocation::Location Location) { DidClickMoreApps.Broadcast(Location); }
	void DidFailToLoadMoreApps_Handler(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError) { DidFailToLoadMoreApps.Broadcast(Location, LoadError); }
	
	// rewarded videos
	
	void DidPrefetchVideos_Handler() { DidPrefetchVideos.Broadcast(); }
	void DidDisplayRewardedVideo_Handler(EChartboostLocation::Location Location) { DidDisplayRewardedVideo.Broadcast(Location); }
	void DidCacheRewardedVideo_Handler(EChartboostLocation::Location Location) { DidCacheRewardedVideo.Broadcast(Location); }
	void DidFailToLoadRewardedVideo_Handler(EChartboostLocation::Location Location, EChartboostLoadError::LoadError LoadError) { DidFailToLoadRewardedVideo.Broadcast(Location, LoadError); }
	void DidDismissRewardedVideo_Handler(EChartboostLocation::Location Location) { DidDismissRewardedVideo.Broadcast(Location); }
	void DidCloseRewardedVideo_Handler(EChartboostLocation::Location Location) { DidCloseRewardedVideo.Broadcast(Location); }
	void DidClickRewardedVideo_Handler(EChartboostLocation::Location Location) { DidClickRewardedVideo.Broadcast(Location); }
	void DidCompleteRewardedVideo_Handler(EChartboostLocation::Location Location, int Reward) { DidCompleteRewardedVideo.Broadcast(Location, Reward); }
	void WillDisplayVideo_Handler(EChartboostLocation::Location Location) { WillDisplayVideo.Broadcast(Location); }
	
	// general

	void DidCompleteAppStoreSheetFlow_Handler() { DidCompleteAppStoreSheetFlow.Broadcast(); }
	void DidPauseClickForConfirmation_Handler() { DidPauseClickForConfirmation.Broadcast(); }
};
