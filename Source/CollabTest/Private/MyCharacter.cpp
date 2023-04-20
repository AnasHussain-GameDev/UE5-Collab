// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isDashing = false;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto CharMovement = GetCharacterMovement();
	isMoving = CharMovement->Velocity.Length() > 0.1f;
	isJumping = CharMovement->Velocity.Y > 0.1f;
	isFalling = CharMovement->Velocity.Y < 0.1f;

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (DashInputAction)
		Input->BindAction(DashInputAction, ETriggerEvent::Triggered, this, &AMyCharacter::DashCallbackFunc);
	else
		UKismetSystemLibrary::PrintString(this,"Player Dash Input not set in blueprint");
}

void AMyCharacter::PlayerMove(UPARAM(ref) float& XValue, UPARAM(ref) float& YValue)
{
	AddMovementInput(GetActorForwardVector(), YValue);
	AddMovementInput(GetActorRightVector(), XValue);
}

void AMyCharacter::DashCallbackFunc(const FInputActionInstance& Instance)
{
	isDashing = Instance.GetValue().Get<bool>();
	if (DashCount > 0)
	{
		DashCount--;
	}
}

