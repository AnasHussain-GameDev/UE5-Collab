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

	isMoving = GetCharacterMovement()->Velocity.Length() > 0.1f;
	isJumping = GetCharacterMovement()->Velocity.Y > 0.1f;

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::PlayerMove(UPARAM(ref) float& XValue, UPARAM(ref) float& YValue)
{
	AddMovementInput(GetActorForwardVector(), YValue);
	AddMovementInput(GetActorRightVector(), XValue);
}

