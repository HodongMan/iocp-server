#pragma once

#include "TypeSocket.h"
#include "GrowingArray.hpp"


class TCPSocket
{
	static TCPSocket*	createSocket( bool shouldBlock = false ) noexcept;
	static TCPSocket*	createSocket( const SOCKET& connectedWinsock, const SOCKADDR_IN& remoteAddress, bool shouldBlock = false ) noexcept;
	static void			updateSocket( void ) noexcept;

	~TCPSocket( void );

	bool				bindAndListen( const unsigned short portNumber ) noexcept;

	bool				bind( const unsigned int address, const unsigned short aPortNumber, const bool aReuseAddress ) noexcept;
	bool				listen( void ) noexcept;

	TCPSocket*			acceptConnection( void );

	bool				connect( const SOCKADDR_IN& address ) noexcept;
	bool				connect( const unsigned int address, const unsigned short portNumber ) noexcept;

	void				disconnect( const bool theDisconnectIsGraceful = false ) noexcept;

	bool				sendBuffer( const char* buffer, int bufferLength ) noexcept;
	bool				recvBuffer( _Out_ char* buffer, int bufferLength, _Out_ int& numBytesRead ) noexcept;

	bool				getLocalAddress( _Out_ SOCKADDR_IN& address ) const noexcept;
	bool				getPeerAddress( _Out_ SOCKADDR_IN& address ) const noexcept;

	SOCKADDR_IN			getRemoteAddress( void ) const noexcept;

	const char*			getLocalHostName( void ) const noexcept;

	bool				isConnected( void ) const noexcept;
	bool				isBlocking( void ) const noexcept;

	bool				setNonBlocking( void ) noexcept;

	bool				disableNagle( const bool flag ) noexcept;

	static void			echoWSAError( const char* functionCall ) noexcept;

	void				setSocketInteralRecvBufferSize( const unsigned int bufferSize ) noexcept;
	void				setSocketInteralSendBufferSize( const unsigned int bufferSize ) noexcept;

	void				print( void ) const noexcept;

	unsigned int		getLastActivityTimestamp( void ) const noexcept;
	SOCKET				getSocket( void ) const noexcept;

private:
	TCPSocket( void );

	bool				initialize( const bool shouldBlock = false ) noexcept;
	bool				initialize( const SOCKET& connectedSocket, const SOCKADDR_IN& remoteAddress, const bool shouldBlock = false ) noexcept;
	bool				storeBufferInternal( const char* buffer, const int bufferLength ) noexcept;
	SendResponse		sendInternal( const char* buffer, const int bufferLength ) noexcept;

	static const unsigned int				getTimeDiff( const unsigned int startTime, const unsigned int endTime ) noexcept;


private:
	SOCKET				_winSocket;
	SOCKADDR_IN			_remoteAddress;

	std::string			_localHostName;
	bool				_isBlocking;
	bool				_isConnecting;
	char*				_internalBuffer;
	int					_internalReadPointer;
	int					_internalWritePointer;
	unsigned int		_lastActivity;

	CircularArray<int, MAX_INTERNAL_PACKETS>* _internalPackets;

	static GrowingArray<TCPSocket*>		_activeSockets;
	static unsigned int					_lastActiveSocketCheck;
};