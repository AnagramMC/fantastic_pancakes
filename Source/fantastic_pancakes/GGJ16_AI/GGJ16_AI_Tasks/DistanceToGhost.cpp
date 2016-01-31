// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GGJ16_AI/GGJ16_Vani/GGJ16_Vani.h"
#include "GGJ16_AI/GGJ16_AIController.h"
#include "DistanceToGhost.h"


void UDistanceToGhost::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	UObject* TargetObject = Blackboard->GetValue<UBlackboardKeyType_Object>(TargetName);

	AGGJ16_AIController* AIController = Cast<AGGJ16_AIController>(Blackboard->GetOwner());

	AGGJ16_Vani* VaniCharacter = Cast<AGGJ16_Vani>(TargetObject);

	if (AIController && VaniCharacter)
	{
		Distance = FVector::Dist(VaniCharacter->GetActorLocation(), AIController->GetPawn()->GetActorLocation());

		Blackboard->SetValue<UBlackboardKeyType_Float>(BlackboardKey.GetSelectedKeyID(), Distance);
	}

	GEngine->AddOnScreenDebugMessage(4, 1, FColor::Blue, TEXT("Ding"));
}