// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlatform.h"
#include "MovingPlatform_Rotatable.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API AMovingPlatform_Rotatable : public AMovingPlatform
{
	GENERATED_BODY()

public:
	AMovingPlatform_Rotatable();

		UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Moving")
			float PitchVal;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
			float YawVal;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
			float RollVal;

		

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	
	
};
