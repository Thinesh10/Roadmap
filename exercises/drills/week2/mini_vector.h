template<typename T>

class MiniVector
{
	public:
		constexpr MiniVector() noexcept : size_(0), capacity_(0), reallocations_(0), data_(nullptr);

		void push_back( const T& value )
		{
			if (size_ == capacity_)
			{
				grow();
			}

			data_[size_++] = value;
		}

		void pop_back()
		{
			if (size_ > 0)
			{
				--size_;
			}
		}

		T& operator[]( const std::size_t i ) { return data_[i]; };
		const T& operator[] ( const std::size_t i ) const { return data_[i]; };

		std::size_t size() const { return size_; };
		std::size_t capacity() const { return capacity_; };
		std::size_t reallocations() const { return reallocations_; };

	private:
		std::size_t size_, capacity_, reallocations_;
		std::unique_ptr<T[]> data_;	

		void grow () 
		{
			capacity_ = ( capacity_ == 0 ) ? 1 : ( 2 * capacity );
			std::unique_ptr<T[]> d = std::make_unique<T[]>( capacity_ );

			if (std::is_trivially_copyable_v(T))
			{
				std::memcpy(d.get(), data_.get(), size_ * sizeof(T));
			}
			else
			{
				std::ranges::move(data_.get(), data_.get() + size_, d.get());
			}

			data_ = std::move(d);

			++reallocations;
			std::cout << "Reallocations: " << reallocations_ << ", Capacity: " << capacity_ << std::endl;
		}
}

