// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "RotateTrap.generated.h"

UCLASS()
class ESCAPE_API ARotateTrap : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARotateTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateTrap")
		USceneComponent* OurVisibleActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateTrap")
		UCameraComponent* OurCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotateTrap")
		float RotationSpeed;
	void Rotate_XAxis(float AxisValue);
	void Rotate_YAxis(float AxisValue);

	FRotator CurrentVelocity;

};
