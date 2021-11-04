// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rotatable_Trap.generated.h"

UCLASS()
class ESCAPE_API ARotatable_Trap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatable_Trap();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Moving")
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
		float PitchSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
		float YawSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moving")
		float RollSpeed;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
