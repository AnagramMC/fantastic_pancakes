// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "BaseInteract.h"


// Sets default values
ABaseInteract::ABaseInteract()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractArea = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractArea"));
	InteractMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InteractMesh"));

}

// Called when the game starts or when spawned
void ABaseInteract::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseInteract::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ABaseInteract::InteractEvent()
{

}
