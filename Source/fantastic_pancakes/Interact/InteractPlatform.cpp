// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "InteractPlatform.h"


AInteractPlatform::AInteractPlatform()
{

}

void AInteractPlatform::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AInteractPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractPlatform::InteractEvent()
{
	bPlatformActive = true;
}