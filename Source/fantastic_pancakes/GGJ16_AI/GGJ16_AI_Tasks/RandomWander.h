// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "RandomWander.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API URandomWander : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	bool TraceFromPosition(FHitResult& OutResult, const float TraceDistance, ECollisionChannel const CollisionChannel, FVector CastFrom, UBehaviorTreeComponent& OwnerComp);

private:

	FVector NewWaypoint;

	FHitResult OutResult;
	
};
