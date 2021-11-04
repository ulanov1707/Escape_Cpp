// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "Floating_Actor_Test_Timeline.generated.h"

//declared a class (forward Decloration).Basically another way of define a class instead of using a headerfile (More efficient)
//works only on special cases
class UCurveFloat;


UCLASS()
class ESCAPE_API AFloating_Actor_Test_Timeline : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloating_Actor_Test_Timeline();



	UFUNCTION()//Update function
	void TimelineProgress(float Value/*Alpha*/);

	UFUNCTION()//Finished function
		void OnTimelineFinised();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FTimeline Timeline;


	//Creating Delegate(connects timeline with function " TimelineProgress"). FOnTimelineFloat so it takes float as parameter
	FOnTimelineFloat TProgress;


	//Creating delegate (connects timeline with function "OnTimelineFinished")
	FOnTimelineEvent TFinished;

	UPROPERTY(EditAnywhere,Category="Timeline")
		UCurveFloat* CurveFloat;//Curve itself . you need to set Curve in the blueprints

	UPROPERTY()
		FVector StartLoc;

	UPROPERTY()
		FVector EndLoc;

	UPROPERTY(EditAnywhere,Category="Timeline")
		float ZOffset;



};
