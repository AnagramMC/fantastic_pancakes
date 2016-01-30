// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GGJ16_AIController.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AGGJ16_AIController();
	virtual void Possess(APawn* Pawn) override;

	UBlackboardComponent* GetBlackboardComponent() { return BlackboardComponent; }

protected:
	UPROPERTY(VisibleAnywhere)
		UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere)
		UBlackboardComponent* BlackboardComponent;
};
