// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_MeleeEnemy.h"
#include "GGJ16_MeleeController.h"

AGGJ16_MeleeController::AGGJ16_MeleeController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AGGJ16_MeleeController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	AGGJ16_MeleeEnemy* Character = Cast<AGGJ16_MeleeEnemy>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}