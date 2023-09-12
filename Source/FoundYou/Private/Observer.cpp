// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AObserver::AObserver()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_pawnSensor = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensor"));
}

// Called when the game starts or when spawned
void AObserver::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AObserver::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

