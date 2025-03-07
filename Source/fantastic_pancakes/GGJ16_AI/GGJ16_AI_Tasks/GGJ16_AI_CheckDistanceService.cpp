// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Player/GGJ16_Player.h"
#include "GGJ16_AI/GGJ16_AIController.h"
#include "GGJ16_AI_CheckDistanceService.h"

void UGGJ16_AI_CheckDistanceService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	UObject* TargetObject = Blackboard->GetValue<UBlackboardKeyType_Object>(TargetName);

	AGGJ16_Player* PlayerCharacter = Cast<AGGJ16_Player>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	AGGJ16_AIController* AIController = Cast<AGGJ16_AIController>(Blackboard->GetOwner());

	if (AIController && PlayerCharacter)
	{
		Distance = FVector::Dist(PlayerCharacter->GetActorLocation(), AIController->GetPawn()->GetActorLocation());

		Blackboard->SetValue<UBlackboardKeyType_Float>(BlackboardKey.GetSelectedKeyID(), Distance);
	}

	GEngine->AddOnScreenDebugMessage(4, 1, FColor::Blue, TEXT("Ding"));
}