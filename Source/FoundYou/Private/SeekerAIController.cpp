// Fill out your copyright notice in the Description page of Project Settings.

#include "SeekerAIController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

ASeekerAIController::ASeekerAIController()
{

}

void ASeekerAIController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	if(m_bCanSeekerSee)
		OnSeePawn(m_fpsCharacter);
	else
		ClearFocus(EAIFocusPriority::Gameplay);
}

void ASeekerAIController::BeginPlay()
{
	Super::BeginPlay();
	
	m_fpsCharacter = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	OnPossess(m_observer);
	
	GetWorldTimerManager().SetTimer(m_timerHandle, this, &ASeekerAIController::CountdownTimer, 10.0f, true, 10.0f);
}

void ASeekerAIController::OnPossess(APawn* inPawn)
{
	Super::OnPossess(inPawn);
	m_observer = Cast<AObserver>(GetPawn());
}

void ASeekerAIController::OnSeePawn(APawn* otherPawn)
{
	m_lineOfSight = LineOfSightTo(m_fpsCharacter);

	if (m_lineOfSight)
	{
		SetFocus(m_fpsCharacter);

		if(m_observer)
			m_distanceSaw = m_observer->GetActorLocation() - m_fpsCharacter->GetActorLocation();
		else
			UE_LOGFMT(LogTemp, Fatal, "{0} returned null.", *m_observer->GetName());

		// Divide the result by 100 to convert into meters
		m_XPos = m_distanceSaw.X / 100;
		
		if(m_fpsCharacter->GetController())
			m_fpsCharacter->GetController()->GameHasEnded(m_fpsCharacter, false);
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}
}

void ASeekerAIController::CountdownTimer()
{
	UGameplayStatics::PlaySound2D(this, m_alertSound);

	if(!m_bCanSeekerSee)
		m_bCanSeekerSee = true;
	else
		m_bCanSeekerSee = false;
}