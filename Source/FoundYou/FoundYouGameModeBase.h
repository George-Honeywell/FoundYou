// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FPSCharacter.h"
#include "SeekerAIController.h"
#include "GameFramework/GameModeBase.h"
#include "FoundYouGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FOUNDYOU_API AFoundYouGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFoundYouGameModeBase();

protected:
	virtual void BeginPlay() override;
};
