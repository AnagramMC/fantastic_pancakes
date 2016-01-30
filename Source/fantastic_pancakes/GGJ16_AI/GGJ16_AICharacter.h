// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "GGJ16_AICharacter.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_AICharacter : public ACharacter
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	AGGJ16_AICharacter();

	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree;

protected:

	UPROPERTY(VisibleAnywhere)
		UPawnSensingComponent* PawnSensingComponent;

	UPROPERTY(EditAnywhere)
		FName GhostActorKeyName;

	UFUNCTION()
		void OnSeePlayer(APawn* Pawn);
};
