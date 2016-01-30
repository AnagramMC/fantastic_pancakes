// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_RangedEnemy.h"
#include "GGJ16_RangedController.h"

AGGJ16_RangedController::AGGJ16_RangedController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AGGJ16_RangedController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	AGGJ16_RangedEnemy* Character = Cast<AGGJ16_RangedEnemy>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}


