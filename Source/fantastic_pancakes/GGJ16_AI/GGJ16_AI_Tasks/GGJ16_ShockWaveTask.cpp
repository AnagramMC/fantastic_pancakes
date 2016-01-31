// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_AI/GGJ16_AICharacter.h"
#include "GGJ16_ShockWaveTask.h"

EBTNodeResult::Type UGGJ16_ShockWaveTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;

	}

	for (TActorIterator<AGGJ16_AICharacter> Enemy(GetWorld()); Enemy; ++Enemy)
	{
		AGGJ16_AICharacter* BossEnemy = *Enemy;

		if (BossEnemy)
		{
			BossEnemy->FireProjectile();
			GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));
			return EBTNodeResult::Succeeded;
		}

		GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));

		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Failed;


}