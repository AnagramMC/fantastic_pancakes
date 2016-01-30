// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Enemy/GGJ16_BaseController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GGJ16_RangedController.generated.h"

/**
 * 
 */
UCLASS()
class FANTASTIC_PANCAKES_API AGGJ16_RangedController : public AGGJ16_BaseController
{
	GENERATED_BODY()

		AGGJ16_RangedController();	
	
	virtual void Possess(APawn* Pawn) override;
};
