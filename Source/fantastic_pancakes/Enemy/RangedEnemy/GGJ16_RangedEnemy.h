// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy/GGJ16_BaseEnemy.h"
#include "Enemy/RangedEnemy/GGJ16_FireballProjectile.h"
#include "GGJ16_RangedEnemy.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_RangedEnemy : public AGGJ16_BaseEnemy
{
	GENERATED_BODY()

protected:

		virtual void EnemyInteract(AActor* Interact) override;	

		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGGJ16_FireballProjectile> ProjectileClass;

		virtual void Tick(float DeltaSeconds) override;

		FRotator SpawnRotation;
		FVector SpawnLocation;

public:

	void FireProjectile();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		FRotator ProjectilePitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		FVector ProjectileOffset;
	
};
