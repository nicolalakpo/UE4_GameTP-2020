// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JumpPad.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UArrowComponent;


UCLASS()
class UE4_GAMETP_API AJumpPad : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AJumpPad();

protected:

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* OverlapBox;

	UFUNCTION()
		void OverlapBeing(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(EditInstanceOnly)
		float LaunchStrenght;
	UPROPERTY(EditInstanceOnly)
		float LaunchAngle;



	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* LaunchPadVFX;

};
