// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_AIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GGJ16_AI/GGJ16_Vani/GGJ16_AI_Vani.h"
#include "GGJ16_AICharacter.h"

// Sets default values
AGGJ16_AICharacter::AGGJ16_AICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AGGJ16_AIController::StaticClass();

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
}

void AGGJ16_AICharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComponent)
	{
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AGGJ16_AICharacter::OnSeePlayer);
	}
}

void AGGJ16_AICharacter::OnSeePlayer(APawn* Pawn)
{
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Yellow, TEXT("Ghost seen"));

	float Distance = FVector::Dist(Pawn->GetActorLocation(), this->GetActorLocation());

	if (Distance < 900)
	{
		AGGJ16_AIController* Controller = Cast<AGGJ16_AIController>(GetController());

		if (Controller)
		{
			AGGJ16_AI_Vani* Vani = Cast<AGGJ16_AI_Vani>(Pawn);

			if (Vani)
			{
				Controller->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(GhostActorKeyName, Vani);
				GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Yellow, TEXT("Ghost set"));
			}

			/*Controller->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(GhostActorKeyName, Pawn);
			GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Yellow, TEXT("Ghost set"));*/
		}
	}
}

