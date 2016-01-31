// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "RandomWander.h"


EBTNodeResult::Type URandomWander::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	FVector NewWaypoint = FVector::ZeroVector;

	FVector CurrentPos = Blackboard->GetOwner()->GetActorLocation();

	NewWaypoint.X = CurrentPos.X + FMath::FRandRange(-5000, 5000);
	NewWaypoint.Y = CurrentPos.Y + FMath::FRandRange(-5000, 5000);

	while (FVector::Dist(NewWaypoint, Blackboard->GetOwner()->GetActorLocation()) <= 2000.f && TraceFromPosition(OutResult, 100.f, ECollisionChannel::ECC_EngineTraceChannel1, NewWaypoint, OwnerComp) == false)
	{
		NewWaypoint.X = CurrentPos.X + FMath::FRandRange(-5000, 5000);
		NewWaypoint.Y = CurrentPos.Y + FMath::FRandRange(-5000, 5000);
	}

	if (!NewWaypoint.IsZero())
	{
		Blackboard->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), NewWaypoint);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

bool URandomWander::TraceFromPosition(FHitResult& OutResult, const float TraceDistance, ECollisionChannel const CollisionChannel, FVector CastFrom, UBehaviorTreeComponent& OwnerComp)
{
	FVector RandomPointLocation = CastFrom;

	//GetPlayerViewPoint is used to give the origin and direction
	//of the trace from the player

	FVector const StartTrace = RandomPointLocation;
	FVector const TraceDirection = RandomPointLocation.UpVector * -1;
	FVector const EndTrace = StartTrace + TraceDirection*TraceDistance;

	//Struct that defines parameters into collision function
	FCollisionQueryParams TraceParams(FName(TEXT("TraceFromPosition")), true, OwnerComp.GetOwner());

	bool bHitReturned = false;
	UWorld* const World = GetWorld();

	if (World)
	{
		bHitReturned = World->LineTraceSingleByChannel(OutResult, StartTrace, EndTrace, CollisionChannel, TraceParams);
	}
	return bHitReturned;
}

