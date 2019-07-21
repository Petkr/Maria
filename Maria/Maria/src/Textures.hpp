#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <string>

namespace detail
{
	template <typename T>
	constexpr size_t ac = 0;

	template <typename T>
	constexpr size_t ac<T[]> = 12;
	
	template <typename T, size_t N>
	constexpr size_t ac<T[N]> = N;
}

template <auto arr>
constexpr size_t ac = detail::ac<decltype(arr)>;

template <typename T, size_t N>
constexpr size_t array_count(T(&)[N])
{
	return N;
}

class Textures
{
	using t = const char*;

	static constexpr t names[] = { "mario", "wall", "monster", "coin", "flag" };
	static constexpr int count = array_count(names);

	static sf::Texture textures[];
public:
	enum name
	{
		mario, wall, monster, coin, flag
	};

	static void Init();

	static sf::Texture* Get(Textures::name n);
};