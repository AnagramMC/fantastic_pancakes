// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GGJ16_ShockWaveTask.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API UGGJ16_ShockWaveTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
