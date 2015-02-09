//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ChartboostSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UChartboostSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, Category=iOS, meta=(DisplayName="App ID"))
	FString AppIDiOS;

	UPROPERTY(Config, EditAnywhere, Category=iOS, meta=(DisplayName="App Signature"))
	FString AppSignatureiOS;	
};