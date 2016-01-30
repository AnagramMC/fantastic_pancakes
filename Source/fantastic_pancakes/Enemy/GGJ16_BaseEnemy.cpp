// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_BaseEnemy.h"


// Sets default values
AGGJ16_BaseEnemy::AGGJ16_BaseEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGGJ16_BaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGJ16_BaseEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
