// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ESCAPE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();


	//****************************************************************************
	/* DONT ROTATE THE PLATFORM IT WILL WORK NOT CORRECTLY YOU CAN CHANGE ENDPOINT
	WHEREVER YOU WANT BUT DONT ROTATE PLATFORM  ITSELF   
	**********************************************************************************/



	//mesh for the platform
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform")
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		FVector StartPoint;
	UPROPERTY(EditAnywhere)
		FVector EndPoint;




	


	//MakeEditWidget="true" allow us to set EndPoint  value in the editor VISUALLY(Lecture 47)
	//in the editor when you place a Blueprint in the world derived from this class 
	//since it has MakeEditWidget="true" you will able to see little dimond in the center of a placed blueprint(Mesh) 
	//this is you EndPont and you can set it anywhere you want from Editor Visually  
	//NOTE:Location of an EndPoint will be shown with respect to placed Blueprint(not world coordinates)

	//UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	//FVector EndPoint;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
		float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
		float InterpTime;


	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
		bool bStartToFloat;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform")
		class UBoxComponent* TriggerBox;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Platform")
		class UBoxComponent* EndBox;


	//values of rotatition will be set in the editer
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
		FRotator MeshRotation = FRotator(0.f);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInterping();

	void SwapVector(FVector&, FVector&);

	UStaticMeshComponent* GetMesh() {
		return Mesh;
	}

	void SetMesh(UStaticMeshComponent* MyMesh) {
		Mesh = MyMesh;
	}

	
};
