// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	m_cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_cameraComponent->SetupAttachment(GetCapsuleComponent());
	m_cameraComponent->SetRelativeLocation(FVector(-10.0, 0.0, 60.0));
	m_cameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Yellow, TEXT("FPSCharacter in use!"), true);
	UE_LOG(LogTemp, Display, TEXT("FPSCharacter in use."));

	if (APlayerController* playerController = Cast<APlayerController>(Controller))
		if (UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
			subsystem->AddMappingContext(m_mappingContext, 0);


	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* enhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInputComponent->BindAction(m_moveAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Move);
		enhancedInputComponent->BindAction(m_lookAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);
	}

}

void AFPSCharacter::Move(const FInputActionValue& value)
{
	FVector2D movement = value.Get<FVector2D>();

	if (Controller)
	{
		AddMovementInput(GetActorForwardVector(), movement.Y);
		AddMovementInput(GetActorRightVector(), movement.X);
	}
}

void AFPSCharacter::Look(const FInputActionValue& value)
{
	FVector2D movement = value.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(movement.X);
		AddControllerPitchInput(movement.Y);
	}
}

