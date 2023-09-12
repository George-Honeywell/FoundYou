// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Observer.h"
#include "Engine/Engine.h"
#include "TimerManager.h"
#include "SeekerAIController.generated.h"

UCLASS()
class FOUNDYOU_API ASeekerAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float deltaTime) override;

	ASeekerAIController();
	
	APawn* m_fpsCharacter = nullptr;
	AObserver* m_observer = nullptr;

	APawn* observer = nullptr;
	
	UFUNCTION()
		void OnSeePawn(APawn* otherPawn);

	UPROPERTY(EditAnywhere)
		USoundBase* m_alertSound = nullptr;

	UPROPERTY(BlueprintReadOnly)
		bool m_bCanSeekerSee = false;

	UPROPERTY(BlueprintReadOnly)
		FVector m_distanceSaw = FVector(0,0,0);

	UPROPERTY(BlueprintReadOnly)
		float m_XPos = 0.0f;
	
private:
	void CountdownTimer();
	FTimerHandle m_timerHandle;

	bool m_lineOfSight;

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* inPawn) override;
};
