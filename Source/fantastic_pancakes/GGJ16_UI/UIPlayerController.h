// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> wWinMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> wLoseMenu;

protected:
	UUserWidget* MyPauseMenu;
	UUserWidget* MyWinMenu;
	UUserWidget* MyLoseMenu;

	virtual void Tick(float DeltaSeconds) override;

	void PauseMenu();
	void WinMenu();
	void LoseMenu();
};
