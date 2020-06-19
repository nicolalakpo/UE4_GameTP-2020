// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitZone.generated.h"

class UBoxComponent;


UCLASS()
class UE4_GAMETP_API AExitZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExitZone();

protected:

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
		UBoxComponent* OverlapComponent;


	UFUNCTION()
		void BoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};