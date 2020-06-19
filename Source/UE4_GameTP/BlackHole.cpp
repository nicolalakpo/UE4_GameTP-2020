// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	DestructionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Destructor Sphere"));
	DestructionSphere->SetSphereRadius(50);
	DestructionSphere->SetupAttachment(MeshComp);

	DestructionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABlackHole::OverlapDestructionSphere);

	GrabberSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Grabber Sphere"));
	GrabberSphere->SetSphereRadius(2500);
	GrabberSphere->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*> OverlappingComponents;
	GrabberSphere->GetOverlappingComponents(OverlappingComponents);


	for (int32 i = 0; i < OverlappingComponents.Num(); i++)
	{
		UPrimitiveComponent* PrimitiveComps = OverlappingComponents[i];
		if (PrimitiveComps && PrimitiveComps->IsSimulatingPhysics())
		{
			const float SphereRadius = GrabberSphere->GetScaledSphereRadius();
			const float PullStrenght = -2000;

			PrimitiveComps->AddRadialForce(GetActorLocation(), SphereRadius, PullStrenght, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}

}


void ABlackHole::OverlapDestructionSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor && bDoesDestroy)
	{
		OtherActor->Destroy();
	}
}