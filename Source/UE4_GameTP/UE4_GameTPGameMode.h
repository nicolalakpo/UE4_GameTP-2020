// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE4_GameTPGameMode.generated.h"

UCLASS(minimalapi)
class AUE4_GameTPGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AActor> GameOverView;


public:
	AUE4_GameTPGameMode();

	void EndGame(APawn* InstigatorPawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
		void OnExitCompleted(APawn* InstigatorPawn);
};



