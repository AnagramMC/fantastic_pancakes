// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "UIPlayerController.h"

void AUIPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (APlayerController::WasInputKeyJustPressed(EKeys::P))
	{
		AUIPlayerController::PauseMenu();
		SetPause(true);
	}
}

void AUIPlayerController::PauseMenu()
{
	if (wPauseMenu)
	{
		MyPauseMenu = CreateWidget<UUserWidget>(this, wPauseMenu);

		if (MyPauseMenu)
		{
			MyPauseMenu->AddToViewport(0);
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyPauseMenu->GetCachedWidget());
			SetInputMode(Mode);
		}

		bShowMouseCursor = true;
	}
}