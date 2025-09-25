#pragma once

#include "piece.h"
#include <vector>
#include <string>
#include <memory>

template <typename T, typename Comp>
std::size_t last_smaller_piece_index(const std::vector<T>& v, const T& val, Comp cmp)
{
	auto it = std::lower_bound(std::cbegin(v), std::cend(v), val, cmp);

	if (it == std::cbegin(v))
	{
		return -1;
	}
	
	return std::distance(std::cbegin(v), --it);
}

class PieceTable
{
	public:
		explicit PieceTable(std::string buff) noexcept;
		void insertPiece(const std::size_t pos, const std::string& s);
		void deletePiece(const std::size_t pos, const std::size_t length);
		std::pair<std::size_t, InsertType> getPieceIndex(const std::size_t);

	private:
		std::vector<std::unique_ptr<Piece>> pieces_;
		std::string o_buff_;
		std::string a_buff_;
};
