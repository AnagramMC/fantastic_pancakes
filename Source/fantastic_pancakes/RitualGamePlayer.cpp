// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "RitualGamePlayer.h"


// Sets default values
ARitualGamePlayer::ARitualGamePlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARitualGamePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARitualGamePlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ARitualGamePlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

