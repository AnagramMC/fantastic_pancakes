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
			//World->SpawnActor<AGGJ16_Vani>(Vani, SpawnLocation, FRotator::ZeroRotator);
		}

}