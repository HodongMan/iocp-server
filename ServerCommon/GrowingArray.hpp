#pragma once


template <class Type>
class GrowingArray
{
public:
	GrowingArray( const int nrOfRecommendedItems, const int itemIncreaseSize, const bool safemodeFlag = true ) noexcept;
	GrowingArray( void ) noexcept;
	GrowingArray( const GrowingArray<Type>& array ) noexcept;

	void			reset( void ) noexcept;

	bool			initialize( const int nrOfRecommendedItems, const int itemIncreaseSize, const bool safemodeFlag = true ) noexcept;
	bool			reInitialize( const int nrOfRecommendedItems, const int itemIncreaseSize, const bool safemodeFlag = true ) noexcept;
	bool			isInitialized( void ) const noexcept;

	Type&			operator[] ( const int index ) const noexcept;
	
	inline int		find( const Type& item, const unsigned int lookFromIndex = 0 ) const noexcept;

	template <class Comparer, class Compared>
	inline int		find2( const Compared& item, const unsigned int lookFromIndex = 0 ) const noexcept;

	template <class Compared>
	inline int		find2Std( const Compared& item, const unsigned int lookFromIndex = 0 ) const noexcept;

	inline int		reverseFind( const Type& item, const unsigned int lookFromIndex = 0 ) const noexcept;

	template <class Comparer, class Compared>
	inline int		reverseFind2( const Compared& item, const unsigned int lookFromIndex = 0 ) const noexcept;

	inline bool		add( const Type& item ) noexcept;
	inline bool		add( const Type* someItems, const unsigned int numberOrItemsToAdd ) noexcept;
	inline bool		addN( const Type& item, const unsigned int numberOrItemsToAdd ) noexcept;
	inline void		addUnique( const Type& item ) noexcept;

	inline bool		removeCyclic( const Type& item ) noexcept;
	inline void		removeCyclicAtIndex( const int ItemIndex ) noexcept;
	inline void		removeNAtEnd( const int count ) noexcept;

	inline void		moveToIndex( const int itemIndex, const int netItemIndex ) noexcept;
	inline void		moveToEndCyclic( const int itemIndex ) noexcept;
	inline void		moveToEndConserveOrder( const int itemIndex ) noexcept;



protected:
	int				_usedNrOfItems;
	int				_maxNrOfItems;
	unsigned int	_itemIncreaseSize : 31;
	unsigned int	_safemodeFlag : 1;
	Type*			_itemList;


private:

};