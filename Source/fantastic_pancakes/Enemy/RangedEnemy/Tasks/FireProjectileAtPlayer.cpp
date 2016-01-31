// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "Enemy/RangedEnemy/GGJ16_RangedEnemy.h"
#include "FireProjectileAtPlayer.h"


EBTNodeResult::Type UFireProjectileAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
		
	}

	for (TActorIterator<AGGJ16_RangedEnemy> Enemy(GetWorld()); Enemy; ++Enemy)
	{
		AGGJ16_RangedEnemy* RangedEnemy = *Enemy;

		if (RangedEnemy)
		{
			RangedEnemy->FireProjectile();
			GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));
			return EBTNodeResult::Succeeded;
		}

		GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));

		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Failed;


}

