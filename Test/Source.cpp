#include<iostream>
#include<cmath>
#include<vector>
#define  _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{

    sf::RenderWindow window(sf::VideoMode(600, 400), L"Gta Балтика 7", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    int map[100][100];
    std::pair<int, int> player_cords;
    player_cords.first = 0;
    player_cords.second = 0;
    std::pair<int, int> bot_cords;
    bot_cords.first = 30;
    bot_cords.second = 0;
    map[bot_cords.first][bot_cords.second] = 2;

    Texture player ;
    player.loadFromFile("C:\\Users\\user\\Downloads\\image (3)-Photoroom.png");
    player.setSmooth(true);
   
    Sprite sprite(player);
    sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 128, 128 }));
    sprite.setPosition({ 300.0f, 200.0f });
    sprite.setOrigin(100,64);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                /*sprite.setPosition(sprite.getPosition().x + cos(sprite.getRotation()/360*2*M_PI), sprite.getPosition().y + sin(sprite.getRotation()/360*2*M_PI));
                */player_cords.first+= cos(sprite.getRotation() / 360 * 2 * M_PI)*2;
                player_cords.second += sin(sprite.getRotation() / 360 * 2 * M_PI) * 2;

                std::cout << player_cords.first<<" ";

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            /*sprite.setPosition(sprite.getPosition().x - cos(sprite.getRotation() / 360 * 2 * M_PI), sprite.getPosition().y - sin(sprite.getRotation() / 360 * 2 * M_PI));
        */
            player_cords.first -=  cos(sprite.getRotation() / 360 * 2 * M_PI)*2;
            player_cords.second -= sin(sprite.getRotation() / 360 * 2 * M_PI) * 2;

            std::cout << player_cords.first << " "<<sprite.getRotation()<<"\n";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sprite.rotate(2);
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sprite.rotate(-2 );
        }

        window.clear();
        if ((player_cords.first + 20 > bot_cords.first)&&(player_cords.first - 20 < bot_cords.first)&& (player_cords.second + 20 > bot_cords.second) && (player_cords.second - 20 < bot_cords.second)) {
            Sprite bot(player);
            bot.setTextureRect(sf::IntRect({ 0, 0 }, { 128, 128}));
            bot.setOrigin(100, 64);
            bot.setPosition({ sprite.getPosition().x+(bot_cords.first-player_cords.first)*20,  sprite.getPosition().y + (bot_cords.second - player_cords.second) * 20 });
            

            window.draw(bot);
        }
        window.draw(sprite);
        window.display();
    }
    return 0;
}