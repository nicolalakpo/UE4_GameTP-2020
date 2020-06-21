// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_Hitscan.generated.h"

class USkeletalMeshComponent;
class UDamageType;
class UParticleSystem;

USTRUCT() //Contiene la informacion del linetrace
struct FHitScanTrace
{
	GENERATED_BODY()

public:


	UPROPERTY()
		FVector_NetQuantize NetTraceTo;

	UPROPERTY()
		FRotator NetVFXFinalRotator;
	UPROPERTY()
		bool bIsBloodHit;

	UPROPERTY()
		float NetWeaponDmg;
	UPROPERTY()
		float NetPlayerScore;
	UPROPERTY()
		AActor* NetWeaponOwner;
};


UCLASS()
class UE4_GAMETP_API AWeapon_Hitscan : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon_Hitscan();

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USkeletalMeshComponent* WeaponMesh;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		TSubclassOf<UDamageType> WeaponDamageType;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* ImpactEffect;

	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* RaytraceEffect;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UCameraShake> FireCameraShake;



	UPROPERTY(EditDefaultsOnly, Category = "Weapon Damage")
		float BaseDamage;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Damage")
		float DmgMultiplierHead;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Damage")
		float DmgMultiplierTorso;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Damage")
		float DmgMultiplierLimbs;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Score")
		float ScoreHead;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Score")
		float ScoreTorso;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Score")
		float ScoreLimbs;


	void SendScoreUpdate(float ScoreUpdate, AActor* MyOwner);

	UFUNCTION(Server, Reliable, WithValidation)
		void ServerFire();

	UPROPERTY(ReplicatedUsing = OnRep_HitscanTrace)
		FHitScanTrace HitScanTrace;

	UFUNCTION()
		void OnRep_HitscanTrace();

public:

	UFUNCTION(BlueprintCallable)
		void Fire();

	void PlayShootingEffects(FVector TraceEnd);

	void PlayBloodEffect(FVector VFXPosition, FRotator VFXRotation, bool bHitFleshMat);
};
