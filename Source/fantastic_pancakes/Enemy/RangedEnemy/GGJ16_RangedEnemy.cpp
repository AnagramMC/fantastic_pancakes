// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_RangedEnemy.h"


void AGGJ16_RangedEnemy::EnemyInteract(AActor* Interactor)
{
	//
}

void AGGJ16_RangedEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SpawnRotation = GetControlRotation() + ProjectilePitch;
	// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
	SpawnLocation = GetActorLocation() + ProjectileOffset;
}

void AGGJ16_RangedEnemy::FireProjectile()
{
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			World->SpawnActor<AGGJ16_FireballProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}
}