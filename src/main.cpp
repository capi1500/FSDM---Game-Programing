#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
	sf::RenderWindow window(sf::VideoMode(500, 500), "Programowanie gier");
	window.setFramerateLimit(60);
	
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color(255, 127, 63));
	rect.setOutlineColor(sf::Color::Blue);
	rect.setOutlineThickness(10);
	rect.setPosition(100, 100);
	
	sf::Texture textureKeyA, textureKeyA2, textureKeyW, textureKeyW2, textureKeyD, textureKeyD2, textureKeyS, textureKeyS2;
	textureKeyA.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/A_Key_Dark.png");
	textureKeyA2.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/A_Key_Light.png");
	textureKeyS.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/S_Key_Dark.png");
	textureKeyS2.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/S_Key_Light.png");
	textureKeyD.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/D_Key_Dark.png");
	textureKeyD2.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/D_Key_Light.png");
	textureKeyW.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Dark/W_Key_Dark.png");
	textureKeyW2.loadFromFile("../assets/textures/keyboard_and_controller/Keyboard & Mouse/Light/W_Key_Light.png");
	
	sf::Sprite keyA, keyD, keyW, keyS;
	keyA.setTexture(textureKeyA);
	keyS.setTexture(textureKeyS);
	keyD.setTexture(textureKeyD);
	keyW.setTexture(textureKeyW);
	
	keyW.setPosition(100, 0);
	keyA.setPosition(0, 100);
	keyS.setPosition(100, 100);
	keyD.setPosition(200, 100);
	
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::W){
					keyW.setTexture(textureKeyW2);
				}
				if(event.key.code == sf::Keyboard::A){
					keyA.setTexture(textureKeyA2);
				}
				if(event.key.code == sf::Keyboard::S){
					keyS.setTexture(textureKeyS2);
				}
				if(event.key.code == sf::Keyboard::D){
					keyD.setTexture(textureKeyD2);
				}
			}
			if(event.type == sf::Event::KeyReleased){
				if(event.key.code == sf::Keyboard::W){
					keyW.setTexture(textureKeyW);
				}
				if(event.key.code == sf::Keyboard::A){
					keyA.setTexture(textureKeyA);
				}
				if(event.key.code == sf::Keyboard::S){
					keyS.setTexture(textureKeyS);
				}
				if(event.key.code == sf::Keyboard::D){
					keyD.setTexture(textureKeyD);
				}
			}
			if(event.type == sf::Event::MouseButtonPressed){
				if(event.mouseButton.button == sf::Mouse::Left){
					std::cout << "LPM " << event.mouseButton.x << " " << event.mouseButton.y << "\n";
				}
				if(event.mouseButton.button == sf::Mouse::Right){
					std::cout << "RPM " << event.mouseButton.x << " " << event.mouseButton.y << "\n";
				}
			}
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			rect.move(0, -1);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			rect.move(-1, 0);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			rect.move(0, 1);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			rect.move(1, 0);
		
		window.clear();
		
		window.draw(rect);
		
		window.draw(keyA);
		window.draw(keyW);
		window.draw(keyS);
		window.draw(keyD);
		
		window.display();
	}
	
	return 0;
}