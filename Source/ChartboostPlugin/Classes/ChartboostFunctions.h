//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostFunctions.generated.h"

UENUM(BlueprintType)
namespace EChartboost
{
	enum Location
	{
		CBLocationStartup		UMETA(DisplayName="Startup"),
		CBLocationHomeScreen	UMETA(DisplayName="Home Screen"),
		CBLocationMainMenu		UMETA(DisplayName="Main Menu"),
		CBLocationGameScreen	UMETA(DisplayName="Game Screen"),
		CBLocationAchievements	UMETA(DisplayName="Achievements"),
		CBLocationQuests		UMETA(DisplayName="Quests"),
		CBLocationPause			UMETA(DisplayName="Pause"),
		CBLocationLevelStart	UMETA(DisplayName="Level Start"),
		CBLocationLevelComplete	UMETA(DisplayName="Level Complete"),
		CBLocationTurnComplete	UMETA(DisplayName="Turn Complete"),
		CBLocationIAPStore		UMETA(DisplayName="IAP Store"),
		CBLocationItemStore		UMETA(DisplayName="Item Store"),
		CBLocationGameOver		UMETA(DisplayName="Game Over"),
		CBLocationLeaderBoard	UMETA(DisplayName="LeaderBoard"),
		CBLocationSettings		UMETA(DisplayName="Settings"),
		CBLocationQuit			UMETA(DisplayName="Quit"),
		CBLocationDefault		UMETA(DisplayName="Default")
	};	
}

UCLASS(NotBlueprintable)
class UChartboostFunctions : public UObject {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static bool ChartboostAdIsVisible();
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static void SetAgeGatePassed(bool pass);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static void SetCustomId(FString customId);

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static FString GetCustomId();

	// interstitials
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static bool HasInterstitial(EChartboost::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static void ShowInterstitial(EChartboost::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static void CacheInterstitial(EChartboost::Location Location);

	// more apps

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static bool HasMoreApps(EChartboost::Location Location);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static void ShowMoreApps(EChartboost::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static void CacheMoreApps(EChartboost::Location Location);

	// rewarded video

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static bool HasRewardedVideo(EChartboost::Location Location);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void ShowRewardedVideo(EChartboost::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void CacheRewardedVideo(EChartboost::Location Location);

private:
	static FString GetLocationString(EChartboost::Location Location);
};