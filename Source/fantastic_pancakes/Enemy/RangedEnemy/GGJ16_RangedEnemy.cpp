// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_RangedEnemy.h"


void AGGJ16_RangedEnemy::EnemyInteract(AActor* Interactor)
{
	//
}

void AGGJ16_RangedEnemy::FireProjectile()
{
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation() + FRotator(45,0,0);
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + FVector(50, 0, 0);

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			World->SpawnActor<AGGJ16_FireballProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}
}