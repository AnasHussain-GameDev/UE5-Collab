// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	//Player States
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="PlayerStates")
		bool isMoving;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerStates")
		bool isDashing;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerStates")
		bool isJumping;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerStates")
		bool isAttacking;

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void PlayerMove(UPARAM(ref)float& XValue, UPARAM(ref)float& YValue);

};
