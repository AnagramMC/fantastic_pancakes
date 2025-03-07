	// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Player/GGJ16_Player.h"
#include "Enemy/GGJ16_BaseController.h"
#include "GGJ16_RangedDistService.h"

void UGGJ16_RangedDistService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	//UObject* TargetObject = Blackboard->GetValue<UBlackboardKeyType_Object>(TargetName);

	AActor* BaseActor = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	AGGJ16_BaseController* AIController = Cast<AGGJ16_BaseController>(Blackboard->GetOwner());

	if (AIController)
	{
		if (BaseActor)
		{
			Distance = FVector::Dist(BaseActor->GetActorLocation(), AIController->GetPawn()->GetActorLocation());

			Blackboard->SetValue<UBlackboardKeyType_Float>(BlackboardKey.GetSelectedKeyID(), Distance);
		}
	}

	GEngine->AddOnScreenDebugMessage(4, 1, FColor::Blue, TEXT("Ding"));
}


