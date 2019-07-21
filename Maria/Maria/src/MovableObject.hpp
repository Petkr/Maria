#pragma once
#include "GameObject.hpp"
#include "Geometry.hpp"

class MovableObject : public GameObject
{
	static constexpr int gravity = 1;

	Rectangle future;
	Vector velocity;

public:
	MovableObject(const Vector& position, const Vector& velocity = { 0, 0 })
		: GameObject(position)
		, velocity(velocity)
	{}
	
	Rectangle GetFuture()
	{
		return Rectangle(Position() + velocity, Size());
	}

	void Move()
	{
		if (!velocity.empty())
		{
			future = GetFuture();

			CollideWithBounds();
			CollideWithSolids();
			CollideWithNonSolids();
			CollideWithMovables();

			Position() = future;
		}

		if (velocity.y < 25 - gravity)
			velocity.y += gravity;
	}

	void CollideWithBounds()
	{
		if (future.Y >= game.level.Size.Height - Height())
			Die();
	}
};