// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spike_Trap.generated.h"

UCLASS()
class ESCAPE_API ASpike_Trap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpike_Trap();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Spike")
		class UStaticMeshComponent* Platform;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spike")
		class UStaticMeshComponent *Spike;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spike")
		class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spike")
		FVector InitialSikeLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character)
		class AMainCharacter* Main;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintImplementableEvent, Category = "Spike")
		void RaiseSpike();//functionality will be implenented in Blueprint and will became Event
	UFUNCTION(BlueprintImplementableEvent, Category = "Spike")
		void LowerSpike();//functionality will be implenented in Blueprint and will became Event

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
