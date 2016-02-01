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

	AController* Controller = Cast<AController>(OwnerComp.GetOwner());

	AGGJ16_RangedEnemy* Enemy = Cast<AGGJ16_RangedEnemy>(Controller->GetPawn());

	GEngine->AddOnScreenDebugMessage(3, 2.f, FColor::Black, TEXT("Boop"));

	if (Enemy)
	{
		Enemy->FireProjectile();
		GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

