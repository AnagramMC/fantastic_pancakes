// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy/GGJ16_BaseEnemy.h"
#include "Perception/PawnSensingComponent.h"
#include "GGJ16_MeleeEnemy.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_MeleeEnemy : public AGGJ16_BaseEnemy
{
	GENERATED_BODY()

	AGGJ16_MeleeEnemy();
	
protected:

	virtual void BeginPlay() override;

	virtual void EnemyInteract(AActor* Interact) override;

	UPROPERTY(EditDefaultsOnly)
	UPawnSensingComponent* SensingComponent;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* MeleeCollider;

	UFUNCTION()
	void OnSeePlayer(APawn* Pawn);

public:

	UPROPERTY(EditDefaultsOnly)
	FName PlayerKeyName;

	
	
};
