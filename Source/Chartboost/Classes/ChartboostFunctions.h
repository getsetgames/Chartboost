//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostFunctions.generated.h"

UENUM(BlueprintType)
namespace EChartboostLocation {
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

UENUM(BlueprintType)
namespace EChartboostLoadError {
	enum LoadError
	{
		CBLoadErrorInternal								UMETA(DisplayName="Internal"),
		CBLoadErrorInternetUnavailable					UMETA(DisplayName="Internet Unavailable"),
		CBLoadErrorTooManyConnections					UMETA(DisplayName="Too Many Connections"),
		CBLoadErrorWrongOrientation						UMETA(DisplayName="Wrong Orientation"),
		CBLoadErrorFirstSessionInterstitialsDisabled	UMETA(DisplayName="First Session Interstitials Disabled"),
		CBLoadErrorNetworkFailure						UMETA(DisplayName="Network Failure"),
		CBLoadErrorNoAdFound							UMETA(DisplayName="No Ad Found"),
		CBLoadErrorSessionNotStarted					UMETA(DisplayName="Session Not Started"),
		CBLoadErrorUserCancellation						UMETA(DisplayName="User Cancellation"),
		CBLoadErrorNoLocationFound						UMETA(DisplayName="No Location Found"),
	};
}

UENUM(BlueprintType)
namespace EChartboostClickError {
	enum ClickError
	{
		CBClickErrorUriInvalid		UMETA(DisplayName="Uri Invalid"),
		CBClickErrorUriUnrecognized	UMETA(DisplayName="Uri Unrecognized"),
		CBClickErrorAgeGateFailure	UMETA(DisplayName="Age Gate Failure"),
		CBClickErrorInternal		UMETA(DisplayName="Internal"),
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
	static bool HasInterstitial(EChartboostLocation::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static void ShowInterstitial(EChartboostLocation::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static void CacheInterstitial(EChartboostLocation::Location Location);

	// more apps

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static bool HasMoreApps(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static void ShowMoreApps(EChartboostLocation::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static void CacheMoreApps(EChartboostLocation::Location Location);

	// rewarded video

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static bool HasRewardedVideo(EChartboostLocation::Location Location);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void ShowRewardedVideo(EChartboostLocation::Location Location);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void CacheRewardedVideo(EChartboostLocation::Location Location);

	static FString GetLocationString(EChartboostLocation::Location Location);
	static EChartboostLocation::Location GetLocationFromString(FString Location);
};