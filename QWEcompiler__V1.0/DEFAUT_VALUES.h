#pragma once
#include"data_types.h"
#include <unordered_map>


//////////////////Lexer
static std::allocator< std::vector<Token>> token_alloc;
using token_traits = std::allocator_traits< std::allocator< std::vector<Token>>>;

//constexpr char DEFAULT_QUAS_KEY = 'q';     ->data_types.h
//constexpr char DEFAULT_WEX_KEY = 'w';
//constexpr char DEFAULT_EXORT_KEY = 'e';
//constexpr char DEFAULT_INVOKE_KEY = 'r';

//////////////////Parser
static std::allocator< std::vector<Instuction>> instruction_alloc;
using instuction_traits = std::allocator_traits< std::allocator< std::vector<Instuction>>>;

static std::allocator<Sphere> spheres_alloc;
using spheers_traits = std::allocator_traits<std::allocator<Sphere>>;

constexpr size_t DEFAULT_CAPACITY_OF_BOOK = 3;

constexpr size_t DEFAULT_WEIGHT_OF_QUAS = 1;
constexpr size_t DEFAULT_WEIGHT_OF_WEX = 3;
constexpr size_t DEFAULT_WEIGHT_OF_EXORT = 27;

static std::unordered_map<size_t, Spell> DEFAULT_SPELL_MAP = {
	{ DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_QUAS ,	ColdSnap() },
	{ DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_WEX ,		GhostWalk()},
	{ DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_EXORT ,	IceWall()},
	{ DEFAULT_WEIGHT_OF_WEX  + DEFAULT_WEIGHT_OF_WEX  + DEFAULT_WEIGHT_OF_WEX ,		EMP()},
	{ DEFAULT_WEIGHT_OF_WEX + DEFAULT_WEIGHT_OF_WEX + DEFAULT_WEIGHT_OF_QUAS ,		Tornado()},
	{ DEFAULT_WEIGHT_OF_WEX + DEFAULT_WEIGHT_OF_WEX + DEFAULT_WEIGHT_OF_EXORT ,		Alacrity()},
	{ DEFAULT_WEIGHT_OF_QUAS + DEFAULT_WEIGHT_OF_WEX + DEFAULT_WEIGHT_OF_EXORT ,	DeafeningBlast()},
	{ DEFAULT_WEIGHT_OF_EXORT + DEFAULT_WEIGHT_OF_EXORT + DEFAULT_WEIGHT_OF_EXORT,	SunStrike()},
	{ DEFAULT_WEIGHT_OF_EXORT + DEFAULT_WEIGHT_OF_EXORT + DEFAULT_WEIGHT_OF_QUAS,	ForgeSpirit()},
	{ DEFAULT_WEIGHT_OF_EXORT + DEFAULT_WEIGHT_OF_EXORT + DEFAULT_WEIGHT_OF_WEX,	ChaosMeteor()},
};

//static const Book DEFAULT_BOOK;  -> Book.h
