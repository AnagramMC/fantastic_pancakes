// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_AI/GGJ16_AICharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GGJ16_ShockWaveTask.h"

EBTNodeResult::Type UGGJ16_ShockWaveTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!GetWorld())
	{
		return EBTNodeResult::Failed;

	}

	for (TActorIterator<AGGJ16_AICharacter> Enemy(GetWorld()); Enemy; ++Enemy)
	{
		AGGJ16_AICharacter* BossEnemy = *Enemy;

		if (BossEnemy)
		{

			AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

			AController* AiController = Cast<AController>(OwnerComp.GetOwner());

			FRotator NewRot = UKismetMathLibrary::FindLookAtRotation(AiController->GetPawn()->GetActorLocation(), Player->GetActorLocation());

			NewRot.Roll = 0.f;
			NewRot.Pitch = 0.f;

			//NewRot.Yaw += -90;

			AiController->GetPawn()->SetActorRotation(NewRot);


			BossEnemy->FireProjectile();

			GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, OwnerComp.GetOwner()->GetName());

			BossEnemy->FireProjectile();
			GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));
			return EBTNodeResult::Succeeded;
		}

		GEngine->AddOnScreenDebugMessage(3, 1, FColor::Black, TEXT("FUCK"));

		return EBTNodeResult::Failed;
	}


	return EBTNodeResult::Failed;


}