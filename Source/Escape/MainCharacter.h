// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"




UCLASS()
class ESCAPE_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();




	//speed when you normally run(not sprint)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
		float RunningSpeed;





	//NOTE:Character class has SkeletalMeshComponent called Mesh already , so u can use it(dont need to creaate)

	//AllowPrivateAcces-allows in Blueprints use and see private variable in current class only 
	//CameraBoom-positioning the camera behind the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	//Follow camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	//speed of turning left/right
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	//speed of looking up/down
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bShiftKeyPressed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool bIsPushing;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector SetPushingDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float SetForwardPushVelocity;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool Dead;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//called for Right/Left inputs
	void MoveRight(float);
	//called for Froward/Backward inputs
	void MoveForward(float);

	void TurnAtRate(float);
	void LookUpAtRate(float);

	void jump();
	void stopJumping();


	FORCEINLINE class  USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class  UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	void ShiftKeyPressed();
	void ShiftKeyReleased();

	void Die();

};
