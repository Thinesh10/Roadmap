#pragma once

class PieceTable
{
	public:
		explicit PieceTable(const std::string& buff) noexcept : o_buff_(buff), a_buff("");
		void insertPiece(const std::size_t pos, const std::string& s);
		void deletePiece(const std::size_t pos, const std::size_t length);

	private:
		std::vector<Piece> pieces_;
		std::string o_buff_;
		std::string a_buff_;
}
