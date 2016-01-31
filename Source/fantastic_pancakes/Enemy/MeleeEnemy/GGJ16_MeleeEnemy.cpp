// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_MeleeController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Player/GGJ16_Player.h"
#include "GGJ16_MeleeEnemy.h"

AGGJ16_MeleeEnemy::AGGJ16_MeleeEnemy()
{
	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("SensingComponent"));

	MeleeCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("MeleeCollider"));
	MeleeCollider->AttachTo(RootComponent);
}

void AGGJ16_MeleeEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (SensingComponent)
	{
		SensingComponent->OnSeePawn.AddDynamic(this, &AGGJ16_MeleeEnemy::OnSeePlayer);
	}

}

void AGGJ16_MeleeEnemy::EnemyInteract(AActor* Interactor)
{
	//
}

void AGGJ16_MeleeEnemy::OnSeePlayer(APawn* Pawn)
{
	float Distance = FVector::Dist(Pawn->GetActorLocation(), this->GetActorLocation());

	AGGJ16_Player* Player = Cast<AGGJ16_Player>(Pawn);

	if (Distance < 1000)
	{
		AGGJ16_MeleeController* Controller = Cast<AGGJ16_MeleeController>(GetController());

		if (Controller)
		{
			if (Player)
			{
				Controller->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(PlayerKeyName, Pawn);
				GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Yellow, TEXT("Player set"));
			}
		}
	}
}

