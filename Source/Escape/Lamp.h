// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lamp.generated.h"

UCLASS()
class ESCAPE_API ALamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALamp();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lamp")
	class UStaticMeshComponent* Lamp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Lamp")
	class UMaterialInstance * Lamp_Material;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lamp")
	class USphereComponent* Trigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lamp")
	class UPointLightComponent* Light;


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
