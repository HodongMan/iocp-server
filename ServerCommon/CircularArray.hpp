#pragma once


template< class Type>
class CircularArray
{
public:
	CircularArray( unsigned int numNode )
	{
		_maxNumNode		= numNode;
		_nodes			= new Type[_maxNumNode];
		_nextFreeNode	= 0;
		_firstNode		= 0;
		_currentNumNode = 0;
	}

	~CircularArray()
	{
		removeAll();

		if ( nullptr != _nodes )
		{
			delete[] _nodes;
			_nodes		= nullptr;
		}
	}

	void add( const Type& type ) noexcept
	{
		
	}


private:
	Type*			_nodes;
	unsigned int	_maxNumNode;
	unsigned int	_currentNumNode;
	unsigned int	_nextFreeNode;
	unsigned int	_firstNode;
};

template <class Type, unsigned int MAX_NODES>
class CircularArrayT
{
public:
	typedef Type value_t;
	const static unsigned int MAX = MAX_NODES;

	CircularArrayT()
		: _currentNumNode( 0 )
		, _nextFreeNode( 0 )
		, _firstNode( 0 )
	{
	
	}

	~CirculaArrayT()
	{
		removeAll();
	}

	bool removeFirst( void ) noexcept
	{
		if ( 0 == _currentNumNode )
		{
			return false;
		}

		_currentNumNode -= 1;
		_firstNode		+= 1;

		if ( _firstNode == MAX_NODES )
		{
			_firstNode	= 0;
		}

		return true;
	}

	void add( const Type& value ) noexcept
	{
		if ( _currentNumNode < MAX_NODES )
		{
			_currentNumNode += 1;
		}
		else
		{
			if ( _nextFreeNode == _firstNode)
			{
				_firstNode += 1;
				if ( MAX_NODES == _firstNode )
				{
					_firstNode += 1;
				}
			}
		}

		_nodes[_nextFreeNode] = value;
		_nextFreeNode += 1;
		if ( MAX_NODES == _nextFreeNode )
		{
			_nextFreeNode = 0;
		}
	}

	Type& getFirst( void ) const noexcept
	{
		return _nodes[0];
	}

	Type& getLast( void ) const noexcept
	{
		return _nodes[_currentNumNode - 1];
	}

	bool removeLast( void ) noexcept
	{
		if ( 0 == _currentNumNode )
		{
			return false;
		}

		_currentNumNode -= 1;

		if ( 0 == _nextFreeNode )
		{
			_nextFreeNode = MAX_NODES - 1;
		}
		else
		{
			_nextFreeNode -= 1;
		}

		return true;
	}

	void removeAll( void ) noexcept
	{
		_nextFreeNode	= 0;
		_firstNode		= 0;
		_currentNumNode = 0;
	}


	int count( void ) const noexcept
	{
		return _currentNumNode;
	}

	Type& operator[]( const unsigned int index ) noexcept
	{
		return _nodes[( _firstNode + index ) % MAX_NODES];
	}

	const Type& operator[]( const unsigned int index ) const noexcept
	{
		return _nodes[( _firstNode + index ) % MAX_NODES];
	}

private:
	Type			_nodes[MAX_NODES];
	unsigned int	_currentNumNode;
	unsigned int	_nextFreeNode;
	unsigned int	_firstNode;
};