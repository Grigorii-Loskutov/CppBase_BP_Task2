// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "TimerManager.h"

// Sets default values
ACppBaseActor::ACppBaseActor() {
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Amplitude = 70.0f;

	Frequency = 1.0f;

	InitialLocation = { 0, 0, 0 };
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();

	//ShowInformation();
	//ShowActorInformation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor::ShowInformation() {
	//Пример из лекции
	
	UE_LOG(LogTemp, Warning, TEXT("ShowInformation print"));
	/*
	UE_LOG(LogTemp, Warning, TEXT("CppBase is failed"));
	UE_LOG(LogTemp, Error, TEXT("CppBase is crached!"));

	int EnemyNum = 20;
	float CurrentHealth = 57.54687;
	bool IsAlive = true;

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
	*/
}

void ACppBaseActor::ShowActorInformation() {
	UE_LOG(LogTemp, Display, TEXT("ObjName: %s"), *ActorName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

void ACppBaseActor::SinMovement()
{
	float	Time = GetGameTimeSinceCreation();
	FVector NewLocation = InitialLocation + FVector(0, 0, Amplitude * FMath::Sin(Frequency * Time));
	SetActorLocation(NewLocation);
}
