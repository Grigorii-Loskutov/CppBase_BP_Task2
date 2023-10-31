// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UstaticMeshComponent;
UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static,
	Test
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

	// Called every frame
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	virtual void		  Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	FString ActorName;
	UPROPERTY(EditAnywhere)
	int EnemyNum;
	UPROPERTY(EditAnywhere)
	int IsAlive;
	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	// Поля для синуса
	UPROPERTY(EditAnywhere)
	float Amplitude;

	UPROPERTY(EditAnywhere)
	float Frequency;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation;

	UFUNCTION(BlueprintCallable)
	void SinMovement();

private:
	void ShowActorInformation();
};
