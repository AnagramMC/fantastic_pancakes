// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "Volcano.h"

AVolcano::AVolcano()
{
	SpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnLocation"));
	SpawnLocation->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AVolcano::BeginPlay()
{
	Super::BeginPlay();

	SpawnPoint.X = this->GetActorLocation().X;
	SpawnPoint.Y = this->GetActorLocation().Y;
	SpawnPoint.Z = this->GetActorLocation().Z + 130.f;

	
	bTimerExpired = true;

}

// Called every frame
void AVolcano::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AVolcano::InteractEvent()
{
		UWorld* const World = GetWorld();

	
			if (World != NULL)
			{
				VaniReference = World->SpawnActor<AGGJ16_Vani>(VaniClass, SpawnPoint, FRotator::ZeroRotator);

				

				if ((TimerHandle.IsValid() == false) || (bTimerExpired))
				{
					World->GetTimerManager().SetTimer(TimerHandle, this, &AVolcano::TimerExpired, 5.0f);
					bTimerExpired = false;
				}
			}
		
			
	
}

void AVolcano::TimerExpired()
{
	GetWorld()->DestroyActor(VaniReference);
	GetWorld()->ForceGarbageCollection(true);
	bTimerExpired = true;
	
}