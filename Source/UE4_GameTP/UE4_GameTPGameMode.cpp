// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4_GameTPGameMode.h"
#include "UE4_GameTPHUD.h"
#include "TPCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AUE4_GameTPGameMode::AUE4_GameTPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/BP_PlayerPawn"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUE4_GameTPHUD::StaticClass();
}

void AUE4_GameTPGameMode::EndGame(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr); // como es nullptr le hace disable al input especifico del instigator

		if (GameOverView)
		{
			TArray<AActor*> GOViewActors;
			UGameplayStatics::GetAllActorsOfClass(this, GameOverView, GOViewActors);

			if (GOViewActors.Num() > 0)
			{
				AActor* NewViewTarget = GOViewActors[0];

				APlayerController* PlayerCont = Cast<APlayerController>(InstigatorPawn->GetController());

				if (PlayerCont)
				{
					PlayerCont->SetViewTargetWithBlend(NewViewTarget, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
				}
			}
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Game Over View es null, Updatear gamemode con la subclase"));

	}

	OnExitCompleted(InstigatorPawn);
}
