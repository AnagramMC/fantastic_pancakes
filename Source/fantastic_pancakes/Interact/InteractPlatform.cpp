// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "InteractPlatform.h"


AInteractPlatform::AInteractPlatform()
{

}

void AInteractPlatform::BeginPlay()
{
	Super::BeginPlay();

	bTimerExpired = true;

}

// Called every frame
void AInteractPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractPlatform::InteractEvent()
{
	UWorld* const World = GetWorld();
	if (World != NULL)
	{
		bPlatformActive = true;

		if ((TimerHandle.IsValid() == false) || (bTimerExpired))
		{
			World->GetTimerManager().SetTimer(TimerHandle, this, &AInteractPlatform::TimerExpired, 4.5f);
			bTimerExpired = false;
		}
	}
}

void AInteractPlatform::TimerExpired()
{
	bPlatformActive = false;
	bTimerExpired = true;
}