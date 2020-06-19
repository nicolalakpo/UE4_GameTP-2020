// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AJumpPad::AJumpPad()
{

	OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Box"));
	OverlapBox->SetBoxExtent(FVector(75, 75, 50));
	RootComponent = OverlapBox;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComponent->SetupAttachment(RootComponent);

	OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &AJumpPad::OverlapBeing);

	LaunchStrenght = 1500;
	LaunchAngle = 45.0f;
}


void AJumpPad::OverlapBeing(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	FRotator LaunchDirection = GetActorRotation();
	LaunchDirection.Pitch = LaunchAngle;
	FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrenght;

	ACharacter* OtherChar = Cast<ACharacter>(OtherActor);
	if (OtherChar)
	{
		OtherChar->LaunchCharacter(LaunchVelocity, true, true);

		if (LaunchPadVFX)
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), LaunchPadVFX, GetActorLocation());
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulse(LaunchVelocity, NAME_None, true);

		if (LaunchPadVFX)
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), LaunchPadVFX, GetActorLocation());
	}


}


