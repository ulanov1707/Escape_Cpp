// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Axe_Trap.generated.h"

UCLASS()
class ESCAPE_API AAxe_Trap : public AActor
{
	GENERATED_BODY()
	 
public:	
	// Sets default values for this actor's properties
	AAxe_Trap();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Axe")
		class UStaticMeshComponent* Axe_Top;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Axe")
		class UStaticMeshComponent* Axe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Axe")
		bool bRotateYAxis;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Axe")
		FRotator InitialYRotation;
	UPROPERTY(EditAnywhere, Category = "Axe")
		float RotationRate;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
		class AMainCharacter* Main;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SwapRotationRate(float&);

};
