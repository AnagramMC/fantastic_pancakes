// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BaseInteract.generated.h"

UCLASS()
class FANTASTIC_PANCAKES_API ABaseInteract : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseInteract();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void InteractEvent();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* InteractArea;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* InteractMesh;
	
};
