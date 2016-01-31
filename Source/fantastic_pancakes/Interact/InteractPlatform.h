// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interact/BaseInteract.h"
#include "InteractPlatform.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AInteractPlatform : public ABaseInteract
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractPlatform();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "InteractEvent")
	virtual void InteractEvent() override;

	void TimerExpired();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bPlatformActive = false;

private:

	FTimerHandle TimerHandle;
	
	bool bTimerExpired;
	
};
