// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GGJ16_AI_Vani.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_AI_Vani : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGGJ16_AI_Vani();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
