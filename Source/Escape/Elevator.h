// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Components/TimelineComponent.h"
#include"Components/BoxComponent.h"
#include"Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include"MainCharacter.h"
#include "Elevator.generated.h"

UCLASS()
class ESCAPE_API AElevator : public AActor
{
	GENERATED_BODY()


	
public:	
	// Sets default values for this actor's properties
	AElevator();

	AMainCharacter* Main;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimeline Timeline;
	FTimeline Timeline2;








	UPROPERTY(EditAnywhere, Category = "Timeline")
		UCurveFloat* CurveFloat;//Curve itself . you need to set Curve in the blueprints

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category="Door")
	class UStaticMeshComponent* Door;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Door")
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Door")
	class UStaticMeshComponent* Elevator;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USceneComponent* Root;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OpenDoor(float value);
	UFUNCTION()
	void CloseDoor(float value);
};
