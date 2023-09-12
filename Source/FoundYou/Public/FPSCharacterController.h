// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSCharacter.h"
#include "GameFramework/PlayerController.h"
#include "FPSCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class FOUNDYOU_API AFPSCharacterController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	AFPSCharacter* m_fpsCharacter = nullptr;

	UWorld* m_worldRef = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player HUD/UI")
		TSubclassOf<class UUserWidget> m_aiStateUI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player HUD/UI")
		TSubclassOf<class UUserWidget> m_gameOverUI;

public:
	UFUNCTION()
		virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;
};
