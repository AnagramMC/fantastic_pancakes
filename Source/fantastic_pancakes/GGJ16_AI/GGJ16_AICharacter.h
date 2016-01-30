// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GGJ16_AICharacter.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_AICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGGJ16_AICharacter();

	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree;
};
