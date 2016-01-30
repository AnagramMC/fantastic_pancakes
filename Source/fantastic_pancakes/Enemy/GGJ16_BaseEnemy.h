// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GGJ16_BaseEnemy.generated.h"

UCLASS(ABSTRACT)
class FANTASTIC_PANCAKES_API AGGJ16_BaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGGJ16_BaseEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void EnemyInteract(AActor* Interactor) PURE_VIRTUAL(AGGJ16_BaseEnemy::Interact, );

	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree;
};
