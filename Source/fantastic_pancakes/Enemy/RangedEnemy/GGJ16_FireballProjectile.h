// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GGJ16_FireballProjectile.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_FireballProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGJ16_FireballProjectile();

	UPROPERTY(EditDefaultsOnly)
	UProjectileMovementComponent* Projectile;

private:

	float speedPower;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* Collider;	

	UFUNCTION()
	virtual void OnActorOverlap(AActor* OtherActor);
	
};
