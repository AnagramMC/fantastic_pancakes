// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Interact/BaseInteract.h"
#include "Interact/Volcano.h"
#include "Interact/InteractPlatform.h"
#include "PlayerAnimInstance.h"
#include "Enemy/GGJ16_BaseEnemy.h"
#include "GGJ16_AI/GGJ16_Vani/GGJ16_Vani.h"
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

	UFUNCTION(BlueprintCallable, Category = "JumpHack")
	void AddJump();

	UFUNCTION(BlueprintCallable, Category = "CollsionCheck")
		void CheckCollision();

	UFUNCTION(BlueprintCallable, Category = "KnockbackAmount")
		void KnockbackPlayer(float KnockBackAmount);


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCanInteract = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bJumpStart = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPlayerAnimInstance* AnimInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float KnockBackAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float BaseDamage = 10.f;

	float VaniCount = 0;

	bool isDead = false;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

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

	bool didDamage = true;

protected:


	void MoveForward(float Value);
	void MoveRight(float Value);
	void Attack();
	void Interact();
	void Jump();

	FRotator CalculateTargetRotation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationAlpha;

	
	
};
