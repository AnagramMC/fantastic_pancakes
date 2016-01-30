// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Player/GGJ16_Player.h"
#include "GGJ16_AI_FindPlayerTask.h"

EBTNodeResult::Type UGGJ16_AI_FindPlayerTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	for (TActorIterator<AGGJ16_Player> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AGGJ16_Player* PlayerCharacter = *ActorItr;
		if (PlayerCharacter)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), PlayerCharacter);

			//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Red, TEXT("Found You F***er!"));

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}