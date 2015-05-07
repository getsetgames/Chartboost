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
	DECLARE_MULTICAST_DELEGATE_OneParam(FChartboostLocationDelegate, FString);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostLocationLoadErrorDelegate, FString, EChartboostLoadError::LoadError);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostLocationRewardDelegate, FString, int32);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FChartboostLocationClickErrorDelegate, FString, EChartboostClickError::ClickError);
	
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
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChartboostLocationDynDelegate, FString, Location);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostLocationLoadErrorDynDelegate, FString, Location, EChartboostLoadError::LoadError, LoadError);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostLocationClickErrorDynDelegate, FString, Location, EChartboostClickError::ClickError, ClickError);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChartboostLocationRewardDynDelegate, FString, Location, int32, Reward);
	
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

	void DidDisplayInterstitial_Handler(FString Location) { DidDisplayInterstitial.Broadcast(Location); }
	void DidCacheInterstitial_Handler(FString Location) { DidCacheInterstitial.Broadcast(Location); }
	void DidFailToLoadInterstitial_Handler(FString Location, EChartboostLoadError::LoadError LoadError) { DidFailToLoadInterstitial.Broadcast(Location, LoadError); }
	void DidFailToRecordClick_Handler(FString Location, EChartboostClickError::ClickError ClickError) { DidFailToRecordClick.Broadcast(Location, ClickError); }
	void DidDismissInterstitial_Handler(FString Location) { DidDismissInterstitial.Broadcast(Location); }
	void DidCloseInterstitial_Handler(FString Location) { DidCloseInterstitial.Broadcast(Location); }
	void DidClickInterstitial_Handler(FString Location) { DidClickInterstitial.Broadcast(Location); }
	
	//  more apps
	
	void DidDisplayMoreApps_Handler(FString Location) { DidDisplayMoreApps.Broadcast(Location); }
	void DidCacheMoreApps_Handler(FString Location) { DidCacheMoreApps.Broadcast(Location); }
	void DidDismissMoreApps_Handler(FString Location) { DidDismissMoreApps.Broadcast(Location); }
	void DidCloseMoreApps_Handler(FString Location) { DidCloseMoreApps.Broadcast(Location); }
	void DidClickMoreApps_Handler(FString Location) { DidClickMoreApps.Broadcast(Location); }
	void DidFailToLoadMoreApps_Handler(FString Location, EChartboostLoadError::LoadError LoadError) { DidFailToLoadMoreApps.Broadcast(Location, LoadError); }
	
	// rewarded videos
	
	void DidPrefetchVideos_Handler() { DidPrefetchVideos.Broadcast(); }
	void DidDisplayRewardedVideo_Handler(FString Location) { DidDisplayRewardedVideo.Broadcast(Location); }
	void DidCacheRewardedVideo_Handler(FString Location) { DidCacheRewardedVideo.Broadcast(Location); }
	void DidFailToLoadRewardedVideo_Handler(FString Location, EChartboostLoadError::LoadError LoadError) { DidFailToLoadRewardedVideo.Broadcast(Location, LoadError); }
	void DidDismissRewardedVideo_Handler(FString Location) { DidDismissRewardedVideo.Broadcast(Location); }
	void DidCloseRewardedVideo_Handler(FString Location) { DidCloseRewardedVideo.Broadcast(Location); }
	void DidClickRewardedVideo_Handler(FString Location) { DidClickRewardedVideo.Broadcast(Location); }
	void DidCompleteRewardedVideo_Handler(FString Location, int Reward) { DidCompleteRewardedVideo.Broadcast(Location, Reward); }
	void WillDisplayVideo_Handler(FString Location) { WillDisplayVideo.Broadcast(Location); }
	
	// general

	void DidCompleteAppStoreSheetFlow_Handler() { DidCompleteAppStoreSheetFlow.Broadcast(); }
	void DidPauseClickForConfirmation_Handler() { DidPauseClickForConfirmation.Broadcast(); }
};
