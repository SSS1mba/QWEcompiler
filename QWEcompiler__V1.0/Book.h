#pragma once
#include "DEFAUT_VALUES.h"

class Book
{
public:
	Book(size_t capacity_of_book_ = DEFAULT_CAPACITY_OF_BOOK,
		const std::unordered_map<size_t, Spell>& spell_map = DEFAULT_SPELL_MAP);
	~Book();
	Book(const Book& other);
	Book(Book&& other) noexcept;
	Book& operator= (const Book& other) = delete;
	Book& operator= (Book&& other) = delete;


	void emplace_sphere(size_t sphere_weight);
	Spell invoke() const;


private:
	bool is_empty() const noexcept;
	size_t sum_of_spheres() const noexcept;
	///////////////
	std::unordered_map<size_t, Spell> spell_map_;
	const size_t capacity_of_book_;
	size_t current_sphere_;
	Sphere* spheres_;

};

static const Book DEFAULT_BOOK;