// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GGJ16_AI/GGJ16_Vani/GGJ16_AI_Vani.h"
#include "GGJ16_AI_FindGhostTask.h"

EBTNodeResult::Type UGGJ16_AI_FindGhostTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	for (TActorIterator<AGGJ16_AI_Vani> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AGGJ16_AI_Vani* Ghost = *ActorItr;
		if (Ghost)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), Ghost);

			GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Red, TEXT("Found You F***er!... Wait, just a ghost..."));

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}