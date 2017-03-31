//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "ChartboostFunctions.generated.h"

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
		CBLoadErrorPrefetchingIncomplete				UMETA(DisplayName="Prefetching Incomplete")
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
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static void ChartboostStart(FString AppId, FString AppSignature);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static bool ChartboostAdIsVisible();
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static void ChartboostSetAgeGatePassed(bool pass);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static void ChartboostSetCustomId(FString customId);

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost")
	static FString ChartboostGetCustomId();

	// interstitials
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static bool ChartboostHasInterstitial(FString Location = "Default");

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static void ChartboostShowInterstitial(FString Location = "Default");

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = "Chartboost|Interstitials")
	static void ChartboostCacheInterstitial(FString Location = "Default");

	// more apps

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static bool ChartboostHasMoreApps(FString Location = "Default");
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static void ChartboostShowMoreApps(FString Location = "Default");

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising"), Category = "Chartboost|More Apps")
	static void ChartboostCacheMoreApps(FString Location = "Default");

	// rewarded video

	UFUNCTION(BlueprintPure, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static bool ChartboostHasRewardedVideo(FString Location = "Default");
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void ChartboostShowRewardedVideo(FString Location = "Default");

	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising video"), Category = "Chartboost|Rewarded Video")
	static void ChartboostCacheRewardedVideo(FString Location = "Default");
};
