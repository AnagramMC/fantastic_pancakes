// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_AICharacter.h"
#include "GGJ16_AIController.h"

AGGJ16_AIController::AGGJ16_AIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AGGJ16_AIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	AGGJ16_AICharacter* Character = Cast<AGGJ16_AICharacter>(Pawn);
	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}