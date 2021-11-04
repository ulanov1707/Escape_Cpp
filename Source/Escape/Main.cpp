// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include"GameFramework/SpringArmComponent.h"
#include"Camera/CameraComponent.h"
#include"Engine/World.h"
#include"Components/CapsuleComponent.h"
#include"GameFramework/CharacterMovementComponent.h"
#include"Kismet/KismetSystemLibrary.h"
#include"Components/SkeletalMeshComponent.h"
#include"Animation/AnimInstance.h"


// Sets default values
AMain::AMain()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creates Camera Boom(pulls towards the player if there is a collosion)
	//SpringArm-создает своего рода спираль между персонажем с определенным расо€нием(TargetArmLength())
	//и потом можно к одному концу спирали можно прив€зать камеру а к другому самого персонажа
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f;//Camera  keeps distatnce on this value
	CameraBoom->bUsePawnControlRotation = true;//Rotate arm based on controller(if mouse rotates Spring arm rotates as well)

	//sets a capsule  collision size for capsule of character in default pannel SetCapsuleSize(capsuleRadius, capsuleHalfHeight)
	GetCapsuleComponent()->SetCapsuleSize(37.f, 100.f);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	//Attached Camera to Spring Arm
	//Socket-если например персонаж подбирает камень с земли то камень должен быть прикриплен(attached) к руке персонажа
	//и дл€ этого камн€ создаетс€ разъем(socket)
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	//we set it to "false" ,cuz we alredy set rotataion to SpringArm .Camera is attahecd(child) of SpringArm ,so we dont need it .

	//sets speed to view a character
	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;

	//when you rotate the mouse , charachter doesn rotates along with the mouse(camera)
	//let that just affect the camera
	bUseControllerRotationYaw = false;

	//rotates the character when you press keys in neccessary direction (ex.if you press "D" it rotates character to the left)
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f/*Yaw*/, 0.0f);//rotates at this Rate(speed)
	GetCharacterMovement()->JumpZVelocity = 650.f;//speed of Jump
	GetCharacterMovement()->AirControl = 5.f;//allows to contol character(move left/right,forward/backward) when he is in the air


	RunningSpeed = 650.f;


	Dead = false;



}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();



}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//just checks if the variable is valid
	check(PlayerInputComponent);

	//BindAction(NameOfInput,EventName,ClassToBeEffected,FunctionToCallIfEventIsActivated)
	//BindAction used when in the editor u use "Action Mapping" for the input
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);



	//recall lecture 37
	PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain::MoveRight);

	//turns a charachter when you turn around a mosue
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("TurnRate", this, &AMain::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMain::LookUpAtRate);
}

void AMain::MoveForward(float Value)
{
	//Character class has  a variable Controller 
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		//gives an info to which direction mouse is looking(Controller=mouse)
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.f);

		//дает ’ координану наешго объекта , нужна дл€ того чтобы когда мы нажмем "вперед"
		//персонаж понимал в какую сторону двигатьс€
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		//moves object.непосредственно двиает персонажа по карте по заданому выше направлению 
		AddMovementInput(Direction, Value);
	}

}
void AMain::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		//gives an info to which direction mouse is looking(Controller=mouse)
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.f);

		//дает Y координану наешго объекта 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		//moves object
		AddMovementInput(Direction, Value);
	}

}

void AMain::TurnAtRate(float Rate)
{
	//views an object in BaseTurnRate frames per second
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());

}
void AMain::LookUpAtRate(float Rate)
{
	//views an object in BaseLookUp frames per second
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}


void AMain::Die() 
{
	Dead = true;
}



