// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_FireballProjectile.h"


// Sets default values
AGGJ16_FireballProjectile::AGGJ16_FireballProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("CapsuleComp"));
	Collider->BodyInstance.SetCollisionProfileName("Projectile");
	Collider->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	Collider->CanCharacterStepUpOn = ECB_No;

	RootComponent = Collider;

	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	Projectile->UpdatedComponent = Collider;
	Projectile->InitialSpeed = 1200.f;
	Projectile->MaxSpeed = 1200.f;
	Projectile->bRotationFollowsVelocity = true;
	Projectile->bShouldBounce = false;

	OnActorBeginOverlap.AddDynamic(this, &AGGJ16_FireballProjectile::OnActorOverlap);

	InitialLifeSpan = 5.0f;

}

void AGGJ16_FireballProjectile::OnActorOverlap(AActor* OtherActor)
{
	if (OtherActor != GetOwner())
	{
		//this->Destroy();
		UGameplayStatics::ApplyDamage(OtherActor, 10.f, this->GetInstigatorController(), this, UDamageType::StaticClass());
	}
}