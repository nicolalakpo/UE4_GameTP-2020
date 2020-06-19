// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy_Melee.generated.h"

class UPawnSensingComponent;

UCLASS()
class UE4_GAMETP_API AEnemy_Melee : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy_Melee();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSenses;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
