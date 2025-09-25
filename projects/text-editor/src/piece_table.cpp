#include "piece_table.h"
#include <algorithm>

template <typename T, typename Comp>
std::size_t last_smaller_piece_index(const std::vector<T>& v, const std::size_t val, Comp cmp)
{
	auto it = std::lower_bound(std::cbegin(v), std::cend(v), val, cmp);

	if (it == std::cbegin(v))
	{
		return -1;
	}
	
    if (it == std::cend(v))
    {
        return v.size() - 1;
    }

	return std::distance(std::cbegin(v), --it);
}

explicit PieceTable::PieceTable(std::string s)
{
    o_buff_ = std::move(s);
    a_buff_ = "";

    pieces_.emplace_back(std::make_unique<Piece>(BuffType::orig, 0, s.size()));
}

void PieceTable::insertPiece(const std::size_t pos, const std::string& s)
{
    std::unique_ptr<Piece> newPiece = std::make_unique<Piece>(BuffType::add, pos, s.size());
    a_buff_ += s;

    auto [piece_index, type] = getPieceIndex(pos);

    // add piece into piece table:
    //     start or o buff
    //     middle of o buff
    //     end of o buff
};

std::pair<std::size_t, InsertType> PieceTable::getPieceIndex(const std::size_t pos)
{
    if (pos == 0)
    {
        return {0, InsertType::start};
    }
    else if (pos > pieces_[pieces_.size() - 1]->end())
    {
        return {pieces_.size() - 1, InsertType::end};
    }

    auto cmp = [](const std::unique_ptr<Piece>& l, const std::size_t val)
    {
        return l->start() <= val;
    };

    auto index = last_smaller_piece_index(pieces_, pos, cmp);
    if (pos == pieces_[index]->start())
    {
        return {index, InsertType::start};
    }
    
    return {index, InsertType::mid};
};