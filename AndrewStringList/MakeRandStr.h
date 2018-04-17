#pragma once
#include <random>

std::mt19937 gen{ std::random_device()() };
std::uniform_int_distribution<size_t> uid1(32, 127);
std::uniform_int_distribution<size_t> uid2( 5, 35);

char* MakeString(char *rand_str)
{
	const size_t SIZE = uid2(gen);
	for (size_t i = 0; i < SIZE; ++i)
	{
		rand_str[i] = (char)uid1(gen);
	}
	rand_str[SIZE] = '\0';
	return rand_str;
}