//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostFunctions.generated.h"

UENUM(BlueprintType)
enum EChartboostLocation
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

UCLASS(NotBlueprintable)
class UChartboostFunctions : public UObject {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "chartboost ad advertising intersitial"), Category = Chartboost)
	static void ShowInterstitial(EChartboostLocation Location);
};