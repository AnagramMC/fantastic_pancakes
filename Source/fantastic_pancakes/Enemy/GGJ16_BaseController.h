// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "GGJ16_BaseController.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_BaseController : public AAIController
{
	GENERATED_BODY()

	UBlackboardComponent* GetBlackboardComponent() { return BlackboardComponent; }

protected:

	UPROPERTY(VisibleAnywhere)
	UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere)
	UBlackboardComponent* BlackboardComponent;
	
	
};
