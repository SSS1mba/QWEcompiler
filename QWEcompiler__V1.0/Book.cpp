#include "Book.h"

Book::Book(size_t capacity_of_book_, const std::unordered_map<size_t, Spell>& spell_map)
	:spell_map_(spell_map),
	capacity_of_book_(capacity_of_book_),
	current_sphere_(0), /*изначально книга пустая*/
	spheres_(spheers_traits::allocate(spheres_alloc, capacity_of_book_))
{
	for (size_t i = 0; i < capacity_of_book_; ++i)
	{
		spheers_traits::construct(spheres_alloc, spheres_ + i, empty_slot);
	}
}

Book::~Book()
{
	for (size_t i = 0; i < capacity_of_book_; ++i)
	{
		spheers_traits::destroy(spheres_alloc, spheres_ + i);
	}
	spheers_traits::deallocate(spheres_alloc, spheres_, capacity_of_book_);
}

Book::Book(const Book& other)
	:spell_map_(other.spell_map_),
	capacity_of_book_(other.capacity_of_book_),
	current_sphere_(other.current_sphere_),
	spheres_(spheers_traits::allocate(spheres_alloc, capacity_of_book_))
{
	for (size_t i = 0; i < capacity_of_book_; ++i)
	{
		spheers_traits::construct(spheres_alloc, spheres_ + i, other.spheres_[i]);
	}
}

Book::Book(Book&& other) noexcept
	: spell_map_(std::move(other.spell_map_)),
	capacity_of_book_(other.capacity_of_book_),
	current_sphere_(other.current_sphere_),
	spheres_(other.spheres_)
{
	other.spheres_ = nullptr;
}



void Book::emplace_sphere(size_t sphere_weight)
{
	spheers_traits::destroy(spheres_alloc, spheres_ + current_sphere_);
	spheers_traits::construct(spheres_alloc, spheres_ + current_sphere_, sphere_weight);
	++current_sphere_;
	current_sphere_ = current_sphere_ % capacity_of_book_;
}

Spell Book::invoke() const
{
	if (is_empty()) throw compile_error("The book is not initialised!");

	Spell result;
	try { result = spell_map_.at(sum_of_spheres()); }
	catch (const std::out_of_range& ex) { throw compile_error("unknown spell in spell_table"); }

	return result;
}

bool Book::is_empty() const noexcept
{
	for (size_t i = 0; i < capacity_of_book_; ++i)
	{
		if (spheres_[i].GET_weight() == empty_slot) return true;
	}
	return false;
}

size_t Book::sum_of_spheres() const noexcept
{
	size_t sum = 0;
	for (size_t i = 0; i < capacity_of_book_; ++i) { sum += spheres_[i].GET_weight(); }
	return sum;
}