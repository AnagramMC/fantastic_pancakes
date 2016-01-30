// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interact/BaseInteract.h"
#include "Volcano.generated.h"

/**
 * 
 */

UCLASS()
class FANTASTIC_PANCAKES_API AVolcano : public ABaseInteract
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVolcano();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	virtual void InteractEvent() override;
	
};
