#pragma once

#include <cstddef>

enum class BuffType
{
	orig,
	add,
};

enum class InsertType
{
	mid,
	start,
	end,
};

class Piece
{
	public:
		constexpr Piece(const BuffType t, const std::size_t s, const std::size_t l) noexcept 
		: type_(t), start_(s), size_(l) {};

		[[nodiscard]] constexpr BuffType bufferType() const noexcept { return type_; };
		[[nodiscard]] constexpr std::size_t start() const noexcept { return start_; };
		[[nodiscard]] constexpr std::size_t size() const noexcept { return size_; };
		[[nodiscard]] constexpr std::size_t end() const noexcept { return start_ + size_ - 1; };

	private:
		BuffType type_;
		std::size_t start_, size_;
};