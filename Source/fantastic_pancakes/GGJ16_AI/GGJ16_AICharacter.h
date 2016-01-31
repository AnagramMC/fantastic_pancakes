// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "Enemy/RangedEnemy/GGJ16_FireballProjectile.h"
#include "GGJ16_AICharacter.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_AICharacter : public ACharacter
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	AGGJ16_AICharacter();

	//Set up a pointer to hold the behavior tree for the class
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree;

	UFUNCTION()
		void FireProjectile();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGGJ16_FireballProjectile> ProjectileClass;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		FRotator ProjectilePitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Rotation)
		FVector ProjectileOffset;

protected:
	
	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensingComponent;

	//Create two FNames (Basically text fields) that will allow us to set the keys that the values will be stored in on the blackboard
	UPROPERTY(EditAnywhere)
	FName GhostActorKeyName;

	UPROPERTY(EditAnywhere)
	FName PlayerKeyName;

	UPROPERTY(EditDefaultsOnly)
	USoundCue* RoarSound;

	//Set up the On See Player function (Same vien as On Actor Overlap)
	UFUNCTION()
	void OnSeePlayer(APawn* Pawn);

	UFUNCTION()
	virtual void OnOverlapBegin(class AActor* OtherActor);

private:

	bool FirstEncounter;
};
