#include <SFML/Network.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <cstdlib>

//g++ server.cpp -o server -lpthread -lsfml-system -lsfml-network


int main()
{
    sf::TcpListener listner;
    sf::TcpSocket socket;
    //std::string messageBuffer;
    std::size_t bytesRecieved;

    for(;;)
    {
        if(listner.listen(53000) != sf::Socket::Done)
        {
            std::cout << "Port problems" << '\n';
        }    
            
        if(listner.accept(socket) != sf::Socket::Done)
        {
        std::cout << "Can't accept connection" << '\n'; 
        }

        char messageBuffer[100] = {};
        bytesRecieved = 0;

        sf::Socket::Status status = socket.receive(messageBuffer, 100, bytesRecieved);

        if (status == sf::Socket::Done)
        {
            std::cout << "Got " << bytesRecieved << " bytes." << '\n';
            std::cout << "Message: " << messageBuffer << '\n';
        }

    }


}