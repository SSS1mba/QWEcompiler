#pragma once
#include "DEFAUT_VALUES.h"

class Book
{
public:
	Book(size_t capacity_of_book_ = DEFAULT_CAPACITY_OF_BOOK,
		const std::unordered_map<size_t, Spell>& spell_map = DEFAULT_SPELL_MAP)
		:spell_map_(spell_map) ,
		capacity_of_book_(capacity_of_book_),
		current_sphere_(0), /*изначально книга пустая*/
		spheres_(spheers_traits::allocate(spheres_alloc, capacity_of_book_))
	{
		for (size_t i = 0; i < capacity_of_book_; ++i)
		{
			spheers_traits::construct(spheres_alloc, spheres_ + i, empty_slot);
		}
	}
	~Book()
	{
		for (size_t i = 0; i < capacity_of_book_; ++i)
		{
			spheers_traits::destroy(spheres_alloc, spheres_ + i);
		}
		spheers_traits::deallocate(spheres_alloc, spheres_, capacity_of_book_);
	}
	Book(const Book& other) :spell_map_(other.spell_map_),
		capacity_of_book_(other.capacity_of_book_),
		current_sphere_(other.current_sphere_),
		spheres_(spheers_traits::allocate(spheres_alloc, capacity_of_book_))
	{
		for (size_t i = 0; i < capacity_of_book_; ++i)
		{
			spheers_traits::construct(spheres_alloc, spheres_ + i, other.spheres_[i]);
		}
	}
	Book(Book&& other) noexcept : spell_map_(std::move(other.spell_map_)),
		capacity_of_book_(other.capacity_of_book_),
		current_sphere_(other.current_sphere_),
		spheres_(other.spheres_)
	{
		other.spheres_ = nullptr;
	}
	Book& operator= (const Book& other) = delete;
	Book& operator= (Book&& other) = delete;


	void emplace_sphere(size_t sphere_weight)
	{
		spheers_traits::destroy(spheres_alloc, spheres_ + current_sphere_);
		spheers_traits::construct(spheres_alloc, spheres_ + current_sphere_, sphere_weight);
		++current_sphere_;
		current_sphere_ = current_sphere_ % capacity_of_book_;
	}
	Spell invoke() const
	{
		if (is_empty()) throw compile_error("The book is not initialised!");
		
		Spell result;
		try { result = spell_map_.at(sum_of_spheres()); }
		catch (std::out_of_range ex) { throw compile_error("unknown spell in spell_table"); }

		return result;
	}


private:
	bool is_empty() const noexcept
	{
		for (size_t i = 0; i < capacity_of_book_; ++i)
		{
			if (spheres_[i].GET_weight() == empty_slot) return true;
		}
		return false;
	}
	size_t sum_of_spheres() const noexcept
	{
		size_t sum = 0;
		for (size_t i = 0; i < capacity_of_book_; ++i) { sum += spheres_[i].GET_weight(); }
		return sum;
	}
	///////////////
	std::unordered_map<size_t, Spell> spell_map_;
	const size_t capacity_of_book_;
	size_t current_sphere_;
	Sphere* spheres_;

};

static const Book DEFAULT_BOOK;