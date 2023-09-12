// Copyright Epic Games, Inc. All Rights Reserved.


#include "FoundYouGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

AFoundYouGameModeBase::AFoundYouGameModeBase() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_FPSCHaracter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void AFoundYouGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}