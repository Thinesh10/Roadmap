template<typename T>
class UniquePtr
{
	public: 
		// Constructors
		constexpr UniquePtr() noexcept : ptr_(nullptr) {};
		explicit UniquePtr(T* p) noexcept : ptr_(p) {};	

		// Destructor
		~UniquePtr() { delete ptr_; };

		// Copy constructor
		UniquePtr(const UniquePtr& p) = delete;
		// Coppy assignment operator
		UniquePtr& operator=(const UniquePtr& p) = delete;

		// Move constructor
		UniquePtr(UniquePtr&& p) noexcept : ptr_(p.ptr_) { p.ptr = nullptr; };
		// Move assignment operator
		UniquePtr& operator=(UniquePtr&& p) noexcept 
		{
			if (this != &p)
			{
				delete ptr_;
				ptr_ = p.ptr_;
				p.ptr_ = nullptr;
			}
		
			return *this;
		}

		// Dereference operator
		T& operator*() const { return *ptr_; };
		// Arrow operator
		T* operator->() const { return ptr_; };

		// Observe
		T* get() const noexcept ( return ptr_; };
		// Release
		T* release() noexcept
		{
			T* tmp = ptr_;
			ptr_ = nullptr;
			return tmp;
		}
		// Reset
		void reset(T* p = nullptr) noexcept
		{
			if (ptr_ != p)
			{
				delete ptr_;
				ptr_ = p;
			}
		}

		explicit operator bool() const noexcept { return ptr_ != nullptr; };	

	private:
		T* ptr_;
}
