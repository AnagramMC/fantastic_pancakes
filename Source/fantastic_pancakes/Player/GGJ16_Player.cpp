// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_Player.h"


// Sets default values
AGGJ16_Player::AGGJ16_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(CameraBoom);

}

// Called when the game starts or when spawned
void AGGJ16_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGJ16_Player::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGGJ16_Player::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("Forward", this, &AGGJ16_Player::MoveForward);
	InputComponent->BindAxis("Right", this, &AGGJ16_Player::MoveRight);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

}

void AGGJ16_Player::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGGJ16_Player::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}

}