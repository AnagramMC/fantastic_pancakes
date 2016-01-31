// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Player/GGJ16_Player.h"
#include "Blueprint/UserWidget.h"
#include "UIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AUIPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> wPauseMenu;

protected:
	UUserWidget* MyPauseMenu;

	virtual void Tick(float DeltaSeconds) override;

	void PauseMenu();
};
