// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Melee.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEnemy_Melee::AEnemy_Melee()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSenses = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Senses"));

	PawnSenses->OnSeePawn.AddDynamic(this, &AEnemy_Melee::OnPawnSeen);
}

// Called when the game starts or when spawned
void AEnemy_Melee::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemy_Melee::OnPawnSeen(APawn * SeenPawn)
{
	if (SeenPawn == nullptr) return;

	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 8, FColor::Red, false, 7.0f);

}


// Called every frame
void AEnemy_Melee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
}

