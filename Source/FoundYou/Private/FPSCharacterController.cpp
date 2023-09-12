// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacterController.h"
#include "Blueprint/UserWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

void AFPSCharacterController::BeginPlay()
{
	Super::BeginPlay();

	m_worldRef = GetWorld();
	m_fpsCharacter = Cast<AFPSCharacter>(m_worldRef->GetFirstPlayerController()->GetCharacter());
	
	if(UUserWidget* aiStateHUD = CreateWidget(this, m_aiStateUI))
		aiStateHUD->AddToViewport();
}

void AFPSCharacterController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	if(UUserWidget* gameOver = CreateWidget(this, m_gameOverUI))
	{
		gameOver->AddToViewport();
		UGameplayStatics::SetGamePaused(m_worldRef, true);
		bShowMouseCursor =				true;
		bEnableClickEvents =			true;
		bEnableMouseOverEvents =	true;
	}
}

