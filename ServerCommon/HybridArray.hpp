#pragma once


template<typename Type, int StaticSize>
class HybridArray
{
public:
	inline HybridArray( void );
	inline HybridArray( const HybridArray& rhs );
	template<int OtherSize>
	HybridArray( const HybridArray<Type, OtherSize>& rhs );
	
	inline ~HybridArray( void );
	

	inline void			operator=( const HybridArray& rhs ) noexcept;
	template<int OtherSize>
	void				operator=( const HybridArray<Type, OtherSize>& rhs ) noexcept;

	inline void			vailidate( void ) const noexcept;

	inline void			add( const Type& item ) noexcept;
	inline bool			addUnique( const Type& item ) noexcept;

	inline void			removeLast( void ) noexcept;

	inline Type&		operator[]( const int index ) noexcept;
	inline const Type&	operator[]( const int index ) const noexcept;
	
	inline Type&		getFirst( void ) noexcept;
	inline const Type&	getFirst( void ) const noexcept;
	inline Type&		getLast( void ) noexcept;
	inline const Type&	getLast( void ) const noexcept;

	inline void			removeAtIndex( const int index ) noexcept;
	inline void			removeCyclicAtIndex( const int index ) noexcept;
	inline bool			remove( const Type& item ) noexcept;
	inline void			removeAll( void ) noexcept;

	inline void			truncate( const int newSize ) noexcept;





private:
	int					_count;
	int					_maxSize;
	Type*				_data;
	Type				_staticData[StaticSize];
};