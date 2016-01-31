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
		const FRotator SpawnRotation = GetControlRotation() + ProjectilePitch;
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + ProjectileOffset;

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			World->SpawnActor<AGGJ16_FireballProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}
}

float AGGJ16_RangedEnemy::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
	}

	if (Health <= 0)
	{
		DestroySelf();
	}
	
	return ActualDamage;	
}

void AGGJ16_RangedEnemy::DestroySelf()
{
	Destroy();
}