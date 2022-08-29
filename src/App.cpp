#include "App.hpp"

#include "SpriteSheet.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>


void App::run() {
	_services.window().create(sf::VideoMode{ 587, 707 }, "Moving dude");
	_services.window().setVerticalSyncEnabled(true);

	sf::Clock clock;

	SpriteSheet<10> spriteSheet;
	if (spriteSheet.load(_services.assets(), generate_spritesheet_paths<spriteSheet.size()>("knight/Walk")).failed()) {
		return;
	}
	sf::Sprite player{ *spriteSheet[0] };

	_controller.add(
		[](const sf::Event& e) { return e.type == sf::Event::KeyPressed; },
		[]() { std::cout << "Hello\n"; }
	);

	size_t counter{ 0 };
	clock.restart();
	while (_services.window().isOpen()) {
		sf::Event e;
		sf::Time dt = clock.restart();
		while (_services.window().pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				_services.window().close();
			}
			_controller.handle_event(e);
		}

		player.setTexture(*spriteSheet[counter++ / 5 % 10]);

		_services.window().clear();
		_services.window().draw(player);
		_services.window().display();
	}
}
