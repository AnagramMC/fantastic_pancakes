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

	InteractSense = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractSense"));
	InteractSense->AttachTo(RootComponent);

	MeleeCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("MeleeCollider"));
	MeleeCollider->AttachTo(RootComponent);

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

	float Movement = 0.f;

	if (CurrentInputRotation.X != 0 || CurrentInputRotation.Y != 0)
	{
		Movement = 1.f;
		CalculateTargetRotation();
	}

	AddMovementInput(GetActorForwardVector(), Movement);
	
	TArray<AActor*> OverlappingActors;
	InteractSense->GetOverlappingActors(OverlappingActors);

	for (AActor* CollidedActor : OverlappingActors)
	{
		ABaseInteract* curInteractObject = Cast<ABaseInteract>(CollidedActor);
		if (curInteractObject)
		{
			AVolcano* curVolcanoInteract = Cast<AVolcano>(curInteractObject);
			if (curVolcanoInteract)
			{
				bCanInteract = true;
			}
			else
			{
				bCanInteract = false;
			}
		}
		else
		{
			bCanInteract = false;
		}
	}
}

// Called to bind functionality to input
void AGGJ16_Player::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("Forward", this, &AGGJ16_Player::MoveForward);
	InputComponent->BindAxis("Right", this, &AGGJ16_Player::MoveRight);

	InputComponent->BindAction("Attack", IE_Pressed, this, &AGGJ16_Player::Attack);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AGGJ16_Player::Interact);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

}

void AGGJ16_Player::MoveForward(float Value)
{
	CurrentInputRotation.X = Value;
}

void AGGJ16_Player::MoveRight(float Value)
{
	CurrentInputRotation.Y = Value;
}

FRotator AGGJ16_Player::CalculateTargetRotation()
{
	float Yaw = FMath::RadiansToDegrees(FMath::Atan2(CurrentInputRotation.Y, CurrentInputRotation.X));
	SetActorRotation(FMath::Lerp(GetActorRotation(), FRotator(0.f, Yaw, 0.f), RotationAlpha));
	return GetActorRotation();

}

void AGGJ16_Player::Attack()
{
	TArray<AActor*> OverlappingActors;

	MeleeCollider->GetOverlappingActors(OverlappingActors);
	for (AActor* CollidedActor : OverlappingActors)
	{
		//Check if is enemy and do damage
	}
}

void AGGJ16_Player::Interact()
{
	
	//Run interact function on object in range.
}