// Fill out your copyright notice in the Description page of Project Settings.

#include "fantastic_pancakes.h"
#include "GGJ16_AIController.h"
#include "GGJ16_AICharacter.h"


// Sets default values
AGGJ16_AICharacter::AGGJ16_AICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AGGJ16_AIController::StaticClass();
}

