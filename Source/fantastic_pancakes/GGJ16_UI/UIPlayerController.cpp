// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "Player/GGJ16_Player.h"
#include "GGJ16_AI/GGJ16_AICharacter.h"
#include "UIPlayerController.h"

void AUIPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (APlayerController::WasInputKeyJustPressed(EKeys::K))
	{
		AUIPlayerController::LoseScreen();
		SetPause(true);
	}

	if (APlayerController::WasInputKeyJustPressed(EKeys::W))
	{
		AUIPlayerController::WinScreen();
		SetPause(true);
	}

	if (APlayerController::WasInputKeyJustPressed(EKeys::P))
	{
		AUIPlayerController::PauseMenu();
		SetPause(true);
	}

	for (TActorIterator<AGGJ16_Player> PlayerItr(GetWorld()); PlayerItr; ++PlayerItr)
	{
		AGGJ16_Player* PlayerCharacter = *PlayerItr;
		
		if (PlayerCharacter)
		{
			if (PlayerCharacter->isDead)
			{
				AUIPlayerController::LoseMenu();
			}
		}
	}

	for (TActorIterator<AGGJ16_AICharacter> EnemyItr(GetWorld()); EnemyItr; ++EnemyItr)
	{
		AGGJ16_AICharacter* EnemyCharacter = *EnemyItr;

		if (EnemyCharacter)
		{
			if (EnemyCharacter->InteractCounter > 4)
			{
				AUIPlayerController::WinMenu();
			}
		}
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

void AUIPlayerController::WinMenu()
{
	if (wWinMenu)
	{
		MyWinMenu = CreateWidget<UUserWidget>(this, wWinMenu);

		if (MyWinMenu)
		{
			MyWinMenu->AddToViewport(0);
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyWinMenu->GetCachedWidget());
			SetInputMode(Mode);
		}

		bShowMouseCursor = true;
	}
}

void AUIPlayerController::LoseMenu()
{
	if (wLoseMenu)
	{
		MyLoseMenu = CreateWidget<UUserWidget>(this, wLoseMenu);

		if (MyLoseMenu)
		{
			MyLoseMenu->AddToViewport(0);
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyLoseMenu->GetCachedWidget());
			SetInputMode(Mode);
		}

		bShowMouseCursor = true;
	}
}