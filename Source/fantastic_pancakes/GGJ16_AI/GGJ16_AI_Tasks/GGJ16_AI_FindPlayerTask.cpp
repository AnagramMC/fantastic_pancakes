// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
//#include "???/???.h"
#include "GGJ16_AI_FindPlayerTask.h"

EBTNodeResult::Type UGGJ16_AI_FindPlayerTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	/*for (TActorIterator<???> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		???* PlayerCharacter = *ActorItr;
		if (PlayerCharacter)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), PlayerCharacter);

			return EBTNodeResult::Succeeded;
		}
	}*/

	return EBTNodeResult::Failed;
}