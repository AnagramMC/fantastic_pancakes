// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Interact/BaseInteract.h"
#include "Interact/Volcano.h"
#include "GGJ16_Player.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGGJ16_Player();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


public:
	bool bIsAttacking = false;

protected:

	UPROPERTY(EditDefaultsOnly)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* InteractSense;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* MeleeCollider;

	FVector CurrentInputRotation;

protected:


	void MoveForward(float Value);
	void MoveRight(float Value);
	void Attack();
	void Interact();

	FRotator CalculateTargetRotation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationAlpha;

	
	
	
};
