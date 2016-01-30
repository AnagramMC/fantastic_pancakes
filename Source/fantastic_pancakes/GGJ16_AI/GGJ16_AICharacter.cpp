// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_AIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "GGJ16_Vani/GGJ16_Vani.h"
#include "Player/GGJ16_Player.h"
#include "GGJ16_AICharacter.h"

// Sets default values
AGGJ16_AICharacter::AGGJ16_AICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AGGJ16_AIController::StaticClass();

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));

	OnActorBeginOverlap.AddDynamic(this, &AGGJ16_AICharacter::OnOverlapBegin);
}

void AGGJ16_AICharacter::BeginPlay()
{
	Super::BeginPlay();

	//Add dynamic the same way we would with actor overlap
	if (PawnSensingComponent)
	{
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AGGJ16_AICharacter::OnSeePlayer);
	}
}

void AGGJ16_AICharacter::OnSeePlayer(APawn* Pawn)
{
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Yellow, TEXT("Something seen"));

	float Distance = FVector::Dist(Pawn->GetActorLocation(), this->GetActorLocation());

	if (Distance < 900)
	{
		AGGJ16_AIController* Controller = Cast<AGGJ16_AIController>(GetController());

		if (Controller)
		{
			//Here we check which of the things we saw. This lets us decide what the monster should do and who he should chase. The Ghost has a higher priority so he will always go for the ghost first.
			AGGJ16_Vani* Vani = Cast<AGGJ16_Vani>(Pawn);
			AGGJ16_Player* Player = Cast<AGGJ16_Player>(Pawn);

			if (Vani)
			{
				Controller->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(GhostActorKeyName, Pawn);
				GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Yellow, TEXT("Ghost set"));
			}
			else if (Player)
			{
				Controller->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(PlayerKeyName, Pawn);
				GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Yellow, TEXT("Player set"));
			}
		}
	}
}

void AGGJ16_AICharacter::OnOverlapBegin(class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))
	{
		UGameplayStatics::ApplyDamage(OtherActor, 10.f, GetController(), this, UDamageType::StaticClass());

		GEngine->AddOnScreenDebugMessage(3, 1.f, FColor::Red, TEXT("Something damaged"));
	}
}

