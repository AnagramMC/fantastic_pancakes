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

	AActor* Enemy = OwnerComp.GetOwner();

	if (Enemy)
	{
		AGGJ16_RangedEnemy* RangedEnemy = Cast<AGGJ16_RangedEnemy>(Enemy);

		if (RangedEnemy)
		{
			RangedEnemy->FireProjectile();
			return EBTNodeResult::Succeeded;
		}

		GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));

		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Failed;


}

