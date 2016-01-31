// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "AudioHandler.h"


// Sets default values
AAudioHandler::AAudioHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAudioHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAudioHandler::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

