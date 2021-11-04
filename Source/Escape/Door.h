// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ESCAPE_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	//Door Meshes
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Door")
	UStaticMeshComponent* Door;

	//Overlapping box to open and close the door
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Door")
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Door")
	FVector InitialDoorLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	float FinalDoor_Z_Component = 400.f;//we can change this value in the  editor

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	FVector FinalDoorLocation;

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void RaiseDoor();//functionality will be implenented in Blueprint and will became Event
	UFUNCTION(BlueprintImplementableEvent, Category = "Door")
	void LowerDoor();//functionality will be implenented in Blueprint and will became Event
	
	

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
