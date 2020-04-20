#include <SFML/Network.hpp>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

int main()
{
    for(;;)
    {    
        sf::TcpSocket socket;

        if (socket.connect("127.0.0.1", 53000) != sf::Socket::Done)
        {
            std::cout << "Can't connect" << '\n';
        }

        char mes[] = {};

        std::cin >> mes;

        sf::Socket::Status status = socket.send(mes, strlen(mes));

        if (status == sf::Socket::Done)
        {
            std::cout << "Sent" << '\n';
        } 
        else
        {
            std::cout << "Ploho" << '\n';
        }

        std::cout << mes << '\n';

        socket.disconnect();
    }

   return 0;   
}