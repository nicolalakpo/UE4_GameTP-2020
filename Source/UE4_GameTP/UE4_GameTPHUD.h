// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UE4_GameTPHUD.generated.h"

UCLASS()
class AUE4_GameTPHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUE4_GameTPHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

